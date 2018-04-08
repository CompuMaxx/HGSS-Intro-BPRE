


#ifndef SPRITES_UTILS_H
#define SPRITES_UTILS_H

#include <pokeagb/pokeagb.h>

void load_sprite_pal(void* palette, u16 tag, bool compressed);
void load_sprite(const struct OamData* oam_data, void* graphics, u8 sprite_num, 
        u16 pal_tag, u8 frame_amount, const struct Frame **animation_table);
void move_sprite(u8 sprite_num, s16 x, s16 y);
void change_sprite_frame(u8 sprite_num, s8 frame);
void toggle_hflip(u8 sprite_num);
void toggle_vflip(u8 sprite_num);
void start_sprite_animation(u8 sprite_num, u8 anim_num);
void delete_sprite(u8 sprite_num);
void change_sprite_pal(u16 new_pal_tag, u8 sprite_num);


#define SIZE_64x64 3
#define SIZE_32x32 2
#define SIZE_16x16 1
#define SIZE_8x8 0

#define FRAME_64x64 64
#define FRAME_32x32 16
#define FRAME_16x16 4
#define FRAME_8x8 1




#endif /* SPRITES_UTILS_H */

