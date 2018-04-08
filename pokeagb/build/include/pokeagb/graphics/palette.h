/**
 * @file
 * @brief Palettes
 */

#ifndef POKEAGB_GRAPHICS_PALETTE_H_
#define POKEAGB_GRAPHICS_PALETTE_H_

#include "../types.h"

// this doesn't structured right at. Bit fields broken between bytes
// and game loads it as though it's a byte. Please review
struct FadeControl {
    u16 bg_pal_bitfield;
    u16 obj_pal_bitfield;
    u8 delay_counter:6;
    u16 y:5; // blend coefficient
    u16 target_y:5; // target blend coefficient
    u16 blend_color:15;
    u16 active:1;
    u16 multipurpose:6;
    u16 y_dec:1; // whether blend coefficient is decreasing
    u16 buffer_transfer_disabled:1;
    u16 mode:2;
    u16 should_reset_blend_registers:1;
    u16 hardware_fade_finishing:1;
    u16 software_fade_finishing_counter:5;
    u16 software_fade_finishing:1;
    u16 obj_palette_toggle:1;
    u8 delta_y:4; // rate of change of blend coefficient
};

struct ColorComponents {
    u16 r : 5;
    u16 g : 5;
    u16 b : 5;
    u16 unused : 1;
};

union Color {
    struct ColorComponents components;
    u16 packed;
};

/**
 * @address{BPRE,02037AB8}
 */
extern struct FadeControl pal_fade_control;

/**
 * @address{BPRE,08150408}
 */
POKEAGB_EXTERN u8* stdpal_get(u8 id);

/**
 * @address{BPRE,03003E58}
 */
extern u8* gpu_pal_tag_search_lower_boundary;

/**
 * @address{BPRE,080703EC}
 */
POKEAGB_EXTERN void gpu_pal_apply(const void* palette, u16 offset, u16 size);

/**
 * @address{BPRE,080703A8}
 */
POKEAGB_EXTERN void gpu_pal_apply_compressed(void* palette, u16 offset, u16 size);

/**
 * @address{BPRE,08070588}
 */
POKEAGB_EXTERN bool fade_screen(u32 bitmask, s8 speed, u8 to, u8 from, u16 color);

/**
 * @address{BPRE,080704D0}
 */
POKEAGB_EXTERN DEPRECATED void fade_and_return_progress_probably(void);

/**
 * @address{BPRE,08070474}
 */
POKEAGB_EXTERN void gpu_pal_upload(void);

/**
 * @address{BPRE,08070528}
 */
POKEAGB_EXTERN void pal_fade_control_and_dead_struct_reset(void);

/**
 * @address{BPRE,0807DB38}
 */
POKEAGB_EXTERN void palette_bg_faded_fill_black(void);

/**
 * @address{BPRE,080704D0}
 */
POKEAGB_EXTERN void process_palfade(void);

/**
 * @address{BPRE,080088F0}
 */
POKEAGB_EXTERN void gpu_pal_allocator_reset(void);

/**
 * ZeroFills PAL RAM
 * @address{BPRE,0807DC00}
 */
POKEAGB_EXTERN void pal_fill_black(void);

  
#endif /* POKEAGB_GRAPHICS_PALETTE_H_ */
