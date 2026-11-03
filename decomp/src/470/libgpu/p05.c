#include "common.h"

s32 IsEndPrim(void* p) {
    register u32 mask asm("v1") = 0x00FFFFFF;
    register u32 value asm("v0") = *(u32*)p;
    value &= mask;
    value ^= mask;
    return value < 1;
}
