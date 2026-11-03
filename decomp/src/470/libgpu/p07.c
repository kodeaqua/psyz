#include "common.h"

void AddPrims(void* ot, void* p0, void* p1) {
    register u32 addrMask asm("a3") = 0x00FFFFFF;
    register u32 lenMask asm("t0") = 0xFF000000;
    register u32 primTag asm("v1") = *(u32*)p1;
    register u32 otTag asm("v0") = *(u32*)ot;
    *(u32*)p1 = (primTag & lenMask) | (otTag & addrMask);
    *(u32*)ot = (*(u32*)ot & lenMask) | ((u32)p0 & addrMask);
}
