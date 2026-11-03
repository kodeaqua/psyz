# Spec: PSY-Q 4.7 full decompilation migration

**Author:** Codex, from the user's direction to pursue full PSY-Q 4.7 support
**Date:** 2026-11-03
**Status:** Approved for staged implementation
**Reviewers:** User
**Related specs:** None

## Context

The root SDK setup already downloads PSY-Q 4.7 for homebrew builds, while PsyZ's exact-match decompilation currently targets PSY-Q 4.0. The decomp repository contains initial 4.7 symbols and Splat configuration, but the default Makefile, diff settings, compile command generator, and CI still select 4.0.

The decomp README records that prior 4.7 matching work was difficult because the compiler or compiler flags for versions after 4.0 were not known. A full migration therefore needs a reproducible 4.7 reference build and function-by-function binary matching. Keep the 4.0 baseline available while proving 4.7; do not claim completion from a version-number or config switch alone.

## Functional Requirements

- FR-1: The decomp build MUST select PSY-Q 4.7 inputs, symbols, sources, objects, and output names consistently when configured for version 470.
- FR-2: The decomp build MUST retain the PSY-Q 4.0 target during the migration so existing matching remains reproducible.
- FR-3: The build and diff tooling MUST fail clearly when required version-specific SDK inputs or toolchain support are missing; they MUST NOT silently fall back to 4.0.
- FR-4: The 4.7 target MUST cover the PSY-Q 4.7 library set selected by the decomp project, including any library required by PsyZ integration.
- FR-5: The 4.7 reconstructed ELF MUST match the GNU-converted PSY-Q 4.7 reference ELF byte-for-byte.
- FR-6: PsyZ and PS1 integration builds MUST consume the intended PSY-Q 4.7-compatible headers and libraries after the migration is complete.
- FR-7: Documentation and CI MUST identify and verify the active decomp target accurately.

## Non-Functional Requirements

### Reliability

- NFR-R1: A clean build MUST keep 4.0 and 4.7 generated artifacts in version-specific paths so parallel or sequential builds cannot mix objects.
- NFR-R2: Repeating the 4.7 reference and matching build from the same SDK and toolchain MUST produce the same ELF checksum.
- NFR-R3: The 4.0 target MUST remain buildable until the 4.7 acceptance criteria pass.

### Performance

- N/A — build duration is not part of the migration's correctness contract.

### Security, accessibility, and scalability

- N/A — this work changes build and decompilation inputs, not a runtime service or user interface.

## Acceptance Criteria

### AC-1: Reproducible 4.7 reference build (FR-1, FR-3, NFR-R2)

Given the verified PSY-Q 4.7 SDK archive and required conversion tools are available,
When the 4.7 decomp build runs from a clean state,
Then it produces a version-specific GNU-compatible reference ELF,
And a second clean run produces the same checksum.

### AC-2: Complete 4.7 binary match (FR-4, FR-5)

Given the selected PSY-Q 4.7 libraries and the decompiled/assembly sources,
When the 4.7 reconstructed ELF is linked,
Then its checksum matches the checksum of the 4.7 reference ELF.

### AC-3: Baseline preservation during migration (FR-2, NFR-R3)

Given the migration is not yet accepted,
When the 4.0 decomp build runs,
Then its existing version-specific output and checksum verification still work.

### AC-4: PsyZ integration uses 4.7 inputs (FR-6)

Given the 4.7 migration is accepted,
When the relevant PsyZ and PS1 integration targets build and run,
Then they use the 4.7-compatible SDK headers and libraries,
And the existing PsyZ API and rendering expectations remain satisfied.

### AC-5: CI and docs match the implementation (FR-7)

Given the final target is 4.7,
When CI runs the decomp verification and a contributor follows the setup docs,
Then CI verifies the 4.7 target,
And the docs name the verified PSY-Q version and required toolchain.

## Edge Cases and Error Scenarios

- EC-1: The 4.7 SDK archive is absent or fails its checksum -> stop with an explicit error; do not use 4.0 inputs.
- EC-2: The requested assembler/compiler compatibility mode is unknown -> stop before claiming binary matching and report the unresolved toolchain requirement.
- EC-3: A 4.7 library is absent from the selected SDK -> identify the library and fail the reference build rather than silently omitting it.
- EC-4: A build directory contains objects from another PSY-Q version -> use isolated versioned paths or clean them before linking.
- EC-5: The 4.7 source set has unmatched functions -> report the remaining mismatch; do not mark the migration complete.

## API Contracts

- N/A — no runtime API contract changes are included in this migration.

## Data Models

- N/A — no persistent data model changes are included in this migration.

## Out of Scope

- OS-1: Adding unrelated PSY-Q APIs or changing PsyZ runtime behavior — these require separate work and acceptance criteria.
- OS-2: Dropping PSY-Q 4.0 before the full 4.7 acceptance criteria pass — the old target is the migration reference until then.
- OS-3: Adding support for PSY-Q versions other than 4.0 and 4.7 — outside this migration.
