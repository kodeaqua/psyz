#include "common.h"

void SetRii(s32 a, s32 b, s32 c) {
    __asm__ volatile("ctc2 %0, $0\n\t"
                     "ctc2 %1, $2\n\t"
                     "ctc2 %2, $4"
                     : : "r"(a), "r"(b), "r"(c));
}
