#include "common.h"

void SetDQA(s32 value) {
    __asm__ volatile("ctc2 %0, $27" : : "r"(value));
}
