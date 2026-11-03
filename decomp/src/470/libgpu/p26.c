#include "common.h"

void SetTile(void* p) {
    register u32 value asm("v0") = 3;
    ((u8*)p)[3] = value;
    value = 0x60;
    ((u8*)p)[7] = value;
}
