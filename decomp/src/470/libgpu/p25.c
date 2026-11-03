#include "common.h"

void SetTile16(void* p) {
    register u32 value asm("v0") = 2;
    ((u8*)p)[3] = value;
    value = 0x78;
    ((u8*)p)[7] = value;
}
