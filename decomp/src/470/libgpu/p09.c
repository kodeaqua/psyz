#include "common.h"

void TermPrim(void* p) {
    register u32 value asm("v0") = *(u32*)p;
    register u32 mask asm("v1") = 0x00FFFFFF;
    value |= mask;
    *(u32*)p = value;
}
