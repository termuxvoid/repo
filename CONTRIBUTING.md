# Contributing to TermuxVoid

Thank you for your interest in adding a package. Before you start, make sure you understand the two core topics below. PRs may be closed without review if a submission shows these are missing.

## Prerequisites

1. **Debian package layout.** Each package in `packages/<name>/` is an unpacked Debian package directory. It must contain a `DEBIAN/` directory with a `control` file and lifecycle scripts (`preinst`, `postinst`, `postrm`). Understand what a `control` file contains and when each script runs. See the [Debian Policy](https://www.debian.org/doc/debian-policy/) if needed.

2. **Termux paths and environment.** These are used throughout the scripts:
   - `$PREFIX` → `/data/data/com.termux/files/usr` — root of the installed environment
   - `$HOME` → `/data/data/com.termux/files/home` — user home
   - `$TMPDIR` → where temporary files go; use it for scratch files
   - `$PREFIX/bin` → where user commands live
   - `$PREFIX/share/<pkg>` → where a package's data lives
   - Scripts use the Termux shebang: `#!/data/data/com.termux/files/usr/bin/bash`

## Package structure

```
packages/<name>/
└── DEBIAN/
    ├── control     # metadata
    ├── preinst     # pre-install checks (optional)
    ├── postinst    # build/install/link (required)
    └── postrm      # uninstall cleanup (required)
```

### control

Required fields:

`Package`, `Version`, `Architecture` (use `all`), `Maintainer`, `Depends`, `Section`, `Priority`, `Homepage`, `Description`. List every runtime dependency under `Depends`; apt installs them for you.

### preinst

Runs before the package is unpacked. Use it for cheap guard checks (e.g. architecture). Keep it minimal or omit it.

### postinst

Runs after installation. This is where the real work happens: download, build, install, link. **Rules to follow:**

- **Keep it simple.** One job: install the tool and expose it on `$PATH`.
- **Never** modify `$PATH`, `$HOME`, `$PREFIX`, or any other environment variable.
- **Never** touch the user's existing Termux config or dotfiles.
- Expose commands via **symlinks into `$PREFIX/bin`**. Prefer a `ln -s` over a wrapper script.
- Its final job is to verify the command exists; `exit 1` on any failure.

Example (Go tool):

```bash
#!/data/data/com.termux/files/usr/bin/bash
set -e

go install -trimpath github.com/example/tool@v1.2.3

if [ ! -f "$PREFIX/bin/tool" ] && [ -f "$HOME/go/bin/tool" ]; then
    ln -sf "$HOME/go/bin/tool" "$PREFIX/bin/tool"
fi
```

### postrm

Runs on uninstall. Remove whatever `postinst` created — nothing more, nothing in the user's own files.

```bash
#!/data/data/com.termux/files/usr/bin/bash

rm -f "$PREFIX/bin/tool"
rm -rf "$PREFIX/share/tool"
```

## Test before submitting

Install, run, and remove the package on a Termux device (real Termux or emulator). At minimum:

```bash
pkg update
dpkg-deb -b packages/<name>
pkg install ./<name>_<version>_all.deb

# 1. Command is on PATH and runs
tool --version

# 2. Nothing env-related was modified
echo "$PATH"      # unchanged after install

# 3. Uninstall leaves no trace
pkg remove <name>
test ! -e "$PREFIX/bin/tool"
```

## PR checklist

- [ ] Correct Debian layout (`packages/<name>/DEBIAN/control` plus scripts).
- [ ] All runtime dependencies declared under `Depends`.
- [ ] `postinst` keeps to one job, uses symlinks, and does **not** change any environment variable or path.
- [ ] `postrm` removes only what the package created.
- [ ] Installed, ran, and uninstalled successfully during testing.
- [ ] Added to `assets/PACKAGES.md` under the correct category.

If unsure about any step, ask before opening the PR rather than guessing.