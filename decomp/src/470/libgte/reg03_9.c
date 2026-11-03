#include "common.h"

void SetSZfifo4(s32 a, s32 b, s32 c, s32 d) {
    __asm__ volatile("mtc2 %0, $16\n\t"
                     "mtc2 %1, $17\n\t"
                     "mtc2 %2, $18\n\t"
                     "mtc2 %3, $19"
                     : : "r"(a), "r"(b), "r"(c), "r"(d));
}
