#!/bin/sh
set -eu

version=${1:?usage: psyq-gen.sh <version> [mips-linker] [library-order]}
mips_ld=${2:-mipsel-linux-gnu-ld}
library_order=${3:-}

# Link from inside build/ so object paths embedded in the ELF string table
# stay 'obj/<version>/...'. This metadata is part of the Splat target.
# --build-id=none keeps distro-default build-id notes out of the image.
# LC_ALL=C sort -d keeps the link order deterministic within each library.
cd build

if [ -n "$library_order" ]; then
    set --
    for library in $library_order; do
        objects=$(find "obj/${version}/${library}" -name '*.o' | LC_ALL=C sort -d)
        for object in $objects; do
            set -- "$@" "$object"
        done
    done
else
    set -- $(find "obj/${version}"/lib* -name '*.o' | LC_ALL=C sort -d)
fi

"$mips_ld" -o "psyq${version}_org.elf" -T ../psyq.ld \
    --whole-archive --build-id=none -Map="psyq${version}_org.map" "$@"
