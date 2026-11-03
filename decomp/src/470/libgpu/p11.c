#include "common.h"

void SetShadeTex(void* p, s32 tge) {
    const volatile u8* source = (const volatile u8*)p;
    u8* dest = (u8*)p;
    u8 codeValue;
    if (tge) {
        codeValue = source[7] | 1;
    } else {
        codeValue = source[7] & (u8)~1;
    }
    dest[7] = codeValue;
}
