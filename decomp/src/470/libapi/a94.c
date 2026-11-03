#include "common.h"

s32 GetGp(void) {
    register s32 gp_value asm("gp");
    return gp_value;
}
