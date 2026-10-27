<div align="center">
  <a href="https://termuxvoid.github.io/">
    <img alt="TermuxVoid" height="160" src="img/termuxvoid_logo.png">
    <h1>TermuxVoid APT Repository</h1>
  </a>
  <p><b>Unofficial APT repository: 250+ tools for Termux</b></p>

  <div>
    <a href="https://github.com/TermuxVoid/repo/stargazers">
      <img src="https://img.shields.io/github/stars/TermuxVoid/repo?style=for-the-badge&logo=github&color=ffd700&labelColor=0d1117" alt="GitHub Stars">
    </a>
    <a href="https://github.com/TermuxVoid/repo/blob/main/LICENSE">
      <img src="https://img.shields.io/badge/License-BSD_3--Clause-blue?style=for-the-badge&logo=opensourceinitiative" alt="License">
    </a>
    <a href="https://github.com/TermuxVoid/repo/issues">
      <img src="https://img.shields.io/github/issues/TermuxVoid/repo?style=for-the-badge&logo=github&color=orange&labelColor=0d1117" alt="GitHub Issues">
    </a>
  </div>
</div>

## Install

```bash
curl -sL https://github.com/termuxvoid/repo/raw/main/install.sh | bash
```

> [!WARNING]
> Piping a remote script to `bash` runs it immediately. Download and read `install.sh` first if you want to inspect it.

Then install packages:

```bash
pkg update
pkg install <tool-name>
pkg install metasploit-framework
```

The installer also sets up **tvpkg** (`tvp`), the TermuxVoid package manager.

To remove the repository later:

```bash
curl -sL https://github.com/termuxvoid/repo/raw/main/uninstall.sh | bash
```

This does not remove packages you already installed.

On **Pacman**? The same packages are in [pacman-repo](https://github.com/termuxvoid/pacman-repo):

```bash
curl -sL https://github.com/termuxvoid/pacman-repo/raw/main/install-repo.sh | bash
```

## Packages

Browse the full list: [assets/PACKAGES.md](assets/PACKAGES.md).

Popular packages include **Metasploit**, **Burp Suite**, **Ghidra**, **Hydra**, **SQLMap**, and **John the Ripper**. The catalog also lists 16 AI tools.

## Security

This is an unofficial, independently maintained project. Package scripts run with your permissions: read the script before installing. Some packages compile on device; others download prebuilt upstream binaries. Stable fixed-version downloads use pinned SHA-256 hashes, but git clones, mutable URLs, `pip`/`gem` installs, and upstream installers are not hash-pinned. A checksum reduces download-tampering risk, not the risk of a malicious package.

APT repository metadata is GPG-signed (`InRelease`); `install.sh` installs the TermuxVoid key.

Some packages are dual-use security tools. Use them only on devices, accounts, and networks you own or are explicitly authorized to test. See [SECURITY.md](SECURITY.md).

## FAQ

- **Is it safe?** No package is guaranteed safe. Read the script and upstream source; test unfamiliar tools in isolation.
- **Is it legal?** Only for authorized security research and testing. Unauthorized access or interception is illegal.
- **How do I update or search?** Run `pkg update`, then `pkg search <tool-name>`.
- **Package missing?** Run `pkg update` and check the [full catalog](assets/PACKAGES.md) for the exact name.
- **How often updated?** As upstream releases and issues are handled; no fixed schedule.

## Support

[Telegram](https://telegram.me/nullxvoid) · [GitHub](https://github.com/TermuxVoid/repo) · [YouTube](https://youtube.com/@alienkrishnorg)

Read [CONTRIBUTING.md](CONTRIBUTING.md) before opening a PR. Report bugs via [Issues](https://github.com/TermuxVoid/repo/issues).

<div align="center">
  <sub>Unofficial project by <a href="https://github.com/Anon4You">Alienkrishn</a>. Review package scripts before installing.</sub>
</div>
