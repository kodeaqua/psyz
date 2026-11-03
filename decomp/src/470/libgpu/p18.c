#include "common.h"

void SetPolyG4(void* p) {
    register u32 value asm("v0") = 8;
    ((u8*)p)[3] = value;
    value = 0x38;
    ((u8*)p)[7] = value;
}
