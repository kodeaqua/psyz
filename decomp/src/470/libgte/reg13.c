#include "common.h"

void SetGeomScreen(s32 value) {
    __asm__ volatile("ctc2 %0, $26" : : "r"(value));
}
