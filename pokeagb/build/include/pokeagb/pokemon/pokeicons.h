/**
 * @file
 * @brief Pokemon icons
 */

#ifndef POKEAGB_POKEICONS_H_
#define POKEAGB_POKEICONS_H_

#include <pokeagb/common.h>
#include <pokeagb/core/string.h>
#include "../graphics/palette.h"
#include "../graphics/sprites.h"
#include "species.h"

POKEAGB_BEGIN_DECL

#define POKEAGB_POKEMON_ICON_SIZE 1024

/**
 * @address{BPRE,083D37A0}
 */
extern const u8 pokeicon_table[410][POKEAGB_POKEMON_ICON_SIZE];

/**
 * Icons Pal Table
 * @address{BPRE,083D3740}
 */
extern const u16 pokeicon_pals[3][16];


/**
 * Icons Pal index Table. It contains an index 0-2 for the three
 * pals which are from the icons Pal table.
 * @address{BPRE,083D3E80}
 */
extern const u8 pokeicon_pal_indices[410];


/**
 * Graphics for held items. Hold item and mail held indicators
 * @address{BPRE,0845A3AC}
 */
extern const void *gfx_heldicons;


/**
 * Pal for held items. The yellow box and mail icon
 * @address{BPRE,0845A3EC}
 */
extern const void *pal_heldicons;

/**
 * Load the icon tiles for the given Pokemon, factoring in forms.
 *
 * @param pid Used to fetch the correct Unown form.
 * @param deoxys Whether to display the correct Deoxys form for this version.
 *
 * @address{BPRE,08097054}
 */
POKEAGB_EXTERN void* load_party_icon_tiles_with_form(enum PokemonSpecies species,
                                                    u32 pid, bool deoxys);

/**
 * Load the icon palette index for the given Pokemon species.
 * @address{BPRE,080971F8}
 */
POKEAGB_EXTERN u8 load_party_icon_palette_index(enum PokemonSpecies species);

/**
 * @address{BPRE,083D350C}
 */
extern const struct Template storage_hand_template;

/**
 * @address{BPRE,083D2BEC}
 */
extern const u8 storage_hand_tiles[0x800];

/**
 * @address{BPRE,083D2BCC}
 */
extern const u16 storage_hand_palette[16];

POKEAGB_END_DECL

#endif /* POKEAGB_POKEICONS_H_ */
