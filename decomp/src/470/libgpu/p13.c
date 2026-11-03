#include "common.h"

void SetPolyFT3(void* p) {
    register u32 value asm("v0") = 7;
    ((u8*)p)[3] = value;
    value = 0x24;
    ((u8*)p)[7] = value;
}
