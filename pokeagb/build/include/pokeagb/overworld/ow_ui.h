/**
 * @file
 * @Overworld UI, including start and help menu
 */

#ifndef POKEAGB_OW_UI_H_
#define POKEAGB_OW_UI_H_
#include "../common.h"
#include "../types.h"

POKEAGB_BEGIN_DECL

/**
 * Disables the game's help menu LR button toggled
 * @address{BPRE,0812B478}
 */
POKEAGB_EXTERN void help_system_disable__sp198(void);

/**
 * Plays the menu close sound, closes rboxes open from start menu
 * additionally unlocks the player for movement and allows scripts to run again.
 * @address{BPRE,0806FEA0}
 */
POKEAGB_EXTERN void sm_close_menu(void);

/**
 *
 * @address{BPRE,080F7998}
 */
POKEAGB_EXTERN void sm_close_description(void);

/**
 * closes the safari zone step count box, if in the safari zone
 * @address{BPRE,0806EF18}
 */
POKEAGB_EXTERN void safari_stepscount_close(void);

/**
 * @address{BPRE,0x080568A8}
 */
POKEAGB_EXTERN void c2_overworld_switch_start_menu(void);

POKEAGB_END_DECL

#endif /* POKEAGB_OW_UI_H_ */
