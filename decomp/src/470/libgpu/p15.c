#include "common.h"

void SetPolyGT3(void* p) {
    register u32 value asm("v0") = 9;
    ((u8*)p)[3] = value;
    value = 0x34;
    ((u8*)p)[7] = value;
}
