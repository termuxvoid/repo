<div align="center">
  <a href="https://termuxvoid.github.io/">
    <img alt="TermuxVoid" height="170" src="img/termuxvoid_logo.png">
    <h1>TermuxVoid APT Repository</h1>
  </a>
  <p><b>Unofficial APT repository: 250+ security and utility tools for Termux</b></p>

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

**TermuxVoid** is an unofficial APT repository for Termux, packaging **250+ security, Android, AI, and utility tools**. Packages are defined in this repository; some compile on device, while others download upstream releases. Read the package script before installing.

Requires Termux (F-Droid or GitHub), Android 7+, and free storage for large tools.

## Contents

- [Install](#install)
- [Packages](#packages)
  - [Featured Tools](#featured-tools)
  - [AI Tools](#ai-tools)
- [Security](#security)
- [FAQ](#faq)
- [Support](#support)

## Install

```bash
curl -sL https://github.com/termuxvoid/repo/raw/main/install.sh | bash
```

> [!WARNING]
> Piping a remote script to `bash` runs it immediately. Download and read `install.sh` first if you want to inspect it.

Then install packages:

```bash
# Refresh package lists
pkg update

# Install any tool
pkg install <tool-name>

# Example
pkg install metasploit-framework
```

The installer also sets up **tvpkg** (`tvp`), the TermuxVoid package manager.

To remove the repository later:

```bash
curl -sL https://github.com/termuxvoid/repo/raw/main/uninstall.sh | bash
```

This removes the repository source and key, not packages you already installed.

Using **Pacman**? The same 250+ packages are available from [pacman-repo](https://github.com/termuxvoid/pacman-repo):

```bash
curl -sL https://github.com/termuxvoid/pacman-repo/raw/main/install-repo.sh | bash
```

## Packages

<div align="center">
  <a href="assets/PACKAGES.md">
    <img src="https://img.shields.io/badge/Browse_All_250%2B_Tools-2ea44f?style=for-the-badge" alt="Browse All Tools">
  </a>
</div>

### Featured Tools

| Tool | Category | Description |
| :--- | :--- | :--- |
| **Metasploit** | `Security & Exploitation` | Penetration testing framework. |
| **Burp Suite** | `Web Security` | Web application security testing platform. |
| **Ghidra** | `Security & Exploitation` | Software reverse-engineering suite. |
| **Hydra** | `Networking` | Parallelized login cracker. |
| **SQLMap** | `Web Security` | SQL injection detection and exploitation. |
| **John the Ripper** | `Password Tools` | Password cracker. |

### AI Tools

AI tools may require accounts or API keys and may send data to third-party providers. AI output can be wrong; review generated code before running it.

| Tool | Description |
| :--- | :--- |
| **9router** | Gateway between your tools and AI providers |
| **antigravity-cli** | AI coding assistant (glibc wrapper for Termux) |
| **claude-code** | Claude Code - AI coding assistant by Anthropic |
| **codex-cli** | Codex CLI - AI coding agent (npm version) |
| **copilot-cli** | GitHub Copilot CLI |
| **freebuff** | AI coding agent for the terminal |
| **hermes-agent** | AI coding assistant and workflow automation tool |
| **jcode** | Terminal coding agent harness |
| **kimi-code** | AI coding assistant for the terminal |
| **laudacode** | Lightweight AI coding agent for your terminal |
| **mimocode** | AI coding agent (glibc wrapper for Termux) |
| **mmx-cli** | CLI for MiniMax AI |
| **openclaude** | Open-source coding-agent CLI for cloud and local LLMs |
| **opencode** | AI-powered coding assistant |
| **termux-ai** | Interactive AI assistant for Termux |
| **utim-cli** | AI-powered unified terminal intelligence manager |

## Security

This is an unofficial, independently maintained project. Package scripts run with your permissions: read the script before installing. Some packages compile on device; others download prebuilt upstream binaries. Stable fixed-version downloads use pinned SHA-256 hashes, but git clones, mutable URLs, `pip`/`gem` installs, and upstream installers are not hash-pinned. A checksum reduces download-tampering risk, not the risk of a malicious package.

APT repository metadata is GPG-signed (`InRelease`); `install.sh` installs the TermuxVoid key.

Some packages are dual-use security tools. Use them only on devices, accounts, and networks you own or are explicitly authorized to test. See [SECURITY.md](SECURITY.md).

## FAQ

- **Is it safe?** No package is guaranteed safe. Read the script and upstream source; test unfamiliar tools in isolation.
- **Is it legal?** Only for authorized security research and testing. Unauthorized access or interception is illegal.
- **How do I update or search?** Run `pkg update`, then `pkg search <tool-name>`.
- **Package missing?** Run `pkg update` and check the [full catalog](assets/PACKAGES.md) for the exact name.
- **How do I uninstall the repository?** Run `curl -sL https://github.com/termuxvoid/repo/raw/main/uninstall.sh | bash`. This removes the repository source and key, not installed packages.
- **How often updated?** As upstream releases and issues are handled; no fixed schedule.

## Support

[Telegram](https://telegram.me/nullxvoid) · [GitHub](https://github.com/TermuxVoid/repo) · [YouTube](https://youtube.com/@alienkrishnorg)

Read [CONTRIBUTING.md](CONTRIBUTING.md) before opening a PR. Report bugs via [Issues](https://github.com/TermuxVoid/repo/issues).

<div align="center">
  <sub>Unofficial project by <a href="https://github.com/Anon4You">Alienkrishn</a>. Review package scripts before installing.</sub>
</div>
