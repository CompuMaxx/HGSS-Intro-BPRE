

#include "headers/bg_utils.h"
#include "headers/intro_master.h"
#include "headers/gba_io_regs.h"

volatile struct REG_BGCNT (*reg_bg_cnt)[4] = (struct REG_BGCNT (*)[4]) 0x04000008;

void set_bg_config()
{
    u8 i;
    
    struct REG_BGCNT bg_cnt[4] = { 
        { //BG0
            .priority= 0,
            .char_index = 3, 	// 0x600C000
            .padding = 0,
            .mosiac = 0,
            .color = 0, 		// 16 colors
            .map_index = 27, 	// 0x600D800
            .screen_over = 0,
            .size = 0,		 	// 256x256
        },  { //BG1
            .priority= 3,
            .char_index = 0, 	// 0x6000000
            .padding = 0,
            .mosiac = 0,
            .color = 1, 		// 256 colors
            .map_index = 28, 	// 0x600E000
            .screen_over = 0,
            .size = 0,		 	// 256x256
        },  { //BG2
            .priority= 2,
            .char_index = 2, 	// 0x6008000
            .padding = 0,
            .mosiac = 0,
            .color = 0, 		// 16 colors
            .map_index = 20, 	// 0x600A000
            .screen_over = 0,
            .size = 0,		 	// 256x256
        },  { //BG3
            .priority= 1,
            .char_index = 1, 	// 0x6004000
            .padding = 0,
            .mosiac = 0,
            .color = 0, 		// 16 colors
            .map_index = 12, 	// 0x6006000
            .screen_over = 0,
            .size = 0,		 	// 256x256
        }
    };
    cast_dispcnt dispcnt = { .st = { 
            .bg_mode =  0,
            .reserved = 0,
            .display_frame = 0,
            .hblank_interval = 0,
            .obj_vram_map = 1,
            .forced_blank = 0,
            .display_bg0 = 1,
            .display_bg1 = 1,
            .display_bg2 = 1,
            .display_bg3 = 1,
            .display_obj = 1,
            .display_window0 = 0,
            .display_window1 = 0,
            .display_obj_window = 0
        }
    };


    clear_bgs();
    
    REG_DISPCNT = dispcnt.casted_u16;
    for (i = 0; i < 4; i++) 
    {
        (*reg_bg_cnt)[i] = bg_cnt[i];
    }
    write_bg_positions(intro_master);
}

void set_bg_config_1()
{
   u8 i;
   
    struct REG_BGCNT bg_cnt[4] = { 
        { //BG0
            .priority= 0,
            .char_index = 0, 	// 0x6000000
            .padding = 0,
            .mosiac = 0,
            .color = 0, 		// 16 colors
            .map_index = 3, 	// 0x6001800
            .screen_over = 0,
            .size = 0,		 	// 256x256
        },  { //BG1
            .priority= 1,
            .char_index = 1, 	// 0x6004000
            .padding = 0,
			.mosiac = 0,
            .color = 0, 		// 16 colors
            .map_index = 12, 	// 0x6006000
            .screen_over = 0,
            .size = 3,		 	// 512x512
        },  { //BG2
            .priority= 2,
            .char_index = 2, 	// 0x6008000
            .padding = 0,
            .mosiac = 0,
            .color = 1, 		// 256 colors
            .map_index = 4, 	// 0x6002000
            .screen_over = 0,
            .size = 3,		 	// 512x512
        },  { //BG3
            .priority= 3,
            .char_index = 0, 	// 0x6000000
            .padding = 0,
            .mosiac = 0,
            .color = 0, 		// 16 colors
            .map_index = 31, 	// 0x600F800
            .screen_over = 0,
            .size = 0,		 	// 256x256
		}
	};
		
    cast_dispcnt dispcnt = { .st = { 
            .bg_mode =  0,
            .reserved = 0,
            .display_frame = 0,
            .hblank_interval = 0,
            .obj_vram_map = 1,
            .forced_blank = 0,
            .display_bg0 = 1,
            .display_bg1 = 1,
            .display_bg2 = 1,
            .display_bg3 = 1,
            .display_obj = 1,
            .display_window0 = 0,
            .display_window1 = 0,
            .display_obj_window = 0
        }
    };
    
    REG_DISPCNT = dispcnt.casted_u16;
    for (i = 0; i < 4; i++) 
    {
        (*reg_bg_cnt)[i] = bg_cnt[i];
    }

}

