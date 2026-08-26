<div align="center">
  <a href="https://termuxvoid.github.io/">
    <img alt="TermuxVoid" height="180" src="img/termuxvoid_logo.png">
    <h1>TermuxVoid APT Repository</h1>
  </a>
  <p><b>Unofficial APT Repository: 220+ Ethical Hacking & Pentesting Packages</b></p>

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

## 📖 Table of Contents

- [Project Overview](#-project-overview)
- [Prerequisites](#-prerequisites)
- [Quick Installation](#-quick-installation)
- [Pacman Users](#-pacman-users)
- [Featured Tools](#-featured-tools)
- [Legal & Disclaimer](#-legal--disclaimer)
- [Frequently Asked Questions](#-frequently-asked-questions)
- [Support & Community](#-support--community)
- [Contribution & Support](#-contribution--support)

---

## 📋 Prerequisites

Before using TermuxVoid, ensure your environment meets these requirements:

- **Termux** installed from [F-Droid](https://f-droid.org/en/packages/com.termux/) (recommended) or GitHub
- **Android 7+** with ~2GB free storage for larger tools
- **Working internet connection** for package downloads
- **No root required** for most tools (some may need root for certain features)

---

## 🔍 Project Overview

**TermuxVoid** is an **unofficial custom APT repository** that bridges the gap between mobile convenience and professional security auditing. We host **220+ advanced security tools** that are not available in the official Termux repositories. Package installation happens on your device: depending on the tool, the package may build from source, install an upstream dependency, or download an upstream release.

Whether you are a professional penetration tester or an ethical hacking enthusiast, TermuxVoid turns your Android device into a portable powerhouse.

> [!NOTE]
> This repository contains tools that are often excluded from official sources due to complexity, licensing, or security sensitivity. Read a package's installation script and its upstream source before installing it.<br>

## Security & Transparency

TermuxVoid is an unofficial, community-maintained repository. Package definitions and lifecycle scripts are published here so you can inspect what runs on installation and removal. A package may build from source on your device, install through an upstream package manager, or download an upstream release; the package script is the source of truth.

Each package lives in `packages/<name>/` and normally ships a standard Debian layout under `DEBIAN/`:

- `control` — metadata (name, version, dependencies, description)
- `preinst` — pre-install checks (e.g. architecture validation)
- `postinst` — performs installation (such as building, downloading, or linking the tool)
- `postrm` — removes files created by the package when possible

### What packages do—and do not—change

- No package modifies `$PATH`, `$HOME`, `$PREFIX`, or any other Termux environment variable.
- Most tool packages do not alter existing Termux configuration and expose commands through **symlinks** or package-manager-installed commands instead of environment mutation.
- Packages whose stated purpose is shell styling, themes, desktop environments, or similar customization may create or change relevant configuration files. Read their scripts carefully before installation and removal.
- Uninstall scripts are intended to remove files created by the package. Preserve your own configuration backups, especially before installing customization packages.

### Before you install

Security tools are powerful and many have dual-use capabilities. Use them only on systems and data you own or are explicitly authorized to test. Do not install a package solely because it is listed here.

1. Read `packages/<name>/DEBIAN/control`, `preinst`, `postinst`, and `postrm` (where present).
2. Check every download URL, Git repository, package-manager command, and configuration change in those scripts.
3. Review the upstream tool and its license, then install it in a test environment first if it is unfamiliar.
4. Keep backups of personal configuration before installing shell, theme, or desktop packages.

Don't trust — verify. See [CONTRIBUTING.md](CONTRIBUTING.md) for the package layout and [SECURITY.md](SECURITY.md) for the security policy.

### Package-source expectations

When a package obtains software from upstream, its scripts should make the source auditable. Contributors should provide the upstream project URL, use a pinned release, tag, or commit where practical, and verify an upstream checksum or signature when one is available. Review every network download, upstream package-manager command, file/configuration change, exposed command, and uninstall action before installing.

## 🚀 Quick Installation

Getting started is seamless. Run the following one-liner in your Termux terminal to add the repository automatically:

```bash
# Add repository
curl -sL https://github.com/termuxvoid/repo/raw/main/install.sh | bash
```

> [!WARNING]
> Piping a remote script directly to `bash` executes it immediately. For maximum transparency, download and inspect `install.sh` first, then run it locally.

Once the repository is added, you can install any tool using `pkg install`:

```bash
# Install any tool
pkg install <tool-name>

# Example
pkg install metasploit-framework
```

> [!TIP]
> After installation, run `pkg update` to refresh your local package database. You can search for tools using `pkg search <tool-name>`.

> [!NOTE]
> Removing the TermuxVoid repository later does not remove packages you already installed. Use the package manager to remove individual packages; see the [uninstall instructions](#how-do-i-uninstall-the-termuxvoid-repository) to remove only the repository source and key.

## 🐧 Pacman Users

Running a **pacman-based Termux** (switched pacman bootstrap or `termux-penv`)? The very same tools are also shipped as pacman packages through our dedicated pacman repository — signed database, `arch=('any')` builds, `pacman -S <tool>` workflow.

**Pacman repository:** [github.com/termuxvoid/pacman-repo](https://github.com/termuxvoid/pacman-repo)

```bash
curl -sL https://github.com/termuxvoid/pacman-repo/raw/main/install-repo.sh | bash
```

If you are on standard apt/dpkg Termux, stay right here — this repository is for you.

## ✨ Featured Tools

We provide a curated selection of industry-standard tools. Here are some highlights:

<div align="center">

| Tool | Category | Description |
| :--- | :--- | :--- |
| **Metasploit Framework** | `Exploitation` | The world's most used penetration testing framework. |
| **Burp Suite** | `Web Security` | Leading toolkit for web application security testing. |
| **Ghidra** | `Reverse Eng.` | NSA's high-end software reverse engineering suite. |
| **THC Hydra** | `Password Cracking` | Fast network logon cracker supporting many protocols. |
| **SQLMap** | `Web Security` | Automatic SQL injection and database takeover tool. |

</div>

<details>
<summary><b>📊 View Mermaid Architecture</b></summary>

```mermaid
graph TD
    A[TermuxVoid Repo] -->|Provides| B[Exploitation]
    A -->|Provides| C[Reverse Engineering]
    A -->|Provides| D[Network Scanning]
    A -->|Provides| E[Password Attacks]

    B --> B1[Metasploit]
    B --> B2[SQLMap]

    C --> C1[Ghidra]
    C --> C2[Radare2]

    D --> D1[Nmap]
    D --> D2[Netcat]

    E --> E1[Hydra]
    E --> E2[John the Ripper]
```
</details>

<div align="center">
  <a href="assets/PACKAGES.md">
    <img src="https://img.shields.io/badge/📦-Browse_All_220%2B_Packages-2ea44f?style=for-the-badge" alt="Browse All Packages">
  </a>
</div>

## 🧠 AI Agents

| Tool | Description |
| :--- | :--- |
| **opencode** | AI-powered coding assistant |
| **claude-code** | AI-powered coding assistant by Anthropic |
| **antigravity-cli** | AI coding assistant (glibc wrapper) |
| **copilot-cli** | GitHub Copilot CLI — AI-powered assistance in your terminal |
| **codex-cli** | Codex CLI by OpenAI — lightweight AI-powered coding agent in your terminal |
| **mimocode** | Autonomous AI engineer — creates, modifies, tests, deploys code |
| **openclaude** | Open-source coding-agent CLI for cloud & local LLMs |
| **hermes-agent** | AI-powered coding assistant and workflow automation tool |
| **kimi-code** | AI-powered coding assistant for the terminal by Moonshot AI |
| **mmx-cli** | CLI tool for MiniMax AI – chat, completion, and image generation from the terminal |

## Legal & Disclaimer

These tools are provided for **educational and authorized security research only**. You are responsible for ensuring your use complies with all applicable laws and regulations. Unauthorized access to systems you do not own or lack explicit permission to test is illegal. The maintainers assume no responsibility for any misuse.

## ❓ Frequently Asked Questions

<details>
<summary><b>Are these tools safe to use on a personal device?</b></summary>
<br>
Yes, all packages are built from source directly on your device during installation. This means no pre-compiled binaries are shipped — each tool is compiled and installed for your specific Termux environment. However, these are powerful security tools; ensure you understand what a tool does before executing it to avoid unintended system modifications.
</details>

<details>
<summary><b>Are these tools legal to use?</b></summary>
<br>
All tools are for <strong>legal security research and ethical hacking purposes only</strong>. Always obtain proper authorization before testing systems you do not own.
</details>

<details>
<summary><b>Why aren't these in the official repo?</b></summary>
<br>
Many of these tools (like Metasploit or Ghidra) have heavy dependencies, large sizes, or licensing complexities that make them difficult to maintain in the official core repositories. We handle the heavy lifting so you don't have to.
</details>

<details>
<summary><b>How often are tools updated?</b></summary>
<br>
- Security patches within 24 hours
- Version updates every Sunday
- Emergency fixes as needed
</details>

<details>
<summary><b>How do I request a new package?</b></summary>
<br>
We are constantly expanding. You can request new tools via:

1. Opening a **[GitHub Issue](https://github.com/TermuxVoid/repo/issues)**
2. Contacting us on Telegram: **[Telegram @nullxvoid](https://telegram.me/nullxvoid)**
3. Sending an email to: **[termuxvoid@gmail.com](mailto:termuxvoid@gmail.com)**
</details>

<details>
<summary><b>How do I report a broken package?</b></summary>
<br>
Open an issue on **[GitHub](https://github.com/TermuxVoid/repo/issues)** with the tool name and error output. We aim to fix reported issues within 24 hours.
</details>

<details>
<summary><b>How do I uninstall the TermuxVoid repository?</b></summary>
<br>
To remove the repository from your Termux environment:

```bash
curl -sL https://github.com/termuxvoid/repo/raw/main/uninstall.sh | bash
```

This removes the repository source and its GPG key, refreshes APT, and does not remove packages you have already installed.
</details>

<details>
<summary><b>I get a "package not found" error — what should I do?</b></summary>
<br>
Ensure you have run `pkg update` after adding the repository. If the issue persists, try:

```bash
apt update
pkg search <tool-name>
```

If the tool still doesn't appear, it may have a different package name — check the **[full package list](assets/PACKAGES.md)** for the exact name.
</details>

## 🌐 Support & Community

Join our growing community of security researchers and mobile hackers.

<div align="center">
  <a href="https://telegram.me/nullxvoid">
    <img src="https://img.shields.io/badge/Telegram-Join_Group-2CA5E0?style=for-the-badge&logo=telegram" alt="Telegram">
  </a>
  <a href="https://youtube.com/@alienkrishnorg">
    <img src="https://img.shields.io/badge/YouTube-Tutorials-FF0000?style=for-the-badge&logo=youtube" alt="YouTube">
  </a>
  <a href="https://github.com/TermuxVoid/repo">
    <img src="https://img.shields.io/badge/GitHub-Source_Code-181717?style=for-the-badge&logo=github" alt="GitHub">
  </a>
</div>

---

## 🛠️ Contribution & Support

Support the project to help us keep the packages updated and add more tools:

- ⭐ **Star** this repository to show your support.
- 🐛 **Report Bugs** responsibly via Issues.
- 📢 **Share** with the security community.

[View Complete Package List »](assets/PACKAGES.md)

<div align="center">
  <sub>Built with ❤️ for security researchers by <a href="https://github.com/Anon4You">Alienkrishn</a> | Built on-device for best compatibility</sub>
</div>
