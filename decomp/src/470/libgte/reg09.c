#include "common.h"

s32 ReadGeomScreen(void) {
    register s32 value asm("v0");
    __asm__ volatile("cfc2 %0, $26" : "=r"(value));
    return value;
}
