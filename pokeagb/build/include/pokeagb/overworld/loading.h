/**
 * @file
 * @brief Overworld loading and setup.
 */

#ifndef POKEAGB_OVERWORLD_LOADING_H_
#define POKEAGB_OVERWORLD_LOADING_H_

#include "../common.h"
#include "../types.h"

typedef void (*MapHook)(void);

/**
 * Load the map fully and set up the normal overworld.
 * @param state_tracker Pointer to a counter to track iteration
 * state. Usually super.multi_purpose_state_tracker
 * @address{BPRE,08056E5C}
 */
POKEAGB_EXTERN void map_loading_loop(u8* state_tracker);

/**
 * Load just the map tiles, skipping NPCs and other overworld
 * features.  Used to render a minimal environment for flashbacks.
 * @param state_tracker Pointer to a counter to track iteration
 * state. Usually super.multi_purpose_state_tracker
 * @address{BPRE,08057300}
 */
POKEAGB_EXTERN void map_loading_loop_minimal(u8* state_tracker);

/**
 * Main overworld callback (callback 1). Requires c2_overworld as callback 2.
 * @address{BPRE,08056534}
 */
POKEAGB_EXTERN void c1_overworld(void);

/**
 * Secondary overworld callback (callback 2).
 * @address{BPRE,080565B4}
 */
POKEAGB_EXTERN void c2_overworld(void);

/**
 * Called in c1_overworld if c2 running and not prev quest
 * @address{BPRE,0805644C}
 */
POKEAGB_EXTERN void c1_overworld_normal(u16 remapped_new, u16 remapped_held);

/**
 * Function to be executed after the map loads.
 * @address{BPRE,03005020}
 */
extern MapHook map_post_load_hook;

/**
 * Default map post load hook.
 * @address{BPRE,0807DF64}
 */
POKEAGB_EXTERN void mapldr_default(void);

/**
 * Clear and set up save blocks for a new game.
 * Requires the player and rival to have been named.
 * @address{BPRE,08054A60}
 */
POKEAGB_EXTERN void new_game(void);


#endif /* POKEAGB_OVERWORLD_LOADING_H_ */
