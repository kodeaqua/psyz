#include "common.h"

void SetLineG4(void* p) {
    register u32 pattern asm("v1") = 0x55555555;
    register u32 value asm("v0") = 9;
    ((u8*)p)[3] = value;
    value = 0x5C;
    ((u8*)p)[7] = value;
    *(u32*)((u8*)p + 0x24) = pattern;
    ((u8*)p)[0x17] = 0;
    ((u8*)p)[0x1F] = 0;
}
