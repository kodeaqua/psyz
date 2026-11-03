#include "common.h"

void SetLineF2(void* p) {
    register u32 value asm("v0") = 3;
    ((u8*)p)[3] = value;
    value = 0x40;
    ((u8*)p)[7] = value;
}
