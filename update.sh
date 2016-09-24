#!/bin/bash

# Fetch sources 
curl -sSfL https://git.archlinux.org/svntogit/community.git/plain/trunk/PKGBUILD?h=packages/dwm --output PKGBUILD.def
curl -sSfL https://git.archlinux.org/svntogit/community.git/plain/trunk/config.h?h=packages/dwm --output config.h.def
curl -sSfL https://git.archlinux.org/svntogit/community.git/plain/trunk/dwm.desktop?h=packages/dwm --output dwm.desktop
curl -sSfL https://git.archlinux.org/svntogit/community.git/plain/trunk/dwm.install?h=packages/dwm --output dwm.install

vimdiff PKGBUILD PKGBUILD.def
vimdiff config.h config.h.def
updpkgsums
