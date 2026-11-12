/*
 * sysfix - run a static Linux/aarch64 binary under Android's app sandbox.
 *
 * Android's seccomp filter kills (SIGSYS) any app process that calls a
 * syscall it does not allow. Some static Linux binaries use such syscalls, and
 * also assume a standard Linux /etc. sysfix is a small ptrace shim that makes
 * three translations so these binaries can run in Termux:
 *
 *   1. openat2 (blocked)  -> emulated with openat (allowed)
 *   2. openat("/")        -> opened with O_PATH (plain open of "/" is EACCES)
 *   3. /etc is a symlink on Android (/etc -> /system/etc): the "etc" probe is
 *      done without NOFOLLOW so strict "no symlinks" checks pass
 *   plus path redirects: /etc/resolv.conf and the CA bundle are pointed at the
 *   copies Termux keeps under $PREFIX.
 *
 * It grants no new access: openat2 is translated to openat, which the app may
 * already call, and O_PATH does not allow reading the directory.
 *
 * Usage: sysfix PROGRAM [ARGS...]
 * Debug: SYSFIX_LOG=file   log failed syscalls, emulations and redirects
 *        SYSFIX_ALL=1      with SYSFIX_LOG, also log every call that has a path
 *
 * aarch64 only. Overhead: the tracee stops on every syscall.
 */
#define _GNU_SOURCE
#include <elf.h>
#include <errno.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <unistd.h>

#ifndef SYS_SECCOMP
#define SYS_SECCOMP 1
#endif
#ifndef PTRACE_GET_SYSCALL_INFO
#define PTRACE_GET_SYSCALL_INFO 0x420e
#endif

#define NR_OPENAT 56
#define NR_NEWFSTATAT 79
#define NR_STATX 291
#define NR_OPENAT2 437

#define F_O_PATH 0x200000ULL
#define F_O_NOFOLLOW 0x8000ULL
#define F_AT_SYMLINK_NOFOLLOW 0x100ULL

#define SCRATCH_WORDS 32 /* 256 bytes of tracee stack used for path rewrites */
#define MAX_TASKS 256

struct regs {
  unsigned long long x[31], sp, pc, pstate;
};

struct sci { /* struct ptrace_syscall_info */
  uint8_t op;
  uint8_t pad[3];
  uint32_t arch;
  uint64_t ip, sp;
  union {
    struct { uint64_t nr, args[6]; } en;
    struct { int64_t rval; uint8_t err; } ex;
    struct { uint64_t nr, args[6]; uint32_t ret; } sc;
  } u;
};

struct task {
  pid_t pid;
  int emul;                  /* current call is an emulated openat2 */
  int restore;               /* scratch stack area must be restored at exit */
  int in_syscall;            /* fallback entry/exit tracking without syscall-info */
  long long nr, a0;
  char path[200];
  unsigned long long saved_x1, scratch;
  long saved[SCRATCH_WORDS];
};

static struct task tasks[MAX_TASKS];
static FILE *lg;
static int log_all;
static int fallback_logged;
static const char *prefix;

static const struct { const char *from, *rel; } redirects[] = {
    {"/etc/resolv.conf", "etc/resolv.conf"},
    {"/etc/ssl/certs/ca-certificates.crt", "etc/tls/cert.pem"},
};

static struct task *task_for(pid_t p) {
  for (int i = 0; i < MAX_TASKS; i++)
    if (tasks[i].pid == p) return &tasks[i];
  for (int i = 0; i < MAX_TASKS; i++)
    if (!tasks[i].pid) {
      memset(&tasks[i], 0, sizeof tasks[i]);
      tasks[i].pid = p;
      return &tasks[i];
    }
  return &tasks[0];
}

static void getr(pid_t p, struct regs *r) {
  struct iovec iov = {r, sizeof *r};
  ptrace(PTRACE_GETREGSET, p, (void *)NT_PRSTATUS, &iov);
}

static void setr(pid_t p, struct regs *r) {
  struct iovec iov = {r, sizeof *r};
  ptrace(PTRACE_SETREGSET, p, (void *)NT_PRSTATUS, &iov);
}

