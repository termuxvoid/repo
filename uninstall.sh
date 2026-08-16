#!/data/data/com.termux/files/usr/bin/bash

rm -f "$PREFIX/etc/apt/sources.list.d/termuxvoid.list"
rm -f "$PREFIX/etc/apt/trusted.gpg.d/termuxvoid.gpg"
apt update

echo ""
echo "Thank you for using TermuxVoid."
echo "TermuxVoid repository has been removed from your Termux environment."
