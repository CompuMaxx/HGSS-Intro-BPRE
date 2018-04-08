

#ifndef IMPORTANT_H
#define IMPORTANT_H

#include <pokeagb/pokeagb.h>
#include "intro_master.h"
#include "bg_utils.h"
#include "sprites_utils.h"
#include "gba_io_regs.h"

extern __attribute__((long_call))void play_song(u16 song_num);
extern __attribute__((long_call))void fade_song();
extern __attribute__((long_call))void play_cry(u16 pkmn_num);


static inline void fadescreen()
{
    fade_screen(0xFFFFFFFF, 0x0, 0x0, 0x10, 0x0000); 
}

static inline void unfadescreen()
{
    fade_screen(0xFFFFFFFF, 0x0, 0x10, 0x0, 0x7FFF); 
}

static inline void fadescreen_white()
{
    fade_screen(0xFFFFFFFF, 0x0, 0x0, 0x10, 0x7FFF);
}


static inline bool key_down(u16 k) 
{
    return super.buttons_new_remapped & k;
}

#endif /* IMPORTANT_H */

