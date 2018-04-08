
#ifndef BG_UTILS_H
#define BG_UTILS_H

#include <pokeagb/pokeagb.h>

struct DISPCNT {
    u16 bg_mode: 3;
    u16 reserved: 1;
    u16 display_frame: 1;
    u16 hblank_interval: 1;
    u16 obj_vram_map: 1;
    u16 forced_blank: 1;
    u16 display_bg0: 1;
    u16 display_bg1: 1;
    u16 display_bg2: 1;
    u16 display_bg3: 1;
    u16 display_obj: 1;
    u16 display_window0: 1;
    u16 display_window1: 1;
    u16 display_obj_window: 1;
};
 
typedef union {
    struct DISPCNT st;
    u16 casted_u16;
} cast_dispcnt;


struct bg_hv_ofs {
    u16 x: 9;
    u16 pad1: 7;
    u16 y: 9;
    u16 pad2: 7;
};
 
void set_bg_config();
void set_bg_config_1();
void set_bg_config_2();
void clear_bgs();
void restart_bgs();
void load_bg_raw(u8 bg_num, void* tilemap);
void load_bg_data(u8 bg_num, void* tileset, void* tilemap);
void load_bg_data_1(u8 bg_num, void* tileset, void* tilemap);
void load_bg_data_2(u8 bg_num, void* tileset, void* tilemap);
void load_bg_raw_1(u8 bg_num, void* tilemap);
void load_bg_pal(u8 pal_num, void * palette, bool is_compressed);
void move_bg(u8 bg_num, s16 x, s16 y);


static inline void toggle_bg_displayed(u8 bg_num)
{
    REG_DISPCNT ^= (1 << (bg_num + 8));
}


#endif /* BG_UTILS_H */

