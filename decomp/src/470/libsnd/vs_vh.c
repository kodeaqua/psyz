#include "common.h"

INCLUDE_ASM("asm/470/nonmatchings/libsnd/vs_vh", SsVabOpenHeadSticky);

INCLUDE_ASM("asm/470/nonmatchings/libsnd/vs_vh", SsVabFakeHead);

s32 func_80113278(s32 unused, s32 value) {
    return value;
}

INCLUDE_ASM("asm/470/nonmatchings/libsnd/vs_vh", _SsVabOpenHeadWithMode);
