#include "common.h"

void SetSemiTrans(void* p, s32 abe) {
    const volatile u8* source = (const volatile u8*)p;
    u8* dest = (u8*)p;
    u8 codeValue;
    if (abe) {
        codeValue = source[7] | 2;
    } else {
        codeValue = source[7] & (u8)~2;
    }
    dest[7] = codeValue;
}
