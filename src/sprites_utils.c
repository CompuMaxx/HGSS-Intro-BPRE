

#include "headers/sprites_utils.h"
#include "headers/intro_master.h"

void load_sprite_pal(void* palette, u16 tag, bool compressed)
{
    struct SpritePalette pal = { (void *) palette, tag };
    if (compressed)
    {
        gpu_pal_decompress_alloc_tag_and_upload(&pal);
    } else {
        gpu_pal_obj_alloc_tag_and_apply(&pal);
    }
}


void obj_callback(struct Object *self) { return; }


void load_sprite(const struct OamData* oam_data, void* graphics, u8 sprite_num, 
        u16 pal_tag, u8 frame_amount, const struct Frame **animation_table)
{
    u16 graphics_tag = sprite_num | (sprite_num << 8);
    struct SpriteTiles sprite = { (void *) graphics, 
                                    32 * frame_amount << (2 * oam_data->size), 
                                    graphics_tag };
    struct Template template = { graphics_tag, pal_tag, oam_data,
                                    (const struct Frame **) animation_table, 
                                    &sprite, &rotscale_empty, obj_callback };   

    
    gpu_tile_obj_decompress_alloc_tag_and_upload(&sprite);
    
    intro_master->sprite_nums[sprite_num] = template_instanciate_forward_search(&template, 
            oam_data->x, oam_data->y, oam_data->priority);
}

void move_sprite(u8 sprite_num, s16 x, s16 y)
{
    sprite_num = intro_master->sprite_nums[sprite_num];
    objects[sprite_num].pos1.x += x;
    objects[sprite_num].pos1.y += y;
}

void change_sprite_frame(u8 sprite_num, s8 frame)
{
    u8 size;
    sprite_num = intro_master->sprite_nums[sprite_num];
    size = objects[sprite_num].final_oam.size;
    objects[sprite_num].final_oam.tile_num += (1 << (2 *size)) * frame;
}

void toggle_hflip(u8 sprite_num)
{
    sprite_num = intro_master->sprite_nums[sprite_num];
    objects[sprite_num].final_oam.h_flip ^= 1;
}

void toggle_vflip(u8 sprite_num)
{
    sprite_num = intro_master->sprite_nums[sprite_num];
    objects[sprite_num].final_oam.v_flip ^= 1;
}

void start_sprite_animation(u8 sprite_num, u8 anim_num)
{
    sprite_num = intro_master->sprite_nums[sprite_num];
    obj_anim_image_start(&objects[sprite_num], anim_num);
}

void delete_sprite(u8 sprite_num)
{
    sprite_num = intro_master->sprite_nums[sprite_num];
    obj_delete(&objects[sprite_num]);
}

void change_sprite_pal(u16 new_pal_tag, u8 sprite_num) 
{
    sprite_num = intro_master->sprite_nums[sprite_num];
    objects[sprite_num].final_oam.palette_num = gpu_pal_tags_index_of(new_pal_tag);
}