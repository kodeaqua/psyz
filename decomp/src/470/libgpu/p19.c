#include "common.h"

void SetPolyGT4(void* p) {
    register u32 value asm("v0") = 12;
    ((u8*)p)[3] = value;
    value = 0x3C;
    ((u8*)p)[7] = value;
}
