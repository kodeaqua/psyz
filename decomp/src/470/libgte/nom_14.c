#include "common.h"

void NormalColorDpq_nom(void* v0, void* v1, s32 p) {
    __asm__ volatile("lwc2 $0, 0(%0)\n\t"
                     "lwc2 $1, 4(%0)\n\t"
                     ".word 0xC8A60000\n\t"
                     "mtc2 %2, $8\n\t"
                     "nop\n\t"
                     ".word 0x4AE80413"
                     : : "r"(v0), "r"(v1), "r"(p) : "memory");
}
