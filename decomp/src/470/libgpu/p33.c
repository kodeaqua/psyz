#include "common.h"

void SetDrawTPage(void* p, s32 dfe, s32 dtd, s32 tpage) {
    ((u8*)p)[3] = 1;
    ((u32*)p)[1] = 0xE1000000 | (dtd ? 0x200 : 0) | (dfe ? 0x400 : 0) | (tpage & 0x9FF);
}
