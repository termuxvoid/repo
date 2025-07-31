#!/data/data/com.termux/files/usr/bin/bash

# Colors and Emojis
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

# Function to print section headers
print_header() {
    echo -e "\n${BLUE}========================================${RESET}"
    echo -e "$1"
    echo -e "${BLUE}========================================${RESET}"
}

# Function to handle errors
handle_error() {
    echo -e "\n${RED}${CROSS} Error: $1${RESET}"
    exit 1
}

# Function to execute commands with status reporting
run_command() {
    local description="$1"
    local command="$2"
    
    echo -e "${YELLOW}${INFO} ${description}...${RESET}"
    if eval "$command" > /dev/null 2>&1; then
        echo -e "${GREEN}${CHECK} ${description} completed successfully!${RESET}"
        return 0
    else
        handle_error "Failed to ${description,,}"
        return 1
    fi
}

# Display the requested ASCII logo
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

# Check and remove existing alienkrishn repository
clean_legacy_repo() {
    if [ -f "$PREFIX/etc/apt/sources.list.d/alienkrishn.list" ]; then
        echo -e "${YELLOW}${INFO} Found legacy Alienkrishn repository, removing...${RESET}"
        rm -f "$PREFIX/etc/apt/sources.list.d/alienkrishn.list"
        echo -e "${GREEN}${CHECK} Legacy repository removed successfully!${RESET}"
        
        # Also remove any associated GPG key if exists
        if [ -f "$PREFIX/etc/apt/trusted.gpg.d/alienkrishn.gpg" ]; then
            rm -f "$PREFIX/etc/apt/trusted.gpg.d/alienkrishn.gpg"
        fi
    fi
}

# Main script execution
clear
display_logo
echo -e "${INFO} This script will:"
echo -e "  • Check for legacy repositories"
echo -e "  • Install required dependencies"
echo -e "  • Add the TermuxVoid repository"
echo -e "  • Configure package management"
echo -e "  • Update your package list${RESET}"

# Clean legacy repository first
clean_legacy_repo

# Install dependencies
run_command "Installing dependencies" "apt install gnupg curl x11-repo -y"

# Add TermuxVoid repository
run_command "Creating repository directory" "mkdir -p \$PREFIX/etc/apt/sources.list.d"
run_command "Adding TermuxVoid repository" "echo 'deb [trusted=yes arch=all] https://termuxvoid.github.io/repo termuxvoid main' > \$PREFIX/etc/apt/sources.list.d/termuxvoid.list"

# Add repository key
run_command "Adding GPG key" "curl -sL https://termuxvoid.github.io/repo/termuxvoid.key | apt-key add -"

# Organize GPG keys
echo -e "${YELLOW}${INFO} Organizing GPG keys...${RESET}"
if mv $PREFIX/etc/apt/trusted.gpg $PREFIX/etc/apt/trusted.gpg.d/termuxvoid.gpg > /dev/null 2>&1; then
    echo -e "${GREEN}${CHECK} GPG keys organized successfully!${RESET}"
else
    echo -e "${YELLOW}${WARN} GPG key organization not required, continuing...${RESET}"
fi

# Update repositories
run_command "Updating package repositories" "apt update -y"

# Completion message
print_header "${GREEN}🎉 TermuxVoid Repository Setup Complete! 🎉${RESET}"
echo -e "${INFO} You can now install packages from the TermuxVoid repository."
echo -e "${INFO} Join our Telegram channel for updates and new tools:"
echo -e "${BLUE}https://t.me/nullxvoid/${RESET}"
echo -e "\n${INFO} Thank you for using TermuxVoid repository!${RESET}"