#include "common.h"

void SetData32(s32 value) {
    __asm__ volatile("mtc2 %0, $30" : : "r"(value));
}
