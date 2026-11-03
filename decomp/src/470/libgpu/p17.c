#include "common.h"

void SetPolyFT4(void* p) {
    register u32 value asm("v0") = 9;
    ((u8*)p)[3] = value;
    value = 0x2C;
    ((u8*)p)[7] = value;
}
