#include "common.h"

void SetDrawStp(void* p, s32 pbw) {
    ((u8*)p)[3] = 2;
    ((u32*)p)[1] = 0xE6000000 | (pbw ? 1 : 0);
    ((u32*)p)[2] = 0;
}
