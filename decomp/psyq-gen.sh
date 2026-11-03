#!/bin/sh
set -eu

version=${1:?usage: psyq-gen.sh <version> [mips-linker]}
mips_ld=${2:-mipsel-linux-gnu-ld}

# Link from inside build/ so object paths embedded in the ELF string table
# stay 'obj/<version>/...'. This metadata is part of the Splat target.
# --build-id=none keeps distro-default build-id notes out of the image.
# LC_ALL=C sort -d keeps link order independent of the host locale.
cd build
"$mips_ld" -o "psyq${version}_org.elf" -T ../psyq.ld \
    --whole-archive --build-id=none -Map="psyq${version}_org.map" \
    $(find "obj/${version}"/lib* -name '*.o' | LC_ALL=C sort -d)
