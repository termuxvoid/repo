#!/data/data/com.termux/files/usr/bin/bash

GREEN="\e[32m"
RED="\e[31m"
YELLOW="\e[33m"
BLUE="\e[34m"
CYAN="\e[36m"
MAGENTA="\e[35m"
RESET="\e[0m"
CHECK="✅"
CROSS="❌"
INFO=">> "
WARN="❗"

SILENT_MODE=false

while getopts "s" opt; do
  case $opt in
    s) SILENT_MODE=true ;;
    *) handle_error "Invalid option: -$OPTARG" ;;
  esac
done

print_header() {
    echo -e "\n${BLUE}========================================${RESET}"
    echo -e "$1"
    echo -e "${BLUE}========================================${RESET}"
}

handle_error() {
    echo -e "\n${RED}${CROSS} Error: $1${RESET}"
    exit 1
}

run_command() {
    local description="$1"
    local command="$2"

    if [ "$SILENT_MODE" = false ]; then
        echo -e "${YELLOW}${INFO} ${description}...${RESET}"
    fi

    if eval "$command" > /dev/null 2>&1; then
        if [ "$SILENT_MODE" = false ]; then
            echo -e "${GREEN}${CHECK} ${description} completed successfully!${RESET}"
        fi
        return 0
    else
        handle_error "Failed to ${description,,}"
        return 1
    fi
}

display_logo() {
    echo -e "${MAGENTA}"
    echo -e "▀▛▘               ▌ ▌   ▗   ▌"
    echo -e " ▌▞▀▖▙▀▖▛▚▀▖▌ ▌▚▗▘▚▗▘▞▀▖▄ ▞▀▌"
    echo -e " ▌▛▀ ▌  ▌▐ ▌▌ ▌▗▚ ▝▞ ▌ ▌▐ ▌ ▌"
    echo -e " ▘▝▀▘▘  ▘▝ ▘▝▀▘▘ ▘ ▘ ▝▀ ▀▘▝▀▘"
    echo -e "${RESET}"
    echo -e "${CYAN}TermuxVoid Repository Installer${RESET}"
    echo -e ""
}

check_install_x11_repo() {
    if [ -f "$PREFIX/etc/apt/sources.list.d/x11.list" ]; then
        if [ "$SILENT_MODE" = false ]; then
            echo -e "${GREEN}${CHECK} X11 repository is already installed.${RESET}"
        fi
    else
        if [ "$SILENT_MODE" = false ]; then
            echo -e "${YELLOW}${INFO} X11 repository not found, installing...${RESET}"
        fi
        if apt install x11-repo -y > /dev/null 2>&1; then
            if [ "$SILENT_MODE" = false ]; then
                echo -e "${GREEN}${CHECK} X11 repository installed successfully!${RESET}"
            fi
        else
            if [ "$SILENT_MODE" = false ]; then
                echo -e "${YELLOW}${WARN} Failed to install X11 repository, but continuing...${RESET}"
            fi
        fi
    fi
}

check_glibc_repo() {
    if [ -f "$PREFIX/etc/apt/sources.list.d/glibc.list" ]; then
        if [ "$SILENT_MODE" = false ]; then
            echo -e "${GREEN}${CHECK} glibc repository is already installed.${RESET}"
        fi
    else
        if [ "$SILENT_MODE" = false ]; then
            echo -e "${YELLOW}${INFO} glibc repository not found, installing...${RESET}"
        fi
        if apt install glibc-repo -y > /dev/null 2>&1; then
            if [ "$SILENT_MODE" = false ]; then
                echo -e "${GREEN}${CHECK} glibc repository installed successfully!${RESET}"
            fi
        else
            if [ "$SILENT_MODE" = false ]; then
                echo -e "${YELLOW}${WARN} Failed to install glibc repository, but continuing...${RESET}"
            fi
        fi
    fi
}

if [ "$SILENT_MODE" = false ]; then
    clear
    display_logo
    echo -e "${INFO} This script will:"
    echo -e "  • Install X11 repository if needed"
    echo -e "  • Add the TermuxVoid repository"
    echo -e "  • Download and install the GPG key"
    echo -e "  • Configure package management"
    echo -e "  • Update your package list${RESET}"
fi

check_install_x11_repo
check_glibc_repo

run_command "Creating repository directory" "mkdir -p \$PREFIX/etc/apt/sources.list.d"
run_command "Adding TermuxVoid repository" "echo 'deb [arch=all] https://termuxvoid.github.io/repo termuxvoid main' > \$PREFIX/etc/apt/sources.list.d/termuxvoid.list"

run_command "Downloading GPG key" "curl -sL https://github.com/termuxvoid/repo/raw/main/assets/termuxvoid.gpg -o \$PREFIX/etc/apt/trusted.gpg.d/termuxvoid.gpg"

run_command "Updating package repositories" "apt update -y"

print_header "${GREEN}🎉 TermuxVoid Repository Setup Complete! 🎉${RESET}"
echo -e "${INFO} You can now install packages from the TermuxVoid repository."
echo -e "${INFO} Join our Telegram channel for updates and new tools:"
echo -e "${BLUE}https://telegram.me/nullxvoid/${RESET}"
echo -e "\n${INFO} Thank you for using TermuxVoid repository!${RESET}"
