#include "common.h"

void SetPolyF3(void* p) {
    register u32 value asm("v0") = 4;
    ((u8*)p)[3] = value;
    value = 0x20;
    ((u8*)p)[7] = value;
}
