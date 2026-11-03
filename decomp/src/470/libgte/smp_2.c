#include "common.h"

void DpqColor(void* v0, s32 p, void* v1) {
    __asm__ volatile("lwc2 $6, 0(%0)\n\t"
                     "mtc2 %1, $8\n\t"
                     "nop\n\t"
                     ".word 0x4A780010\n\t"
                     "swc2 $22, 0(%2)"
                     : : "r"(v0), "r"(p), "r"(v1) : "memory");
}
