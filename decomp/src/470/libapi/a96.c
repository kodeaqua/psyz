#include "common.h"

s32 GetCr(void) {
    s32 value;
    asm volatile("mfc0 %0, $13" : "=r"(value));
    return value;
}
