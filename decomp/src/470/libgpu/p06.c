#include "common.h"

void AddPrim(void* ot, void* p) {
    register u32 addrMask asm("a2") = 0x00FFFFFF;
    register u32 lenMask asm("a3") = 0xFF000000;
    register u32 primTag asm("v1") = *(u32*)p;
    register u32 otTag asm("v0") = *(u32*)ot;
    *(u32*)p = (primTag & lenMask) | (otTag & addrMask);
    *(u32*)ot = (*(u32*)ot & lenMask) | ((u32)p & addrMask);
}
