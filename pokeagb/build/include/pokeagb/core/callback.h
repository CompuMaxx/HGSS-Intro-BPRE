/**
 * @file
 * @brief Game engine callbacks.
 */

#ifndef POKEAGB_CORE_CALLBACK_H_
#define POKEAGB_CORE_CALLBACK_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>
#include <pokeagb/graphics/sprites.h>

POKEAGB_BEGIN_DECL

typedef void (*SuperCallback)(void);

/**
 * Bits for the keypad;
 */
enum Keypad {
    KEY_A = (1 << 0),
    KEY_B = (1 << 1),
    KEY_SELECT = (1 << 2),
    KEY_START = (1 << 3),
    KEY_RIGHT = (1 << 4),
    KEY_LEFT = (1 << 5),
    KEY_UP = (1 << 6),
    KEY_DOWN = (1 << 7),
    KEY_L = (1 << 8),
    KEY_R = (1 << 9),

    /** Directional pad mask */
    KEY_DPAD = (KEY_UP | KEY_DOWN | KEY_LEFT | KEY_RIGHT),
};

/**
 * Check the if the all the given keys are pressed
 */
#define KEYS_ALL_PRESSED(x, keys) (((x) & (keys)) == (keys))

struct Superstate {
    SuperCallback callback1;
    SuperCallback callback2;
    SuperCallback callback2_backup;
    SuperCallback vblank_handler;
    SuperCallback hblank_handler;
    SuperCallback field_14;
    SuperCallback serial_callback;

    u32 bits_to_wait_for;
    u16* vblank_counter;
    u32 field_24;

    u16 buttons_held;
    u16 buttons_new;
    u16 buttons_held_remapped;
    u16 buttons_new_remapped;
    u16 buttons_new_and_repeated;
    u16 buttons_countdown;

    u32 unused_apparently;
    struct OamData sprites[128];
    u8 multi_purpose_state_tracker;
    u8 gpu_sprites_upload_skip;
};

/**
 * Set a primary per-frame callback.
 *
 * @address{BPRE,080565E0}
 */
POKEAGB_EXTERN void set_callback1(SuperCallback func);

/**
 * Set a secondary per-frame callback.
 *
 * @address{BPRE,08000544}
 */
POKEAGB_EXTERN void set_callback2(SuperCallback func);

/**
 *
 *
 * @address{BPRE,080006F4}
 */
POKEAGB_EXTERN void vblank_handler_set(SuperCallback func);

/**
 *
 *
 * @address{BPRE,08000700}
 */
POKEAGB_EXTERN void hblank_handler_set(SuperCallback func);

/**
 *
 *
 * @address{BPRE,080567DC}
 */
POKEAGB_EXTERN void c2_exit_to_overworld_2_switch(void);


/**
 * Global game state.
 *
 * @address{BPRE,030030F0}
 */
extern struct Superstate super;

POKEAGB_END_DECL

#endif /* POKEAGB_CORE_CALLBACK_H_ */
