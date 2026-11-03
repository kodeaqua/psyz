#include "common.h"

void SetPolyF4(void* p) {
    register u32 value asm("v0") = 5;
    ((u8*)p)[3] = value;
    value = 0x28;
    ((u8*)p)[7] = value;
}