static void readstr(pid_t p, unsigned long long a, char *buf, int n) {
  int i = 0;
  buf[0] = 0;
  while (i + 8 < n) {
    errno = 0;
    long w = ptrace(PTRACE_PEEKDATA, p, (void *)(a + i), 0);
    if (errno) { buf[i] = 0; return; }
    memcpy(buf + i, &w, 8);
    for (int k = 0; k < 8; k++)
      if (!buf[i + k]) return;
    i += 8;
  }
  buf[i] = 0;
}

static void pokestr(pid_t p, unsigned long long a, const char *s) {
  size_t n = strlen(s) + 1;
  for (size_t i = 0; i < n; i += 8) {
    long w = 0;
    memcpy(&w, s + i, n - i < 8 ? n - i : 8);
    ptrace(PTRACE_POKEDATA, p, (void *)(a + i), (void *)w);
  }
}

/* Point the path argument (x1) of the current syscall at $PREFIX/<rel>. */
static void redirect(pid_t p, struct task *t, const char *rel) {
  char np[SCRATCH_WORDS * 8];
  snprintf(np, sizeof np, "%s/%s", prefix, rel);
  struct regs r;
  getr(p, &r);
  unsigned long long dst = (r.sp - 512) & ~15ULL;
  for (int i = 0; i < SCRATCH_WORDS; i++) {
    errno = 0;
    t->saved[i] = ptrace(PTRACE_PEEKDATA, p, (void *)(dst + 8 * i), 0);
    if (errno) return;
  }
  pokestr(p, dst, np);
  t->saved_x1 = r.x[1];
  t->scratch = dst;
  t->restore = 1;
  r.x[1] = dst;
  setr(p, &r);
  if (lg) { fprintf(lg, "redirect %s -> %s\n", t->path, np); fflush(lg); }
}

static void on_entry(pid_t p, struct task *t, const struct sci *in) {
  t->nr = in->u.en.nr;
  t->a0 = in->u.en.args[0];
  t->path[0] = 0;
  t->restore = 0;
  if (t->nr != NR_OPENAT && t->nr != NR_NEWFSTATAT && t->nr != NR_STATX &&
      t->nr != NR_OPENAT2)
    return;
  readstr(p, in->u.en.args[1], t->path, sizeof t->path);

  if (t->nr == NR_OPENAT && !strcmp(t->path, "/")) {
    struct regs r;
    getr(p, &r);
    r.x[2] |= F_O_PATH;
    setr(p, &r);
  } else if (t->nr == NR_STATX && !strcmp(t->path, "etc")) {
    struct regs r;
    getr(p, &r);
    r.x[2] &= ~F_AT_SYMLINK_NOFOLLOW;
    setr(p, &r);
  } else if (t->nr == NR_OPENAT || t->nr == NR_NEWFSTATAT) {
    for (size_t i = 0; i < sizeof redirects / sizeof *redirects; i++)
      if (!strcmp(t->path, redirects[i].from)) {
        redirect(p, t, redirects[i].rel);
        break;
      }
  }
}

static void on_exit_stop(pid_t p, struct task *t, const struct sci *in) {
  long long rv = in->u.ex.rval;
  if (lg && (t->emul || (rv < 0 && rv > -4096) || (log_all && t->path[0]))) {
    fprintf(lg, "nr=%lld a0=%lld path=\"%s\" ret=%lld%s\n", t->nr, t->a0, t->path, rv,
            t->emul ? " (emulated openat2)" : "");
    fflush(lg);
  }
  if (t->restore) {
    for (int i = 0; i < SCRATCH_WORDS; i++)
      ptrace(PTRACE_POKEDATA, p, (void *)(t->scratch + 8 * i), (void *)t->saved[i]);
    struct regs r;
    getr(p, &r);
    r.x[1] = t->saved_x1;
    setr(p, &r);
  }
  t->emul = 0;
  t->restore = 0;
}

/* Older kernels lack PTRACE_GET_SYSCALL_INFO; use the regset entry/exit stops. */
static void fallback_syscall(pid_t p, struct task *t) {
  if (!fallback_logged) {
    if (lg) {
      fprintf(lg, "PTRACE_GET_SYSCALL_INFO unavailable; using GETREGS fallback\n");
      fflush(lg);
    }
    fallback_logged = 1;
  }
  struct regs r;
  struct sci in;
  memset(&in, 0, sizeof in);
  getr(p, &r);
  if (!t->in_syscall) {
    in.op = 1;
    in.u.en.nr = r.x[8];
    for (int i = 0; i < 6; i++) in.u.en.args[i] = r.x[i];
    t->in_syscall = 1;
    on_entry(p, t, &in);
  } else {
    in.op = 2;
    in.u.ex.rval = (int64_t)r.x[0];
    t->in_syscall = 0;
    on_exit_stop(p, t, &in);
  }
}

