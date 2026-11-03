#include "common.h"

void SetLineF3(void* p) {
    register u32 pattern asm("v1") = 0x55555555;
    register u32 value asm("v0") = 5;
    ((u8*)p)[3] = value;
    value = 0x48;
    ((u8*)p)[7] = value;
    *(u32*)((u8*)p + 0x14) = pattern;
}
