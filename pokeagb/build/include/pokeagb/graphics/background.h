/**
 * @file
 * @brief Background graphics
 */

#ifndef POKEAGB_GRAPHICS_BACKGROUND_H_
#define POKEAGB_GRAPHICS_BACKGROUND_H_

#include "../types.h"

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160

struct BgConfig {
	u16 bgid : 2;
	u16 character_base : 2;
	u16 map_base : 5;
	u16 size : 2;
	u16 palette : 1;
	u16 priority : 2;
	u16 b_padding : 2; // bit field padding
	u16 padding;
};

struct BgConfig2 {
    u16 target_tile;
	u16 padding;
    u8 *tilemap;
    u32 x;
    u32 y;
};

struct TileMapBlock4BPP {
    u16 tile_offset : 8;
    u16 disable : 2; // not sure, could possible be part of tile offset
    u16 h_flip : 1;
    u16 v_flip : 1;
    u16 pal_slot : 4;
};

/**
 * @address{BPRE,030008E8}
 */
extern struct BgConfig2 bg_config2[4];

/**
 * @address{BPRE,08001618}
 */
POKEAGB_EXTERN void gpu_tile_bg_drop_all_sets(u8);

/**
 * @address{BPRE,080F67B8}
 */
POKEAGB_EXTERN void tilemaps_sync(void);

/**
 * @address{BPRE,0812D594}
 */
POKEAGB_EXTERN void bg_positions_reset(void);

/**
 * @address{BPRE,080F4E24}
 */
POKEAGB_EXTERN void callback_clear_and_init(void);

/**
 * @address{BPRE,08001FD4}
 */
POKEAGB_EXTERN void bgid_nullify_tilemap(u8);

/**
 * @address{BPRE,080017D0}
 */
POKEAGB_EXTERN u16 gpu_copy_to_tileset(u8 layer, const void* tiles, u16 size, u16 offset);

/**
 * @address{BPRE,08002040}
 */
POKEAGB_EXTERN void gpu_copy_tilemap(u8 layer, const void* map, u16 size_or_null, u16 offset);

/**
 * @address{BPRE,080020BC}
 */
POKEAGB_EXTERN void bgid_send_tilemap(u8 layer);

/**
 * @address{BPRE,08001FA0}
 */
POKEAGB_EXTERN void bgid_set_tilemap(u8 layer, u8* space);

/**
 * @address{BPRE,08001658}
 */
POKEAGB_EXTERN void bg_vram_setup(u8 mode, const struct BgConfig* config, u8 layers);

/**
 * @address{BPRE,08001658}
 */
POKEAGB_EXTERN DEPRECATED void bg_vram_set(u8 mode, u32 *setup_array, u8 array_size);

/**
 * @address{BPRE,080F6878}
 */
POKEAGB_EXTERN void* decompress_with_fallback_maybe(u8 layer,
                                                    u8* tiles,
                                                    u16 size,
                                                    u16 offset,
                                                    u8 mode);

/**
 * @address{BPRE,080019BC}
 */
POKEAGB_EXTERN void gpu_sync_bg_show(u8 layer);

/**
 * @address{BPRE,080019D0}
 */
POKEAGB_EXTERN void gpu_sync_bg_hide(u8 layer);

/**
 * @address{BPRE,08007320}
 */
POKEAGB_EXTERN void gpu_sprites_upload(void);

/**
 * @address{BPRE,08007610}
 */
POKEAGB_EXTERN void copy_queue_process(void);

/**
 * @address{BPRE,080563F0}
 */
POKEAGB_EXTERN void overworld_free_bgmaps(void);

/**
 * @address{BPRE,08002DE8}
 */
POKEAGB_EXTERN void textbox_something(void);

/**
 * @address{BPRE,08001D08}
 */
POKEAGB_EXTERN void bgid_mod_y_offset(u8 bgid, s32 delta, u8 dir);

/**
 * @address{BPRE,08001B90}
 */
POKEAGB_EXTERN void bgid_mod_x_offset(u8 bgid, s32 delta, u8 dir);

struct REG_BGCNT {
	u16 priority : 2;
	u16 char_index : 2; // 0x6000000 + char_index * 0x4000
	u16 padding : 2;
	u16 mosiac : 1;
	u16 color : 1; // 256 or 16
	u16 map_index : 5;
	u16 screen_over : 1;
	u16 size : 2;
	/*
	For "text" backgrounds:
	  00 : 256x256 (32x32 tiles)
	  01 : 512x256 (64x32 tiles)
	  10 : 256x512 (32x64 tiles)
	  11 : 512x512 (64x64 tiles)

	  For rotational backgrounds:
	  00 : 128x128 (16x16 tiles)
	  01 : 256x256 (32x32 tiles)
	  10 : 512x512 (64x64 tiles)
	  11 : 1024x1024 (128x128 tiles)

	*/
};

/**
 * BGCNT
 *
 * @address{BPRE,04000008}
 */
extern struct REG_BGCNT BG_CNT[4];

/**
 * @address{BPRE,080F67A4}
 */
POKEAGB_EXTERN void bgid_mark_for_sync(u8 bgid);

/**
 * BG Rotscale maybe
 * @address{BPRE,08001E80}
 */
POKEAGB_EXTERN void rot_scale_bg(u8 bgid, u32 xpos, u32 ypos, u16 x_pos, u16 y_pos, u16 delta_x, u16 delta_y, u8 dir_maybe);

/**
 * BG2 Rotscale
 * @address{BPRE,08001E80}
 */
POKEAGB_EXTERN void bg2_scale_bg(u8 bgid, u32 xposls8, u32 yposls8, u16 x_pos, u16 y_pos, u16 scale_x, u16 scale_y, u8 dir_maybe);

#endif /* POKEAGB_GRAPHICS_BACKGROUND_H_ */
