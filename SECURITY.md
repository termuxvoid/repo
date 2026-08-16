# Security Policy

## Transparency, Not Trust

This repo is open source so you can **read the code before you run `pkg install`**. Every package's full contents are here — nothing hidden in binary blobs.

**What to check before installing:**

1. `DEBIAN/postinst` — runs on install. Read it.
2. `DEBIAN/postrm` and `DEBIAN/prerm` (where present) — run during removal.
3. Files under `data/data/com.termux/files/usr/` — the actual scripts/binaries.

Don't understand the postinst? Copy it, ask an AI "what does this do and is it safe?" Don't install blindly.

## Package Behavior and Configuration

- No package modifies `$PATH`, `$HOME`, `$PREFIX`, or any Termux env var.
- Ordinary tool packages do not alter your existing Termux configuration.
- Packages whose stated purpose is shell styling, themes, desktop environments, or similar customization may create or change relevant configuration files. Inspect their lifecycle scripts before installation and removal, and keep backups of personal configuration.
- Where appropriate, commands are exposed through **symlinks** instead of environment mutations.
- Uninstall scripts are intended to remove files created by the package. Packages cannot restore user changes made after installation, so review cleanup behavior before installing a customization package.

## Verify a Package Before Installing

Do not install a package solely because it is available in this repository. Before installing, review its `DEBIAN/control`, `preinst`, `postinst`, and `postrm` files (where present).

Check the following:

1. **Upstream source:** Confirm the project URL and license are the ones you expect.
2. **Version and integrity:** Prefer a pinned release, tag, or commit. When an upstream checksum or signature is available, verify it.
3. **Network activity:** Identify every URL, Git repository, or upstream package-manager command used during installation.
4. **Local changes:** Identify files created, commands linked, configuration files changed, and what removal does.
5. **Authorization:** Security tools may be dual-use. Use them only on systems and data you own or are explicitly authorized to test.

## Report a Vulnerability

Open a [GitHub Issue](https://github.com/TermuxVoid/repo/issues) or contact [@nullxvoid](https://telegram.me/nullxvoid) on Telegram.

## Legal

These tools are for **educational and authorized security testing only**. Do not use your knowledge for illegal things. I won't take responsibility for your shit — you mess up, you face the consequences yourself. Stay ethical.
