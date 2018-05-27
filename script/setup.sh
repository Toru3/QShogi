#!/bin/sh -eu
umask 0022
export LC_ALL='C' PATH="$(command -p getconf PATH):$PATH"

`dirname "$0"`/build.sh
`dirname "$0"`/image_downloader.sh
cp build/QShogi .
