#include "common.h"

s32 NormalClipS(void) {
    register s32 value asm("v0");
    __asm__ volatile(".word 0x4B400006\n\t"
                     "mfc2 %0, $24"
                     : "=r"(value));
    return value;
}
