#include "common.h"

void SetLineG2(void* p) {
    register u32 value asm("v0") = 4;
    ((u8*)p)[3] = value;
    value = 0x50;
    ((u8*)p)[7] = value;
}
