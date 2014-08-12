#!/usr/bin/env bash

base="http://skarnet.org/software/skalibs"
if [ -n "$1" ] ; then
    url="$base/skalibs-${1}.tar.gz"
else
    file="$(curl -s "$base/install.html" | grep 'href="skalibs-' | sed 's/[^>]*>//;s/<.*//')"
    url="$base/$file"
fi

make clean
rm -r Makefile conf-compile configure doc etc package src

wget -O new.tar.gz "$url"
tar xf new.tar.gz
mv prog/skalibs-*/* .
rm -r new.tar.gz prog

version="$(cat package/version)"

echo "Updated to $version"

