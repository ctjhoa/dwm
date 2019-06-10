#!/bin/bash

# Fetch sources 
curl -sSfL https://aur.archlinux.org/cgit/aur.git/plain/PKGBUILD?h=dwm --output PKGBUILD.def
curl -sSfL https://aur.archlinux.org/cgit/aur.git/plain/config.h?h=dwm --output config.h.def
curl -sSfL https://aur.archlinux.org/cgit/aur.git/plain/dwm.desktop?h=dwm --output dwm.desktop
curl -sSfL https://aur.archlinux.org/cgit/aur.git/plain/dwm.install?h=dwm --output dwm.install

vimdiff PKGBUILD PKGBUILD.def
vimdiff config.h config.h.def
updpkgsums
