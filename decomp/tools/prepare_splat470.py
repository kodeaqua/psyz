#!/usr/bin/env python3
"""Export branch labels shared across Splat-generated translation units."""
from collections import defaultdict
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
ASM_DIR = ROOT / "asm/470/nonmatchings"
LABEL_RE = re.compile(r"\.L([0-9A-Fa-f]{8})")
DEFINITION_RE = re.compile(r"^\s*\.L([0-9A-Fa-f]{8}):\s*$")


def main():
    sources = sorted(ASM_DIR.rglob("*.s"))
    definitions = defaultdict(list)
    references = defaultdict(list)

    for source in sources:
        for line_number, line in enumerate(source.read_text().splitlines(), 1):
            definition = DEFINITION_RE.match(line)
            if definition:
                definitions[definition.group(1)].append(source)
                continue
            for label in LABEL_RE.findall(line):
                references[label].append(source)

    exported = {}
    for label, uses in references.items():
        defining_sources = definitions.get(label, [])
        if not defining_sources or not any(source not in defining_sources for source in uses):
            continue
        if len(defining_sources) != 1:
            raise SystemExit(f"ambiguous definition for .L{label}: {defining_sources}")
        exported[label] = defining_sources[0]

    aliases = {label: f"__psyq_470_local_{label.lower()}" for label in exported}
    changed = 0
    for source in sources:
        original = source.read_text()
        output = []
        for line in original.splitlines(keepends=True):
            definition = DEFINITION_RE.match(line.rstrip("\r\n"))
            if definition:
                label = definition.group(1)
                if label in aliases and exported[label] == source:
                    alias = aliases[label]
                    output.append(f".globl {alias}\n{alias}:\n")
            for label, alias in aliases.items():
                if exported[label] != source:
                    line = line.replace(f".L{label}", alias)
            output.append(line)
        updated = "".join(output)
        if updated != original:
            source.write_text(updated)
            changed += 1

    print(f"Exported {len(aliases)} cross-file branch labels in {changed} assembly files")


if __name__ == "__main__":
    main()
