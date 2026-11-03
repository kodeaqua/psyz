#include "common.h"

void SetIR0(s32 value) {
    __asm__ volatile("mtc2 %0, $8" : : "r"(value));
}