void set_bg_config_2()
{
   u8 i;
   
    struct REG_BGCNT bg_cnt[4] = { 
        { //BG0
            .priority= 0,
            .char_index = 0, 	// 0x6000000
            .padding = 0,
            .mosiac = 0,
            .color = 0, 		// 16 colors
            .map_index = 6, 	// 0x6003000
            .screen_over = 0,
            .size = 1,		 	// 512x256
        },  { //BG1
            .priority= 1,
            .char_index = 1, 	// 0x6004000
            .padding = 0,
			.mosiac = 0,
            .color = 0, 		// 16 colors
            .map_index = 14, 	// 0x6007000
            .screen_over = 0,
            .size = 1,		 	// 512x256
        },  { //BG2
            .priority= 2,
            .char_index = 2, 	// 0x6008000
            .padding = 0,
            .mosiac = 0,
            .color = 0, 		// 16 colors
            .map_index = 22, 	// 0x600B000
            .screen_over = 0,
            .size = 1,		 	// 512x256
        },  { //BG3
            .priority= 3,
            .char_index = 3, 	// 0x600C000
            .padding = 0,
            .mosiac = 0,
            .color = 0, 		// 16 colors
            .map_index = 30, 	// 0x600F000
            .screen_over = 0,
            .size = 1,		 	// 512x256
		}
	};
		
    cast_dispcnt dispcnt = { .st = { 
            .bg_mode =  0,
            .reserved = 0,
            .display_frame = 0,
            .hblank_interval = 0,
            .obj_vram_map = 1,
            .forced_blank = 0,
            .display_bg0 = 1,
            .display_bg1 = 1,
            .display_bg2 = 1,
            .display_bg3 = 1,
            .display_obj = 1,
            .display_window0 = 0,
            .display_window1 = 0,
            .display_obj_window = 0
        }
    };
    
    REG_DISPCNT = dispcnt.casted_u16;
    for (i = 0; i < 4; i++) 
    {
        (*reg_bg_cnt)[i] = bg_cnt[i];
    }

}

void restart_bgs()
{
	BG0HOFF = 0;
	BG1HOFF = 0;
	BG2HOFF = 0;
	BG3HOFF = 0;
	BG0VOFF = 0;
	BG1VOFF = 0;
	BG2VOFF = 0;
	BG3VOFF = 0;
}

void clear_bgs()
{
    memset((void *) 0x6000000, 0, 0x10000);
}

void move_bg(u8 bg, s16 x, s16 y)
{
    (*intro_master->bg_hv_mirror)[bg].x += x;
    (*intro_master->bg_hv_mirror)[bg].y += y;
    write_bg_positions(intro_master);
}

void load_bg_data(u8 bg_num, void* tileset, void* tilemap)
{
	if (bg_num == 0) {
		lz77UnCompVram(tilemap, (void *) 0x600D800);
		lz77UnCompVram(tileset, (void *) 0x600C000);
	}else if (bg_num == 1) {
		lz77UnCompVram(tilemap, (void *) 0x600E000);
		lz77UnCompVram(tileset, (void *) 0x6000000);		
	}else if (bg_num == 2) {
		lz77UnCompVram(tilemap, (void *) 0x600A000);
		lz77UnCompVram(tileset, (void *) 0x6008000);		
	}else if (bg_num == 3) {
		lz77UnCompVram(tilemap, (void *) 0x6006000);
		lz77UnCompVram(tileset, (void *) 0x6004000);		
	}
}

void load_bg_raw(u8 bg_num, void* tilemap)
{
	if (bg_num == 0) {
		lz77UnCompVram(tilemap, (void *) 0x600D800);
	}else if (bg_num == 1) {
		lz77UnCompVram(tilemap, (void *) 0x6006000);
	}else if (bg_num == 2) {
		lz77UnCompVram(tilemap, (void *) 0x600A000);
	}else if (bg_num == 3) {
		lz77UnCompVram(tilemap, (void *) 0x600E000);
	}
}

void load_bg_data_1(u8 bg_num, void* tileset, void* tilemap)
{
	if (bg_num == 0) {
		lz77UnCompVram(tilemap, (void *) 0x6001800);
		lz77UnCompVram(tileset, (void *) 0x6000000);
	}else if (bg_num == 1) {
		lz77UnCompVram(tilemap, (void *) 0x6006000);
		lz77UnCompVram(tileset, (void *) 0x6004000);		
	}else if (bg_num == 2) {
		lz77UnCompVram(tilemap, (void *) 0x6002000);
		lz77UnCompVram(tileset, (void *) 0x6008000);		
	}else if (bg_num == 3) {
		lz77UnCompVram(tilemap, (void *) 0x600F800);
		lz77UnCompVram(tileset, (void *) 0x6000000);
		}
}

void load_bg_data_2(u8 bg_num, void* tileset, void* tilemap)
{
	if (bg_num == 0) {
		lz77UnCompVram(tilemap, (void *) 0x6003000);
		lz77UnCompVram(tileset, (void *) 0x6000000);
	}else if (bg_num == 1) {
		lz77UnCompVram(tilemap, (void *) 0x6007000);
		lz77UnCompVram(tileset, (void *) 0x6004000);		
	}else if (bg_num == 2) {
		lz77UnCompVram(tilemap, (void *) 0x600B000);
		lz77UnCompVram(tileset, (void *) 0x6008000);		
	}else if (bg_num == 3) {
		lz77UnCompVram(tilemap, (void *) 0x600F000);
		lz77UnCompVram(tileset, (void *) 0x600C000);
		}
}

void load_bg_raw_1(u8 bg_num, void* tilemap)
{
	if (bg_num == 0) {
		lz77UnCompVram(tilemap, (void *) 0x600E000);
	}else if (bg_num == 1) {
		lz77UnCompVram(tilemap, (void *) 0x6006000);
	}else if (bg_num == 2) {
		lz77UnCompVram(tilemap, (void *) 0x6002000);
	}else if (bg_num == 3) {
		lz77UnCompVram(tilemap, (void *) 0x600E800);
	}
}

void load_bg_pal(u8 pal_num, void * palette, bool is_compressed)
{
    if (is_compressed){
        gpu_pal_apply_compressed(palette, 0, 512);
    } else {
        gpu_pal_apply(palette, 0, 512);
    }
    
} 
