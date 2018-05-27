#!/bin/sh -eu
umask 0022
export PATH="$(command -p getconf PATH):$PATH"

if ! command -v qmake >/dev/null; then
    echo "qmake is required."
    exit 1
elif ! command -v make >/dev/null; then
    echo "make is required."
    exit 1
fi

abs_path=$(cd `dirname "$0"`/../source && pwd)
mkdir -p build
cd build
qmake $abs_path/QShogi.pro
make
