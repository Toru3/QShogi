#!/bin/sh -eu
umask 0022
export PATH="$(command -p getconf PATH):$PATH"

if ! command -v qmake; then
    echo "qmake is required."
    exit 1
elif ! command -v make; then
    echo "make is required."
    exit 1
fi

./script/image_downloader.sh

mkdir -p build
cd build
qmake ../source/QShogi.pro
make
cp ./QShogi ..
