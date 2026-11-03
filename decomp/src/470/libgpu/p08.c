#include "common.h"

void CatPrim(void* p0, void* p1) {
    register u32 addrMask asm("a2") = 0x00FFFFFF;
    register u32 lenMask asm("v1") = 0xFF000000;
    register u32 tag asm("v0") = *(u32*)p0;
    *(u32*)p0 = (tag & lenMask) | ((u32)p1 & addrMask);
}
