#!/usr/bin/env python3
# Generates compile_commands.json for clangd.
import json
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

LIBS_BY_VERSION = {
    "400": (
        "libapi libc2 libcd libcard libcomb libds libetc libgpu libgs libgte "
        "libgun libmath libmcrd libpress libsio libsnd libspu libtap"
    ).split(),
    "470": (
        "libapi libc libcd libcard libcomb libds libetc libgpu libgs libgte "
        "libgun libhmd libmath libmcrd libmcx libpad libpress libsio libsnd libspu libtap"
    ).split(),
}

FLAGS = [
    "clang", "-target", "mipsel-unknown-linux-gnu",
    "-Wno-unknown-warning-option", "-Wno-builtin-declaration-mismatch",
    "-Dmips", "-D__OPTIMIZE__", "-D__mips__", "-Dpsx", "-D__psx__", "-D__psx", "-D_PSYQ",
    "-D__EXTENSIONS__", "-D_MIPSEL", "-D_LANGUAGE_C", "-DLANGUAGE_C",
    "-fsyntax-only",
]


def main():
    version = os.environ.get("PSYQ_VER", "400")
    if version not in LIBS_BY_VERSION:
        raise SystemExit(f"Unsupported PSYQ_VER {version!r}; expected 400 or 470")

    source_root = "src" if version == "400" else "src/470"
    flags = FLAGS + ["-Iinclude", f"-Iinclude/og{version}"]
    srcs = []
    for lib in LIBS_BY_VERSION[version]:
        d = os.path.join(ROOT, source_root, lib)
        if os.path.isdir(d):
            for f in sorted(os.listdir(d)):
                if f.endswith(".c"):
                    srcs.append(os.path.join(source_root, lib, f))

    entries = [
        {"directory": ROOT, "file": s, "arguments": flags + [s]}
        for s in srcs
    ]

    out_path = os.path.join(ROOT, "compile_commands.json")
    with open(out_path, "w") as f:
        json.dump(entries, f, indent=2)


if __name__ == "__main__":
    main()
