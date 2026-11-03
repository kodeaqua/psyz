#include "common.h"

void SetDQB(s32 value) {
    __asm__ volatile("ctc2 %0, $28" : : "r"(value));
}
