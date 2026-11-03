#include "common.h"
#include <og/libcd.h>

extern CdlLOC CD_pos;

CdlLOC* CdLastPos(void) {
    return &CD_pos;
}
