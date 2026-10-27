# TermuxVoid APT Package Catalog

## Overview

The complete catalog of packages in the TermuxVoid APT repository, grouped by the category recorded in each package's metadata. Each entry links to its documentation page.

> [!WARNING]
> This repository includes dual-use security tools. Use them only on devices, accounts, and networks you own or are explicitly authorized to test. Review each package's install script and upstream source before use.

> [!NOTE]
> Some installs download upstream binaries. Stable fixed-version downloads use pinned SHA-256 hashes; git clones, mutable URLs, pip/gem, and upstream installers are not pinned. The same tools are available as pacman packages: [github.com/termuxvoid/pacman-repo](https://github.com/termuxvoid/pacman-repo) (`curl -sL https://github.com/termuxvoid/pacman-repo/raw/main/install-repo.sh | bash`).

## Tool List

### AI Tools

> AI tools may require accounts, API keys, or paid plans and send prompts/data to third-party providers. AI output can be wrong; review code before running it.

| Tool | Description |
|------|-------------|
| [9router](https://termuxvoid.github.io/tool.html?name=9router) | Gateway between your tools and AI providers |
| [antigravity-cli](https://termuxvoid.github.io/tool.html?name=antigravity-cli) | AI‑powered coding assistant (glibc wrapper for Termux) |
| [claude-code](https://termuxvoid.github.io/tool.html?name=claude-code) | AI‑powered coding assistant by Anthropic for agentic coding tasks |
| [codex-cli](https://termuxvoid.github.io/tool.html?name=codex-cli) | Codex CLI – lightweight AI‑powered coding agent that runs in your terminal |
| [copilot-cli](https://termuxvoid.github.io/tool.html?name=copilot-cli) | GitHub Copilot CLI – AI‑powered assistance in your terminal |
| [freebuff](https://termuxvoid.github.io/tool.html?name=freebuff) | AI coding agent for the terminal |
| [hermes-agent](https://termuxvoid.github.io/tool.html?name=hermes-agent) | AI-powered coding assistant and workflow automation tool |
| [jcode](https://termuxvoid.github.io/tool.html?name=jcode) | Terminal coding agent harness with a fast local TUI, persistent memory, and MCP support |
| [kimi-code](https://termuxvoid.github.io/tool.html?name=kimi-code) | AI‑powered coding assistant for the terminal, powered by Moonshot AI |
| [laudacode](https://termuxvoid.github.io/tool.html?name=laudacode) | Lightweight AI coding agent for your terminal |
| [mimocode](https://termuxvoid.github.io/tool.html?name=mimocode) | AI coding agent (glibc wrapper for Termux) |
| [mmx-cli](https://termuxvoid.github.io/tool.html?name=mmx-cli) | CLI tool for MiniMax AI – chat, completion, and image generation from the terminal |
| [openclaude](https://termuxvoid.github.io/tool.html?name=openclaude) | Open‑source coding‑agent CLI for cloud and local LLMs |
| [opencode](https://termuxvoid.github.io/tool.html?name=opencode) | AI‑powered coding assistant (glibc version) |
| [termux-ai](https://termuxvoid.github.io/tool.html?name=termux-ai) | Interactive AI assistant for Termux |
| [utim-cli](https://termuxvoid.github.io/tool.html?name=utim-cli) | UTIM CLI – AI‑powered unified terminal intelligence manager |

### Android

> APK modification, backdoor, and device-control tools. Use only on devices you own; some require ADB or root.

| Tool | Description |
|------|-------------|
| [android-sdk](https://termuxvoid.github.io/tool.html?name=android-sdk) | Android development toolkit (ADB, Fastboot, and related tools) |
| [antisplit](https://termuxvoid.github.io/tool.html?name=antisplit) | APK Split Package Combiner and Modifier |
| [apkeditor](https://termuxvoid.github.io/tool.html?name=apkeditor) | Lightweight APK modification tool |
| [apkgen-cli](https://termuxvoid.github.io/tool.html?name=apkgen-cli) | CLI tool to quickly generate Android APKs from a template |
| [apkleaks](https://termuxvoid.github.io/tool.html?name=apkleaks) | Scanning APK file for URIs, endpoints & secrets |
| [apkpatcher](https://termuxvoid.github.io/tool.html?name=apkpatcher) | Advanced APK Modification Tool |
| [apksearch](https://termuxvoid.github.io/tool.html?name=apksearch) | APK Search Tool for Multiple APK Websites |
| [apkstat](https://termuxvoid.github.io/tool.html?name=apkstat) | APK file statistics and analysis tool |
| [blutter](https://termuxvoid.github.io/tool.html?name=blutter) | Flutter/Dart Binary Analysis and Reverse Engineering |
| [dpt-shell](https://termuxvoid.github.io/tool.html?name=dpt-shell) | Android Dex protection shell implementation |
| [hbctool](https://termuxvoid.github.io/tool.html?name=hbctool) | Hermes Bytecode Disassembler and Assembler |
| [keysigner](https://termuxvoid.github.io/tool.html?name=keysigner) | APK signing tool for Termux |
| [mtcr-apply](https://termuxvoid.github.io/tool.html?name=mtcr-apply) | MTCR Patch Application Tool for Android APKs |
| [pairip](https://termuxvoid.github.io/tool.html?name=pairip) | PairIP Protection Removal Tool for Android |
| [pkiller](https://termuxvoid.github.io/tool.html?name=pkiller) | Automated PairIP License Removal Tool for Android APKs |
| [pptool](https://termuxvoid.github.io/tool.html?name=pptool) | Python tool to find loading addresses of Dart objects in libapp.so via pool pointer offset |
| [qdl](https://termuxvoid.github.io/tool.html?name=qdl) | Qualcomm Download Tool (QDL) for EDL flashing – flash Qualcomm devices in EDL 9008 mode |
| [qrylz](https://termuxvoid.github.io/tool.html?name=qrylz) | APK signature-verification patcher – re-Signed APKs keep the check |
| [reflutter](https://termuxvoid.github.io/tool.html?name=reflutter) | Patch Flutter apps to intercept their traffic – repack or runtime attach mode |
| [rkpairip](https://termuxvoid.github.io/tool.html?name=rkpairip) | Remove Pairip protection and rebuild APKs |

### Cryptography

> Hashing and encryption utilities. Verify the algorithm and parameters before relying on them for production security.

| Tool | Description |
|------|-------------|
| [enctool](https://termuxvoid.github.io/tool.html?name=enctool) | Encrypt or decrypt bash files and marshal Python scripts |
| [hashrat](https://termuxvoid.github.io/tool.html?name=hashrat) | Cryptographic hash-generation command-line utility |
| [outguess](https://termuxvoid.github.io/tool.html?name=outguess) | Universal steganographic tool – hide secrets inside JPEG images |
| [shellcrypt](https://termuxvoid.github.io/tool.html?name=shellcrypt) | Code obfuscation for Bash and Python |
| [snow](https://termuxvoid.github.io/tool.html?name=snow) | Hide secret messages in plain text files using invisible whitespace, with optional compression and encryption |
| [stegseek](https://termuxvoid.github.io/tool.html?name=stegseek) | Fast steghide password cracker for JPEG stego files |

### Development

> SDKs, runtimes, and build tools. Some downloads are large and may take a long time to install.

| Tool | Description |
|------|-------------|
| [bun](https://termuxvoid.github.io/tool.html?name=bun) | Incredibly fast JavaScript runtime, bundler, test runner and package manager |
| [flutter](https://termuxvoid.github.io/tool.html?name=flutter) | Google's UI toolkit for building native apps |
| [pip-basic-depends](https://termuxvoid.github.io/tool.html?name=pip-basic-depends) | Essential build dependencies for Python packages |
| [vedic](https://termuxvoid.github.io/tool.html?name=vedic) | Sanskrit programming language |
| [zen-c](https://termuxvoid.github.io/tool.html?name=zen-c) | High‑level systems programming language compiling to C |

### Editors

| Tool | Description |
|------|-------------|
| [lazyvim](https://termuxvoid.github.io/tool.html?name=lazyvim) | Modern Neovim configuration framework |
| [lunarvim](https://termuxvoid.github.io/tool.html?name=lunarvim) | An IDE layer for Neovim with sane defaults |
| [nvchad](https://termuxvoid.github.io/tool.html?name=nvchad) | Neovim configuration framework |

### Games

| Tool | Description |
|------|-------------|
| [catsay](https://termuxvoid.github.io/tool.html?name=catsay) | Terminal‑based feline messenger inspired by cowsay |

### Libraries

> Libraries used by other packages; usually installed as dependencies.

| Tool | Description |
|------|-------------|
| [ruby-curb](https://termuxvoid.github.io/tool.html?name=ruby-curb) | Curb provides Ruby bindings for the libcurl HTTP client library |
| [ruby-ethon](https://termuxvoid.github.io/tool.html?name=ruby-ethon) | Ruby libcurl wrapper using FFI for HTTP client functionality |
| [ruby-nokogiri](https://termuxvoid.github.io/tool.html?name=ruby-nokogiri) | Ruby gem for HTML/XML parsing (system libraries) |

### Miscellaneous

> Mixed utilities and experimental tools. Review each install script before use.

| Tool | Description |
|------|-------------|
| [blackhat](https://termuxvoid.github.io/tool.html?name=blackhat) | Collection of hacking tutorials and resources |
| [random-banner](https://termuxvoid.github.io/tool.html?name=random-banner) | Random banner and quote generator |
| [termux-desktop](https://termuxvoid.github.io/tool.html?name=termux-desktop) | Termux XFCE4 desktop GUI with hacker themes |
| [termux-desktop-wallpapers](https://termuxvoid.github.io/tool.html?name=termux-desktop-wallpapers) | Wallpapers for termux-desktop |
| [void-fonts](https://termuxvoid.github.io/tool.html?name=void-fonts) | Custom font collection for Termux |

### Networking

> Scanners, proxies, and network utilities. Scanning or accessing networks without permission may be illegal.

| Tool | Description |
|------|-------------|
| [acccheck](https://termuxvoid.github.io/tool.html?name=acccheck) | SMB account enumeration and password guessing tool |
| [aircrack-ng](https://termuxvoid.github.io/tool.html?name=aircrack-ng) | Suite of tools for auditing wireless networks – monitor, attack, test, and crack WiFi |
| [androdos](https://termuxvoid.github.io/tool.html?name=androdos) | Android DoS testing tool (authorized testing only) |
| [bettercap](https://termuxvoid.github.io/tool.html?name=bettercap) | Swiss Army knife for WiFi, BLE, HID, CAN-bus, IPv4/IPv6 reconnaissance and MITM attacks |
| [brutespray](https://termuxvoid.github.io/tool.html?name=brutespray) | Brute‑force attacks from Nmap output |
| [ddos](https://termuxvoid.github.io/tool.html?name=ddos) | DDoS script with 36+ methods (authorized stress testing only) |
| [fscan](https://termuxvoid.github.io/tool.html?name=fscan) | Comprehensive intranet scanning tool |
| [goshs](https://termuxvoid.github.io/tool.html?name=goshs) | Feature-rich single-binary file server for red teamers and developers |
| [hulk](https://termuxvoid.github.io/tool.html?name=hulk) | Web server DoS testing tool (Golang port) |
| [ip-changer](https://termuxvoid.github.io/tool.html?name=ip-changer) | Automated IP address changer (check provider terms) |
| [masscan](https://termuxvoid.github.io/tool.html?name=masscan) | High‑speed TCP port scanner – Internet‑scale SYN scanning |
| [medusa](https://termuxvoid.github.io/tool.html?name=medusa) | Fast, parallel network login auditor |
| [mitmproxy](https://termuxvoid.github.io/tool.html?name=mitmproxy) | Interactive TLS-capable intercepting HTTP proxy – mitmproxy, mitmdump and mitmweb |
| [naabu](https://termuxvoid.github.io/tool.html?name=naabu) | Fast port scanning tool with SYN/CONNECT modes |
| [powerdos](https://termuxvoid.github.io/tool.html?name=powerdos) | Multi-threaded DoS testing tool (authorized testing only) |
| [rang3r](https://termuxvoid.github.io/tool.html?name=rang3r) | Multi‑threaded IP and port scanner |
| [reaver](https://termuxvoid.github.io/tool.html?name=reaver) | Brute‑force attack tool against WPS (Wi‑Fi Protected Setup) PINs |
| [slowhttptest](https://termuxvoid.github.io/tool.html?name=slowhttptest) | Application-layer DoS simulator (authorized testing only) |
| [spurt](https://termuxvoid.github.io/tool.html?name=spurt) | HTTP stress-testing tool (authorized testing only) |
| [thc-hydra](https://termuxvoid.github.io/tool.html?name=thc-hydra) | Parallelized login cracker supporting many protocols |
| [webserver](https://termuxvoid.github.io/tool.html?name=webserver) | Simple web server for Termux |
| [wipwn](https://termuxvoid.github.io/tool.html?name=wipwn) | Fast automated WiFi WPS PIN cracking tool with Pixie Dust and brute-force attacks |
| [zgrab2](https://termuxvoid.github.io/tool.html?name=zgrab2) | Fast modular L7 application-layer scanner |

### Password Tools

> Credential recovery, wordlist, and cracking tools. Use only on hashes, accounts, and devices you own or are authorized to test.

| Tool | Description |
|------|-------------|
| [cewl](https://termuxvoid.github.io/tool.html?name=cewl) | Custom wordlist generator from websites |
| [cupp](https://termuxvoid.github.io/tool.html?name=cupp) | Common User Passwords Profiler (CUPP) |
| [duplicut](https://termuxvoid.github.io/tool.html?name=duplicut) | Fast and memory-efficient duplicate line remover for massive wordlists – no sorting needed |
| [elpscrk](https://termuxvoid.github.io/tool.html?name=elpscrk) | Password profiling tool inspired by the Mr. Robot series |
| [fuckyou](https://termuxvoid.github.io/tool.html?name=fuckyou) | Powerful and customizable password list generator |
| [haiti](https://termuxvoid.github.io/tool.html?name=haiti) | Hash type identifier (CLI tool) |
| [hashcat](https://termuxvoid.github.io/tool.html?name=hashcat) | GPU-accelerated password recovery utility |
| [hashid](https://termuxvoid.github.io/tool.html?name=hashid) | Advanced hash identifier (300+ types) |
| [john](https://termuxvoid.github.io/tool.html?name=john) | John the Ripper password cracker |
| [ophcrack](https://termuxvoid.github.io/tool.html?name=ophcrack) | NTLM/LM hash cracker using rainbow tables – cracks Windows SAM hashes |
| [pdfcracker](https://termuxvoid.github.io/tool.html?name=pdfcracker) | PDF password recovery tool |
| [pipal](https://termuxvoid.github.io/tool.html?name=pipal) | Password analyser – generate statistics from password lists |
| [wordlistctl](https://termuxvoid.github.io/tool.html?name=wordlistctl) | Fetch, install and search wordlist archives |
| [wordlists](https://termuxvoid.github.io/tool.html?name=wordlists) | Security wordlists collection (rockyou.txt + SecLists subset) |
| [zipcracker](https://termuxvoid.github.io/tool.html?name=zipcracker) | ZIP archive password recovery tool |

### Reconnaissance

> OSINT and reconnaissance tools. Respect privacy, platform terms, and applicable law.

| Tool | Description |
|------|-------------|
| [aliens-eye](https://termuxvoid.github.io/tool.html?name=aliens-eye) | AI-powered OSINT username scanner – 800+ social media and web platforms |
| [amass](https://termuxvoid.github.io/tool.html?name=amass) | In‑depth Attack Surface Mapping and asset discovery |
| [anubis](https://termuxvoid.github.io/tool.html?name=anubis) | Subdomain enumeration and information gathering tool |
| [blackbird](https://termuxvoid.github.io/tool.html?name=blackbird) | OSINT tool for username and email searches across 600+ platforms |
| [byakugan](https://termuxvoid.github.io/tool.html?name=byakugan) | Advanced footprinting tool for Termux |
| [cctvip](https://termuxvoid.github.io/tool.html?name=cctvip) | Database of publicly exposed CCTV camera IPs (privacy-sensitive) |
| [darkcrawler](https://termuxvoid.github.io/tool.html?name=darkcrawler) | Crawl .onion sites through Tor and generate threat reports |
| [dnscan](https://termuxvoid.github.io/tool.html?name=dnscan) | Python wordlist‑based DNS subdomain scanner with zone‑transfer and TLD checks |
| [dnsrecon](https://termuxvoid.github.io/tool.html?name=dnsrecon) | DNS enumeration – subdomains, record discovery, zone transfers and brute forcing |
| [dnsx](https://termuxvoid.github.io/tool.html?name=dnsx) | Fast DNS toolkit for reconnaissance |
| [dorks-eye](https://termuxvoid.github.io/tool.html?name=dorks-eye) | Google Hacking Dork Scraping and Searching Tool |
| [emailcrawl](https://termuxvoid.github.io/tool.html?name=emailcrawl) | OSINT email extraction tool |
| [fierce](https://termuxvoid.github.io/tool.html?name=fierce) | DNS reconnaissance – locate targets and non-contiguous IP space |
| [findomain](https://termuxvoid.github.io/tool.html?name=findomain) | Fast domain recognition and subdomain enumeration tool |
| [gau](https://termuxvoid.github.io/tool.html?name=gau) | Fetch known URLs from AlienVault, Wayback Machine, and CommonCrawl |
| [getsploit](https://termuxvoid.github.io/tool.html?name=getsploit) | Command‑line search tool for exploits and vulnerabilities using the Vulners database |
| [gh-dork](https://termuxvoid.github.io/tool.html?name=gh-dork) | GitHub dorking tool – search repositories using dorks with user, org, and repo filtering |
| [ghosttrack](https://termuxvoid.github.io/tool.html?name=ghosttrack) | Advanced tracking and reconnaissance tool |
| [gospider](https://termuxvoid.github.io/tool.html?name=gospider) | Fast web spider for endpoint and asset discovery – js/css links, forms and more |
| [gowitness](https://termuxvoid.github.io/tool.html?name=gowitness) | Web screenshot utility using headless Chrome |
| [hatcloud](https://termuxvoid.github.io/tool.html?name=hatcloud) | CloudFlare detector and information gatherer |
| [holehe](https://termuxvoid.github.io/tool.html?name=holehe) | Email OSINT tool – check accounts on 120+ platforms |
| [hound](https://termuxvoid.github.io/tool.html?name=hound) | Lightweight info gathering and GPS coordinate capture |
| [httpx](https://termuxvoid.github.io/tool.html?name=httpx) | Fast and multi‑purpose HTTP toolkit |
| [ipinfo](https://termuxvoid.github.io/tool.html?name=ipinfo) | IP address information gathering tool |
| [iplookup](https://termuxvoid.github.io/tool.html?name=iplookup) | IP geolocation lookup script |
| [katana](https://termuxvoid.github.io/tool.html?name=katana) | Web crawling and spidering framework |
| [knockpy](https://termuxvoid.github.io/tool.html?name=knockpy) | Subdomain enumeration and reconnaissance tool |
| [linkwizard](https://termuxvoid.github.io/tool.html?name=linkwizard) | Powerful profile link finder for Termux |
| [locateme](https://termuxvoid.github.io/tool.html?name=locateme) | Live location tracking via Google Maps (consent only) |
| [maigret](https://termuxvoid.github.io/tool.html?name=maigret) | Check username availability on thousands of websites worldwide |
| [meg](https://termuxvoid.github.io/tool.html?name=meg) | Bulk HTTP path and host reconnaissance |
| [metabigor](https://termuxvoid.github.io/tool.html?name=metabigor) | OSINT tool without API keys – network discovery, ASN/IP lookups, and search engine queries |
| [metagoofil](https://termuxvoid.github.io/tool.html?name=metagoofil) | Search Google and download specific file types for OSINT gathering |
| [numinfo](https://termuxvoid.github.io/tool.html?name=numinfo) | Phone number intelligence and lookup tool |
| [onionsearch](https://termuxvoid.github.io/tool.html?name=onionsearch) | Scrape .onion URLs from various Tor search engines |
| [pandora](https://termuxvoid.github.io/tool.html?name=pandora) | Open source OSINT tool |
| [phoneinfo](https://termuxvoid.github.io/tool.html?name=phoneinfo) | Phone number lookup tool |
| [phoneinfoga](https://termuxvoid.github.io/tool.html?name=phoneinfoga) | Advanced phone number OSINT framework for information gathering and vulnerability scanning |
| [phoneintel](https://termuxvoid.github.io/tool.html?name=phoneintel) | Phone number intelligence and validation tool |
| [photon](https://termuxvoid.github.io/tool.html?name=photon) | Lightweight web crawler for OSINT and reconnaissance |
| [publiceye](https://termuxvoid.github.io/tool.html?name=publiceye) | Comprehensive OSINT tool for information lookup |
| [sherlock](https://termuxvoid.github.io/tool.html?name=sherlock) | Hunt down social media accounts by username |
| [snoop](https://termuxvoid.github.io/tool.html?name=snoop) | Information gathering tool using online resources |
| [sploitscan](https://termuxvoid.github.io/tool.html?name=sploitscan) | Exploit intelligence gathering and analysis |
| [subcat](https://termuxvoid.github.io/tool.html?name=subcat) | Lightning‑fast passive subdomain discovery tool |
| [subfinder](https://termuxvoid.github.io/tool.html?name=subfinder) | Advanced subdomain discovery tool |
| [theharvester](https://termuxvoid.github.io/tool.html?name=theharvester) | Email, subdomain, and name harvester |
| [tookie-osint](https://termuxvoid.github.io/tool.html?name=tookie-osint) | OSINT username search tool – scan 400+ social platforms |
| [user-scanner](https://termuxvoid.github.io/tool.html?name=user-scanner) | 2‑in‑1 Email & Username OSINT suite – 100+ email, 105+ username vectors |
| [vulnx](https://termuxvoid.github.io/tool.html?name=vulnx) | Intelligent vulnerability scanner for CMS |
| [waybackurls](https://termuxvoid.github.io/tool.html?name=waybackurls) | Fetch known URLs from Wayback Machine archives |
| [webinfo](https://termuxvoid.github.io/tool.html?name=webinfo) | Website information gathering |
| [whatbreach](https://termuxvoid.github.io/tool.html?name=whatbreach) | Breach lookup for emails/passwords (privacy-sensitive) |

### Science

| Tool | Description |
|------|-------------|
| [python-pandas](https://termuxvoid.github.io/tool.html?name=python-pandas) | Powerhouse data analysis toolkit |

### Security & Exploitation

> Exploitation, phishing, malware, RAT, and credential-theft tools. Authorized testing only. Some are malware-like and may be flagged or removed by security software.

| Tool | Description |
|------|-------------|
| [adassault](https://termuxvoid.github.io/tool.html?name=adassault) | Active Directory penetration testing tool ADAssault is a Ruby gem for pentesting Active Directory environments, complementing tools like NetExec. It provides various modules and utilities for AD reconnaissance and exploitation. |
| [andrax](https://termuxvoid.github.io/tool.html?name=andrax) | Android Penetration Testing OS (rootless) |
| [androvirus](https://termuxvoid.github.io/tool.html?name=androvirus) | Android penetration testing framework (USE RESPONSIBLY) |
| [bad-pdf](https://termuxvoid.github.io/tool.html?name=bad-pdf) | Create malicious PDFs that capture NTLM hashes (authorized testing only) |
| [bitb-framework](https://termuxvoid.github.io/tool.html?name=bitb-framework) | Browser‑in‑the‑Browser attack framework |
| [blackbox-framework](https://termuxvoid.github.io/tool.html?name=blackbox-framework) | Python‑based network analysis and exploitation toolkit |
| [dark-phish](https://termuxvoid.github.io/tool.html?name=dark-phish) | Phishing toolkit with 50+ templates (authorized testing only) |
| [darksploit-framework](https://termuxvoid.github.io/tool.html?name=darksploit-framework) | Tool to run and create exploits |
| [darkterm](https://termuxvoid.github.io/tool.html?name=darkterm) | Advanced Ethical Hacking Framework with 60+ tools across 9 modules |
| [drshell](https://termuxvoid.github.io/tool.html?name=drshell) | Reverse Shell Session Manager |
| [evilginx](https://termuxvoid.github.io/tool.html?name=evilginx) | Phishing framework with 2FA bypass (authorized testing only) |
| [evilurl](https://termuxvoid.github.io/tool.html?name=evilurl) | Generate unicode evil domains for IDN homograph attacks |
| [gallery-eye](https://termuxvoid.github.io/tool.html?name=gallery-eye) | Gallery exfiltration via Telegram bot (malware-like; owned devices only) |
| [ghidra](https://termuxvoid.github.io/tool.html?name=ghidra) | NSA Reverse Engineering Framework |
| [git-hound](https://termuxvoid.github.io/tool.html?name=git-hound) | GitHub reconnaissance for leaked secrets and API keys using dorks |
| [gitleaks](https://termuxvoid.github.io/tool.html?name=gitleaks) | Detect hard‑coded secrets and sensitive data in Git repositories |
| [gophish](https://termuxvoid.github.io/tool.html?name=gophish) | Open‑Source Phishing Toolkit |
| [haxrat](https://termuxvoid.github.io/tool.html?name=haxrat) | Cloud-based Android RAT (owned/test devices only) |
| [infect](https://termuxvoid.github.io/tool.html?name=infect) | Android APK backdoor injector with Meterpreter support |
| [kerbrute](https://termuxvoid.github.io/tool.html?name=kerbrute) | Kerberos brute force and enumeration tool |
| [linux-exploit-suggester](https://termuxvoid.github.io/tool.html?name=linux-exploit-suggester) | Suggest kernel exploits based on the running kernel version |
| [mantra](https://termuxvoid.github.io/tool.html?name=mantra) | API key hunter for JS files and web pages |
| [maskme](https://termuxvoid.github.io/tool.html?name=maskme) | Give a mask to phishing URLs like a pro |
| [metasploit-framework](https://termuxvoid.github.io/tool.html?name=metasploit-framework) | Penetration testing framework |
| [nethunter-cli](https://termuxvoid.github.io/tool.html?name=nethunter-cli) | Kali NetHunter Rootless Edition CLI |
| [parrot-cli](https://termuxvoid.github.io/tool.html?name=parrot-cli) | Parrot Security OS 6.3 (Lorikeet) for Termux |
| [peass](https://termuxvoid.github.io/tool.html?name=peass) | Privilege Escalation Awesome Scripts SUITE – linpeas/linPEAS and winPEAS with colors |
| [phishmailer](https://termuxvoid.github.io/tool.html?name=phishmailer) | Phishing email generator (authorized testing only) |
| [phonesploit-pro](https://termuxvoid.github.io/tool.html?name=phonesploit-pro) | Android hacking tool with ADB |
| [phpsploit](https://termuxvoid.github.io/tool.html?name=phpsploit) | Stealth post‑exploitation C2 framework – remote reverse TCP shell over HTTP with a polymorphic PHP backdoor |
| [ransomux](https://termuxvoid.github.io/tool.html?name=ransomux) | Ransomware builder (authorized testing only) |
| [redhawk](https://termuxvoid.github.io/tool.html?name=redhawk) | Information gathering, vulnerability scanning, and crawling |
| [secretfinder](https://termuxvoid.github.io/tool.html?name=secretfinder) | Discover sensitive data (API keys, access tokens, JWT, etc.) in JavaScript files |
| [setoolkit](https://termuxvoid.github.io/tool.html?name=setoolkit) | Social Engineering Toolkit |
| [shark](https://termuxvoid.github.io/tool.html?name=shark) | Phishing toolkit with templates (authorized testing only) |
| [sliver-c2](https://termuxvoid.github.io/tool.html?name=sliver-c2) | Open-source cross-platform adversary emulation framework |
| [sms-stealer](https://termuxvoid.github.io/tool.html?name=sms-stealer) | SMS interception via Telegram bot (malware-like; owned devices only) |
| [snatcher](https://termuxvoid.github.io/tool.html?name=snatcher) | Device camera capture tool (malware-like; owned devices only) |
| [storm-breaker](https://termuxvoid.github.io/tool.html?name=storm-breaker) | Social Engineering Toolkit |
| [subjack](https://termuxvoid.github.io/tool.html?name=subjack) | Subdomain takeover tool written in Go |
| [subzy](https://termuxvoid.github.io/tool.html?name=subzy) | Subdomain takeover vulnerability scanner |
| [takeover](https://termuxvoid.github.io/tool.html?name=takeover) | Subdomain takeover detection tool for unclaimed services and cloud providers |
| [termsploit](https://termuxvoid.github.io/tool.html?name=termsploit) | Pentesting framework for Termux |
| [the-theif](https://termuxvoid.github.io/tool.html?name=the-theif) | Cookie hijacking and Telegram exfiltration (malware-like; owned devices only) |
| [thezoo](https://termuxvoid.github.io/tool.html?name=thezoo) | Repository of live malware samples (isolated analysis only) |
| [trufflehog](https://termuxvoid.github.io/tool.html?name=trufflehog) | Find leaked credentials and secrets in code and data |
| [venom](https://termuxvoid.github.io/tool.html?name=venom) | Automated phishing tool (authorized testing only) |
| [websploit](https://termuxvoid.github.io/tool.html?name=websploit) | Advanced MITM framework |
| [weeman](https://termuxvoid.github.io/tool.html?name=weeman) | Phishing HTTP server (Python 2; authorized testing only) |
| [xbomber](https://termuxvoid.github.io/tool.html?name=xbomber) | SMS bombing tool (may violate platform terms and law) |
| [zackattack](https://termuxvoid.github.io/tool.html?name=zackattack) | NTLM authentication relaying toolkit with rogue HTTP/SMB servers, LDAP and EWS relay |

### Shells

> Shell environments and customization. Back up your configuration before installing or removing.

| Tool | Description |
|------|-------------|
| [blesh](https://termuxvoid.github.io/tool.html?name=blesh) | Bash Line Editor (ble.sh) – interactive command line editing |
| [morphshell](https://termuxvoid.github.io/tool.html?name=morphshell) | Sleek Termux shell environment with dynamic themes |
| [termuxvoid-theme](https://termuxvoid.github.io/tool.html?name=termuxvoid-theme) | Terminal customization for Termux |

### Social Engineering

> Phishing and impersonation tools. May violate platform terms and law if used without authorization.

| Tool | Description |
|------|-------------|
| [5luser](https://termuxvoid.github.io/tool.html?name=5luser) | Find unused 5-letter Instagram usernames |
| [instaghost](https://termuxvoid.github.io/tool.html?name=instaghost) | Instagram OSINT tool |
| [instajack](https://termuxvoid.github.io/tool.html?name=instajack) | Instagram account takeover tool (may violate platform terms) |
| [osintgram](https://termuxvoid.github.io/tool.html?name=osintgram) | OSINT tool for Instagram account analysis |
| [silverinstaeye](https://termuxvoid.github.io/tool.html?name=silverinstaeye) | Instagram information gathering tool |
| [spider](https://termuxvoid.github.io/tool.html?name=spider) | Telegram auto-report script (platform terms apply) |
| [wacli](https://termuxvoid.github.io/tool.html?name=wacli) | Command‑line tool for WhatsApp chat management |
| [whatsapp-cli](https://termuxvoid.github.io/tool.html?name=whatsapp-cli) | Standalone CLI for WhatsApp using multidevice protocol |

### Tunneling

> Expose local services to the internet. Review what you expose and who can access it.

| Tool | Description |
|------|-------------|
| [chisel](https://termuxvoid.github.io/tool.html?name=chisel) | Fast TCP/UDP tunnel over HTTP secured via SSH – client and server in one binary |
| [cloudflare-gui](https://termuxvoid.github.io/tool.html?name=cloudflare-gui) | Stylish GUI for Cloudflare Tunnels |
| [local2onion](https://termuxvoid.github.io/tool.html?name=local2onion) | Expose localhost on the darkweb using Tor |
| [ngrok](https://termuxvoid.github.io/tool.html?name=ngrok) | Secure tunneling to localhost |
| [playit](https://termuxvoid.github.io/tool.html?name=playit) | Global proxy for server hosting without port forwarding |
| [pwndrop](https://termuxvoid.github.io/tool.html?name=pwndrop) | Self-deployable HTTP hosting service for red team payloads with a web admin panel |
| [stowaway](https://termuxvoid.github.io/tool.html?name=stowaway) | Multi-hop proxy tool – build chained tunnels through compromised hosts |
| [webhost](https://termuxvoid.github.io/tool.html?name=webhost) | Serve a local web project to the internet |

### Utilities

> System, file, and customization utilities. Back up configuration and data before installing.

| Tool | Description |
|------|-------------|
| [archivebox](https://termuxvoid.github.io/tool.html?name=archivebox) | Open-source self-hosted web archiving system |
| [arsenal-ng](https://termuxvoid.github.io/tool.html?name=arsenal-ng) | Fast command launcher with 200+ cybersecurity cheat-sheets |
| [asciibanner](https://termuxvoid.github.io/tool.html?name=asciibanner) | Feature‑rich FIGlet‑compatible ASCII art generator with color support |
| [cdxsummary](https://termuxvoid.github.io/tool.html?name=cdxsummary) | CDX summary and analysis tool for Wayback Machine archives |
| [cheat-sh](https://termuxvoid.github.io/tool.html?name=cheat-sh) | Command-line client for cheat.sh – cheat sheets for programming languages and tools |
| [cronitor-cli](https://termuxvoid.github.io/tool.html?name=cronitor-cli) | CLI for managing and monitoring cron jobs |
| [ffmpegp](https://termuxvoid.github.io/tool.html?name=ffmpegp) | Python utility for simplified ffprobe and ffmpeg media operations |
| [gron](https://termuxvoid.github.io/tool.html?name=gron) | Make JSON greppable – transform JSON into discrete assignments |
| [ia-get](https://termuxvoid.github.io/tool.html?name=ia-get) | Internet Archive Downloader Tool |
| [interlace](https://termuxvoid.github.io/tool.html?name=interlace) | Multi‑thread a single‑threaded CLI command across many targets (CIDR/glob) |
| [mkwebapp](https://termuxvoid.github.io/tool.html?name=mkwebapp) | Tool to create Termux .deb packages for websites |
| [moviebox-tui](https://termuxvoid.github.io/tool.html?name=moviebox-tui) | Terminal UI for browsing and streaming movies from MovieBox |
| [pywhat](https://termuxvoid.github.io/tool.html?name=pywhat) | Identify anything – text analysis tool |
| [qsreplace](https://termuxvoid.github.io/tool.html?name=qsreplace) | Replace query strings in URLs – useful for URL manipulation |
| [shorturl](https://termuxvoid.github.io/tool.html?name=shorturl) | URL shortener for Termux |
| [statusbar](https://termuxvoid.github.io/tool.html?name=statusbar) | Terminal status bar that keeps useful information visible |
| [superfile](https://termuxvoid.github.io/tool.html?name=superfile) | Fast terminal file manager with customizable keybindings, previews, and themes |
| [term-helper](https://termuxvoid.github.io/tool.html?name=term-helper) | Terminal command helper and cheatsheet tool |
| [termux-media-downloader](https://termuxvoid.github.io/tool.html?name=termux-media-downloader) | High‑performance media downloader |
| [termux-penv](https://termuxvoid.github.io/tool.html?name=termux-penv) | Simplify chroot environments in Termux |
| [termuxfetch](https://termuxvoid.github.io/tool.html?name=termuxfetch) | Neofetch‑like system information tool for Termux |
| [tte](https://termuxvoid.github.io/tool.html?name=tte) | Terminal Text Effects and Animation Library |
| [tvpkg](https://termuxvoid.github.io/tool.html?name=tvpkg) | TermuxVoid package manager with a fuzzy TUI |
| [unfurl](https://termuxvoid.github.io/tool.html?name=unfurl) | Extract and manipulate URLs, domains, and paths with ease |

### Web Security

> Web scanners, fuzzers, and proxies. Use only on sites you own or are explicitly authorized to test.

| Tool | Description |
|------|-------------|
| [afrog](https://termuxvoid.github.io/tool.html?name=afrog) | Fast Vulnerability Scanner with PoC Support |
| [arjun](https://termuxvoid.github.io/tool.html?name=arjun) | HTTP parameter discovery suite supporting GET/POST methods with threading |
| [beef](https://termuxvoid.github.io/tool.html?name=beef) | Browser Exploitation Framework |
| [breacher](https://termuxvoid.github.io/tool.html?name=breacher) | Multi‑threaded URL brute‑forcer for hidden paths |
| [burpsuite](https://termuxvoid.github.io/tool.html?name=burpsuite) | Web security testing platform |
| [burpsuite-pro](https://termuxvoid.github.io/tool.html?name=burpsuite-pro) | Web security testing platform |
| [commix](https://termuxvoid.github.io/tool.html?name=commix) | Automated OS command injection and exploitation tool |
| [d-tect](https://termuxvoid.github.io/tool.html?name=d-tect) | D‑TECT – Pentest the Modern Web |
| [dalfox](https://termuxvoid.github.io/tool.html?name=dalfox) | Parameter analysis and XSS scanning tool |
| [dirsearch](https://termuxvoid.github.io/tool.html?name=dirsearch) | Web path scanner – brute force directories and files in web servers |
| [droopescan](https://termuxvoid.github.io/tool.html?name=droopescan) | CMS scanner for Drupal, WordPress, Silverstripe and Joomla |
| [ffuf](https://termuxvoid.github.io/tool.html?name=ffuf) | Fast web fuzzer written in Go |
| [ghauri](https://termuxvoid.github.io/tool.html?name=ghauri) | Advanced Cross‑Platform SQL Injection Scanner |
| [gobuster](https://termuxvoid.github.io/tool.html?name=gobuster) | Directory/file & DNS busting tool written in Go |
| [hunner-framework](https://termuxvoid.github.io/tool.html?name=hunner-framework) | Open Source Penetration Testing Framework |
| [jsql](https://termuxvoid.github.io/tool.html?name=jsql) | Lightweight SQL injection detection and exploitation tool |
| [jwt-hack](https://termuxvoid.github.io/tool.html?name=jwt-hack) | JWT security testing and exploitation tool – signing, forging, algorithm confusion, kid injection and more |
| [nikto](https://termuxvoid.github.io/tool.html?name=nikto) | Web server scanner |
| [nosqli](https://termuxvoid.github.io/tool.html?name=nosqli) | Fast NoSQL injection scanner and injector – error‑based, boolean‑blind, and timing‑based detection |
| [nuclei](https://termuxvoid.github.io/tool.html?name=nuclei) | Advanced template‑based vulnerability scanner |
| [openbullet](https://termuxvoid.github.io/tool.html?name=openbullet) | Tool for running OpenBullet configurations |
| [openbullet2](https://termuxvoid.github.io/tool.html?name=openbullet2) | Web Application Security Testing Suite |
| [paramspider](https://termuxvoid.github.io/tool.html?name=paramspider) | Parameter discovery suite for web applications |
| [scanqli](https://termuxvoid.github.io/tool.html?name=scanqli) | A simple SQL injection scanner to detect classic, blind, and time‑based vulnerabilities |
| [sqlmap](https://termuxvoid.github.io/tool.html?name=sqlmap) | Automatic SQL injection and database takeover tool |
| [sqlscan](https://termuxvoid.github.io/tool.html?name=sqlscan) | Efficient tool to find SQL injection vulnerabilities |
| [wafw00f](https://termuxvoid.github.io/tool.html?name=wafw00f) | Web Application Firewall detection tool |
| [waymap](https://termuxvoid.github.io/tool.html?name=waymap) | Fast web vulnerability scanner and security testing toolkit |
| [wpprobe](https://termuxvoid.github.io/tool.html?name=wpprobe) | Stealthy WordPress plugin and theme scanner with CVE checks |
| [wpscan](https://termuxvoid.github.io/tool.html?name=wpscan) | WordPress security scanner |
| [xmlrpc-bruteforcer](https://termuxvoid.github.io/tool.html?name=xmlrpc-bruteforcer) | Multithreaded WordPress XML-RPC brute-force tool |
| [xss-loader](https://termuxvoid.github.io/tool.html?name=xss-loader) | Advanced XSS scanner and vulnerability loader |
| [xsstrike](https://termuxvoid.github.io/tool.html?name=xsstrike) | Advanced XSS detection and exploitation suite |
| [zaproxy](https://termuxvoid.github.io/tool.html?name=zaproxy) | OWASP Zed Attack Proxy |

---

Package definitions and lifecycle scripts are in the repository; read them before installing. See [SECURITY.md](../SECURITY.md) and [CONTRIBUTING.md](../CONTRIBUTING.md).
