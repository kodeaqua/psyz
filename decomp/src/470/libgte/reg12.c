#include "common.h"
#include <og/libgte.h>

void SetGeomOffset(long ofx, long ofy) {
    __asm__ volatile("sll %0, %0, 16\n\t"
                     "sll %1, %1, 16\n\t"
                     "ctc2 %0, $24\n\t"
                     "ctc2 %1, $25"
                     : "+r"(ofx), "+r"(ofy));
}
