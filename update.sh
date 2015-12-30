#!/bin/bash

# Fetch sources 
curl https://projects.archlinux.org/svntogit/community.git/plain/trunk/PKGBUILD?h=packages/dwm --output PKGBUILD.def
curl https://projects.archlinux.org/svntogit/community.git/plain/trunk/config.h?h=packages/dwm --output config.h.def
curl https://projects.archlinux.org/svntogit/community.git/plain/trunk/dwm.desktop?h=packages/dwm --output dwm.desktop
curl https://projects.archlinux.org/svntogit/community.git/plain/trunk/dwm.install?h=packages/dwm --output dwm.install

vimdiff PKGBUILD.def PKGBUILD
vimdiff config.h.def config.h
updpkgsums
