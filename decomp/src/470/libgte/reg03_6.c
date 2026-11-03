#include "common.h"

void SetIR123(s32 a, s32 b, s32 c) {
    __asm__ volatile("mtc2 %0, $9\n\t"
                     "mtc2 %1, $10\n\t"
                     "mtc2 %2, $11"
                     : : "r"(a), "r"(b), "r"(c));
}
