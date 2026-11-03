#include "common.h"

void SetPolyG3(void* p) {
    register u32 value asm("v0") = 6;
    ((u8*)p)[3] = value;
    value = 0x30;
    ((u8*)p)[7] = value;
}
