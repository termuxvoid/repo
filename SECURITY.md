# Security Policy

## Scope

This policy covers the TermuxVoid APT repository: package definitions, lifecycle scripts, and the installer. It does not cover upstream projects. Report vulnerabilities in an upstream tool to that project's maintainers.

## Transparency, Not Trust

This repository is open source so you can **read the packaging before you run `pkg install`**. Package definitions and lifecycle scripts are published here. Some packages download prebuilt upstream binaries at install time, so the installed files may not be present in this repository. Read the scripts and the upstream source before installing.

**What to inspect:**

1. `DEBIAN/control` — metadata, dependencies, and description.
2. `DEBIAN/preinst`, `postinst`, and `postrm` — lifecycle scripts that run on your device (where present).
3. `data/` (where present) and every URL, Git repository, `pip`/`npm`/`gem` command, or archive extracted by the scripts.

If you do not understand a script, do not install it. Ask the maintainers or a trusted reviewer rather than relying on a guess.

## Package Behavior and Configuration

- Package scripts do not permanently modify `$PATH`, `$HOME`, `$PREFIX`, or other Termux environment variables.
- Ordinary tool packages do not alter existing Termux configuration.
- Packages whose stated purpose is shell styling, themes, desktop environments, or similar customization may create or change relevant configuration files. Inspect their lifecycle scripts before installation and removal, and keep backups of personal configuration.
- Many packages expose commands through symlinks or wrapper scripts in `$PREFIX/bin` rather than environment mutations.
- Removal scripts are intended to remove files created by the package. They cannot restore user changes made after installation, so review cleanup behavior before installing a customization package.

## Install-Time Downloads and Integrity

Some packages compile from source on your device; others download prebuilt upstream binaries. Fixed-version downloads are checked with pinned SHA-256 hashes where upstream provides a stable artifact. Git clones, mutable URLs, `pip`/`gem` installs, and upstream installers are not hash-pinned. Where a SHA-256 check exists, a mismatch aborts installation.

A checksum protects against corrupted or swapped downloads. It does not protect against a compromised upstream account, a malicious upstream release, or a compromised repository signing key. Some packages bundle third-party loaders or patched binaries (for example, Burp Suite Professional); these may violate software licenses and carry additional malware risk. A checksum is not a security audit.

## Signing

APT repository metadata is distributed with a GPG signature (`InRelease`), and `install.sh` installs the TermuxVoid key under `$PREFIX/etc/apt/trusted.gpg.d/`. APT verifies the signed metadata and the package checksums it contains. This protects repository metadata and package integrity in transit; it does not audit what a package's install scripts do on your device.

## Verify a Package Before Installing

Do not install a package solely because it is available in this repository. Before installing, review its package definition and lifecycle scripts.

Check the following:

1. **Upstream source:** Confirm the project URL and license are the ones you expect.
2. **Version and integrity:** Prefer a pinned release, tag, or commit. When an upstream checksum or signature is available, verify it.
3. **Network activity:** Identify every URL, Git repository, package-manager command, and download used during installation.
4. **Local changes:** Identify files created, commands linked, configuration files changed, and what removal does.
5. **Authorization:** Security tools may be dual-use. Use them only on systems and data you own or are explicitly authorized to test.

## Report a Security Issue

For sensitive reports, contact [@nullxvoid](https://telegram.me/nullxvoid) on Telegram instead of opening a public issue. For non-sensitive packaging problems, open a [GitHub Issue](https://github.com/TermuxVoid/repo/issues). Do not include exploit details for an unpatched issue in a public report.

There is no guaranteed response time. Security-relevant reports are prioritized when maintainers are available.

## Legal

These tools are provided for **educational, research, and authorized security testing only**. You are responsible for complying with applicable laws, platform terms, and authorization requirements. Unauthorized access, interception, disruption, or data exfiltration is illegal. The maintainers accept no liability for misuse, damage, or data loss.
