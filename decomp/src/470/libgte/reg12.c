#include "common.h"

void SetGeomOffset(s32 x, s32 y) {
    __asm__ volatile("sll %0, %0, 16\n\t"
                     "sll %1, %1, 16\n\t"
                     "ctc2 %0, $24\n\t"
                     "ctc2 %1, $25"
                     : "+r"(x), "+r"(y));
}
