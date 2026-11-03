#include "common.h"
#include <og/libsnd.h>

typedef struct {
    s32 tickMode;
    s32 manualTick;
    void (*tickCallback)(void);
} SndSeqTickEnv;

extern SndSeqTickEnv _snd_seq_tick_env;

int SsSetTickCallback(void (*cb)()) {
    register void (**address)(void) asm("v1") = &_snd_seq_tick_env.tickCallback;
    void (*previous)(void);

    /* Keep the tick callback address in v1 for both accesses. */
    __asm__ volatile("" : "+r"(address));
    previous = *address;

    if (cb != previous) {
        *address = cb;
    }
    return (int)previous;
}
