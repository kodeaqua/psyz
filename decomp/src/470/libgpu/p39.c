#include "common.h"

void SetPriority(void* p, s32 dfe, s32 pbw) {
    ((u8*)p)[3] = 2;
    ((u32*)p)[1] = 0xE6000000 | (dfe ? 0x2 : 0) | (pbw ? 0x1 : 0);
    ((u32*)p)[2] = 0;
}
