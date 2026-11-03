#include "common.h"

void SetSprt(void* p) {
    register u32 value asm("v0") = 4;
    ((u8*)p)[3] = value;
    value = 0x64;
    ((u8*)p)[7] = value;
}
