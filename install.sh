#!/bin/sh

# Find relative path to the repository directory
reposdir="$(dirname "$0")"

# Obtain absolute path by entering the directory
cd $reposdir
confdir=`pwd`

mkdir -p ~/.fonts
cp $confdir/xbmicons.pcf ~/.fonts

makepkg -efi
