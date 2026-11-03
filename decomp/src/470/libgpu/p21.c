#include "common.h"

void SetSprt16(void* p) {
    register u32 value asm("v0") = 3;
    ((u8*)p)[3] = value;
    value = 0x7C;
    ((u8*)p)[7] = value;
}
