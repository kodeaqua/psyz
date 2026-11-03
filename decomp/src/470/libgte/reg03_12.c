#include "common.h"

void SetMAC123(s32 a, s32 b, s32 c) {
    __asm__ volatile("mtc2 %0, $25\n\t"
                     "mtc2 %1, $26\n\t"
                     "mtc2 %2, $27"
                     : : "r"(a), "r"(b), "r"(c));
}
