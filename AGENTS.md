# Agent instructions

## Project map

- PsyZ is a C compatibility library that replaces the PSY-Q runtime for native ports of PlayStation 1 games. It is not a general PS1 emulator.
- `psyz/src/psyz/` contains platform-independent PS1 API and hardware behavior. `psyz/src/platform/` contains desktop and SDL3 backends; `psyz/src/psp/` is the native PSP backend.
- `psyz/include/` contains PSY-Q-compatible headers and the public PsyZ extensions under `psyz/include/psyz/`.
- `decomp/src/` is a separate PSY-Q 4.0 decompilation project whose code is also used by PsyZ. Its goal includes matching original library binaries.
- `psyz/tests/` contains the PsyZ tests and reference images. `ztest/` provides the cross-target test runner. `samples/` has integration examples; `web/` builds the WebAssembly sample gallery.

## Build and verification

- `make -C psyz` builds the native static library. The CMake source selection and platform configuration live in `psyz/CMakeLists.txt`.
- `make -C psyz test` builds and runs the native test suite. Use the ztest runner's filters to focus on the affected subsystem when practical.
- Root `make -j` prepares PSY-Q SDK headers and libraries for projects that build for both PS1 and PsyZ; it is not the normal PsyZ library build.
- Initialize required Git submodules recursively before building targets that depend on them.
- Tests compare rendered output against files in `psyz/tests/expected/`. Change reference images only when the intended behavior changes and the new output has been reviewed.

## Compatibility and implementation guidance

- Read `PORTING_GUIDE.md` before changing PSY-Q compatibility behavior. For game code, include `<psyz.h>` before PSY-Q-compatible headers as documented there.
- Use `OT_TYPE` for ordering tables and `O_TAG` for custom GPU primitive tags. Never store pointers in fixed-width `s32` or `u32` values; avoid hardcoded PS1 memory addresses.
- Keep shared PS1 behavior in `psyz/src/psyz/`. Put operating-system or device-specific work in the matching backend, and update CMake source selection when adding backend files.
- When changing a public PsyZ API, check its declaration, implementation, and support across the relevant backends. Public extensions use the `Psyz_` prefix.
- Treat `decomp/` changes as binary-matching work: follow its existing decompilation conventions and verify against the matching build when that is part of the task.

## Repository conventions

- Follow the existing C11/C++17 conventions and `.clang-format` style.
- Keep changes scoped to the requested behavior. Avoid editing submodule contents, generated assets, or expected test images unless the task requires it.
- For platform changes, inspect the corresponding sample and CI workflow so the target remains buildable in the project's supported configuration.

## Commits

- Use Conventional Commit subjects: `<type>(optional scope): <short imperative summary>`; choose the type based on the change (`feat`, `fix`, `docs`, `refactor`, `test`, `build`, `ci`, or `chore`).
- Keep the subject concise and explain the reason in the body when the change needs context. For example: `docs: add project guidance for coding agents`.
