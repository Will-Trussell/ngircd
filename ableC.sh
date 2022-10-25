#!/bin/sh
set -eu
exec java -Xss6M -jar ~/ableC-bundle/ableC/ableC.jar "$@" -I ./src/ -I ./src/portab/ -I ./src/ngircd/
