# PSY-Q decomp

This project aims to decompile PSY-Q SDKs by matching individual functions. It converts the SDK library object files to GNU-compatible objects and generates ELF binaries, allowing modern tooling to help with the decompilation process. The goal is for the decompiled code to match the generated binary exactly.

PSY-Q 4.0 is the established target. PSY-Q 4.7 now also has a reproducible binary-matching target and a Splat-generated source baseline. Most 4.7 functions still use assembly stubs, so full C decompilation remains ongoing.

This project allows to better understand the PSY-Q SDK internals better and to preserve the software for future development and archival purposes.

## Local build

Initialize the submodules and Python environment once:

```sh
git submodule update --init --recursive
python3 -m venv decomp/.venv
decomp/.venv/bin/pip install -r requirements.txt
```

Install the SDK and build either version locally. The build downloads the matching SDK and compiler assets as needed; install GNU MIPS little-endian binutils on the host first.

```sh
make -C decomp dependencies PSYQ_VER=400
make -C decomp -j"$(nproc)" PSYQ_VER=400 CPP=cpp all

make -C decomp dependencies PSYQ_VER=470
make -C decomp -j"$(nproc)" PSYQ_VER=470 all
```

On systems that provide `mipsel-linux-gnu-cpp`, the PSY-Q 4.0 `CPP=cpp` override can be omitted. These commands build and verify the exact expected binary using local tools; CI and containers are not required. The generated results are saved under `decomp/expected/400/` and `decomp/expected/470/`.

## Decompile new code

This follows the same decompilation rules from [sotn-decomp](https://github.com/Xeeynamo/sotn-decomp/wiki/Decompilation).

## How does this differ from Sozud' psy-q-decomp

The two decompilation projects follow different philosophies:

This PSY-Q decomp focuses on matching the GNU-converted libraries from the original SDK. It allows matching functions one by one and enables the use of modern tools and compilers.

Sozud's psy-q-decomp aims to match the original unconverted OBJ files using the original Win16/Win32 compilers. The challenge with Sozud's approach is that the entire object file needs to be decompiled and matched, which can be more difficult. But it will produce the original files.

Whenever possible, decompiled code from this repository will be upstreamed to [Sozud decomp](https://github.com/sozud/psy-q-decomp).

## Version targets

- PSY-Q 4.0 uses GCC 2.7.2 and remains the established decompilation target.
- PSY-Q 4.7 uses GCC 2.95.2. Its source baseline is generated with Splat; replacing assembly stubs with matching C implementations is incremental work.
- Each version has separate source, assembly, object, SDK include, and expected-output paths so builds can be run sequentially without overwriting the other version's artifacts.

## Contributing

Contributions are welcome! Please ensure that any code you submit matches the generated ELF binaries. When contributing, adhere to the guidelines provided in the sotn-decomp decompilation rules.

## Special thanks

Most of the decomp was ported from the incredible work of contributors from the [SOTN Decomp repo](https://github.com/Xeeynamo/sotn-decomp/tree/master/src/main/psxsdk).
