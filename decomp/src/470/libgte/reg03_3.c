#include "common.h"

void SetVertex2(void* p) {
    __asm__ volatile("lwc2 $4, 0(%0)\n\t"
                     ".word 0xC8850004"
                     : : "r"(p) : "memory");
}
