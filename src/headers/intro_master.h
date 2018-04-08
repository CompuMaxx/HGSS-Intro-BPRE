

#ifndef TIME_H
#define TIME_H

#include <pokeagb/types.h>
#include "bg_utils.h"

#define SECOND 60

struct IntroSt {
    u32 timer;
    u8 vars[10];
    struct bg_hv_ofs (*bg_hv_mirror)[4];
    u8 sprite_nums[128];
};

extern struct IntroSt *intro_master;

volatile struct __writeonly bg_hv_ofs BG_HV_OFS[4];


static inline u32 get_time(){ return intro_master->timer; }

static inline void inc_timer(){ ++(intro_master->timer); }

static inline void set_timer(u32 value){ intro_master->timer = value; }

static inline u8 get_var(u8 var_num){ return intro_master->vars[var_num]; }

static inline void set_var(u8 var_num, u8 value) 
{ 
    intro_master->vars[var_num] = value;
}

void init_intro_master(struct IntroSt ** pointer);
void free_intro_master(struct IntroSt ** pointer);
void write_bg_positions(struct IntroSt *self);

void update_everything();
void end_intro();
void not_main();
void vblank_function();

#endif /* TIME_H */

