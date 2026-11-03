#include "common.h"
#include <og/libgte.h>

void SetFarColor(long rfc, long gfc, long bfc) {
    __asm__ volatile("sll %0, %0, 4\n\t"
                     "sll %1, %1, 4\n\t"
                     "sll %2, %2, 4\n\t"
                     "ctc2 %0, $21\n\t"
                     "ctc2 %1, $22\n\t"
                     "ctc2 %2, $23"
                     : "+r"(rfc), "+r"(gfc), "+r"(bfc));
}
