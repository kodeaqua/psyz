#include "common.h"

void SetSZfifo3(s32 a, s32 b, s32 c) {
    __asm__ volatile("mtc2 %0, $17\n\t"
                     "mtc2 %1, $18\n\t"
                     "mtc2 %2, $19"
                     : : "r"(a), "r"(b), "r"(c));
}
