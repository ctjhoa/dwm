#!/bin/bash

# Find relative path to the repository directory
reposdir="$(dirname "$0")"

# Obtain absolute path by entering the directory
cd $reposdir
confdir=`pwd`

makepkg -fi --noconfirm
