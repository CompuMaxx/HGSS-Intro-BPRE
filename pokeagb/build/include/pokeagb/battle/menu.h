/**
 * @file
 * @brief Battle data
 */

#ifndef POKEAGB_BATTLE_MENU_H_
#define POKEAGB_BATTLE_MENU_H_

#include "../types.h"
#include "../common.h"
#include "../core/string.h"
#include "data.h"

POKEAGB_BEGIN_DECL

/**
 * The currently selected move index.
 *
 * @address{BPRE,02023FFC}
 */
extern u8 move_index_chosen_per_side[BATTLE_SIDES];
/**
 * The currently selected target.
 * @address{BPRE,03004FF4}
 */
extern u8 selected_battle_side;

/**
 * Draw text on one of the battle text boxes.
 *
 * IDs (Fight Menu/Select a Move):
 * 3 - Move 1
 * 4 - Move 2
 * 5 - Move 3
 * 6 - Move 4
 * 7 - The "PP" text - small text
 * 8 - Move type box - small text, use sequence 0xFC, 6, 1 to make normal sized
 * 9 - Numbers for the move PP box
 * 11 - Whole PP box
 *
 * @address{BPRE,080D87BC}
 */
POKEAGB_EXTERN void battle_draw_rbox(pchar* str, u8 rbox_id);

/**
 * @address{BPRE,080309CC}
 */
POKEAGB_EXTERN void battle_menu_draw_cursor(u8 move_index, u8 color);

/**
 * @address{BPRE,08030830}
 */
POKEAGB_EXTERN void battle_menu_draw_move_names(void);

/**
 * @address{BPRE,080308A8}
 */
POKEAGB_EXTERN void battle_menu_draw_move_pp(void);

/**
 * @address{BPRE,080308CC}
 */
POKEAGB_EXTERN void battle_menu_draw_move_pp_value(void);

/**
 * @address{BPRE,08030940}
 */
POKEAGB_EXTERN void battle_menu_draw_move_type(void);

/**
 * @address{BPRE,08032CB4}
 */
POKEAGB_EXTERN void battle_menu_fight_draw(void);

/**
 * @address{BPRE,08030A14}
 */
POKEAGB_EXTERN void battle_menu_erase_cursor(u8 move_index);

/**
 * A battle callback that handles the fight menu.
 * @address{BPRE,0802EA10}
 */
POKEAGB_EXTERN void battle_fight_menu(void);

POKEAGB_END_DECL

#endif /* POKEAGB_BATTLE_MENU_H_ */
