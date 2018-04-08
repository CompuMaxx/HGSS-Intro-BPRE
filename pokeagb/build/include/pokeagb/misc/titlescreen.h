/**
 * @file
 * @brief Functions used on the titlescreen.
 */

#ifndef POKEAGB_MISC_TITLESCREEN_H_
#define POKEAGB_MISC_TITLESCREEN_H_

#include <pokeagb/common.h>
#include <pokeagb/types.h>

POKEAGB_BEGIN_DECL

/**
 * Go to the main menu if reloading a save or start a new game automatically.
 * @address{BPRE,0800C300}
 */
POKEAGB_EXTERN void c2_main_menu_or_new_game(void);

/**
 * Show the save erase menu.
 * @address{BPRE,080796CC}
 */
POKEAGB_EXTERN void c2_erase_save_menu(void);

POKEAGB_END_DECL

#endif /* POKEAGB_MISC_TITLESCREEN_H_ */
