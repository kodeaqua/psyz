#include "common.h"

s32 GetSr(void) {
    s32 value;
    asm volatile("mfc0 %0, $12" : "=r"(value));
    return value;
}