/* SIGSYS from seccomp: emulate openat2 with openat, fail anything else. */
static void on_sigsys(pid_t p, struct task *t, int syscall_nr) {
  struct regs r;
  getr(p, &r);
  if (syscall_nr == NR_OPENAT2) {
    errno = 0;
    long flags = ptrace(PTRACE_PEEKDATA, p, (void *)r.x[2], 0);      /* how->flags */
    long mode = ptrace(PTRACE_PEEKDATA, p, (void *)(r.x[2] + 8), 0); /* how->mode  */
    if (errno == 0) {
      char pp[16];
      readstr(p, r.x[1], pp, sizeof pp);
      if (!strcmp(pp, "etc")) flags &= ~(long)F_O_NOFOLLOW;
      r.x[8] = NR_OPENAT;
      r.x[2] = flags;
      r.x[3] = mode;
      r.pc -= 4; /* re-execute the svc as openat */
      t->emul = 1;
    } else {
      r.x[0] = (unsigned long long)(-(long long)EFAULT);
    }
  } else {
    if (lg) { fprintf(lg, "BLOCKED syscall %d\n", syscall_nr); fflush(lg); }
    r.x[0] = (unsigned long long)(-(long long)ENOSYS);
  }
  setr(p, &r);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "usage: sysfix PROGRAM [ARGS...]\n");
    return 2;
  }
  prefix = getenv("PREFIX");
  if (!prefix || !*prefix) prefix = "/data/data/com.termux/files/usr";
  if (getenv("SYSFIX_LOG")) lg = fopen(getenv("SYSFIX_LOG"), "w");
  log_all = getenv("SYSFIX_ALL") != NULL;

  pid_t child = fork();
  if (child < 0) { perror("fork"); return 1; }
  if (child == 0) {
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    execvp(argv[1], argv + 1);
    perror(argv[1]);
    _exit(127);
  }

  int st, code = 0;
  waitpid(child, &st, 0);
  if (!WIFSTOPPED(st)) return WIFEXITED(st) ? WEXITSTATUS(st) : 1;
  ptrace(PTRACE_SETOPTIONS, child, 0,
         PTRACE_O_TRACECLONE | PTRACE_O_TRACEFORK | PTRACE_O_TRACEVFORK |
             PTRACE_O_TRACEEXEC | PTRACE_O_TRACESYSGOOD | PTRACE_O_EXITKILL);
  ptrace(PTRACE_SYSCALL, child, 0, 0);

  for (;;) {
    pid_t p = waitpid(-1, &st, __WALL);
    if (p < 0) {
      if (errno == EINTR) continue;
      break;
    }
    if (WIFEXITED(st) || WIFSIGNALED(st)) {
      if (p == child) code = WIFEXITED(st) ? WEXITSTATUS(st) : 128 + WTERMSIG(st);
      task_for(p)->pid = 0;
      continue;
    }
    int sig = 0;
    if (WIFSTOPPED(st) && !(st >> 16)) { /* event stops carry st >> 16; ignore */
      int s = WSTOPSIG(st);
      struct task *t = task_for(p);
      if (s == (SIGTRAP | 0x80)) {
        struct sci in;
        memset(&in, 0, sizeof in);
        if (ptrace(PTRACE_GET_SYSCALL_INFO, p, (void *)sizeof in, &in) > 0) {
          if (in.op == 1) on_entry(p, t, &in);
          else if (in.op == 2) on_exit_stop(p, t, &in);
        } else {
          fallback_syscall(p, t);
        }
      } else if (s == SIGSYS) {
        siginfo_t si;
        if (ptrace(PTRACE_GETSIGINFO, p, 0, &si) == 0 && si.si_code == SYS_SECCOMP)
          on_sigsys(p, t, si.si_syscall);
        else
          sig = s;
      } else if (s != SIGSTOP && s != SIGTRAP) {
        sig = s; /* pass real signals through */
      }
    }
    ptrace(PTRACE_SYSCALL, p, 0, sig);
  }
  return code;
}
