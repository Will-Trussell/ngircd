#!/bin/sh
set -eu
export CC=$(realpath ableC.sh)
./configure $@