#include "common.h"

void SetSXSYfifo(s32 sxy0, s32 sxy1, s32 sxy2) {
    __asm__ volatile("mtc2 %0, $12\n\t"
                     "mtc2 %1, $13\n\t"
                     "mtc2 %2, $14"
                     : : "r"(sxy0), "r"(sxy1), "r"(sxy2));
}
