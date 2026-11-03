#include "common.h"

void* NextPrim(void* p) {
    register u32 mask asm("v1") = 0x00FFFFFF;
    register u32 value asm("v0") = *(u32*)p;
    value &= mask;
    value |= 0x80000000;
    return (void*)value;
}
