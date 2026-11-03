#include "common.h"
#include <og/libgte.h>

void SetGeomScreen(long h) {
    __asm__ volatile("ctc2 %0, $26" : : "r"(h));
}
