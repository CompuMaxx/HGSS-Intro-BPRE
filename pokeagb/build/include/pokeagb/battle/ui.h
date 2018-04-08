/**
* @file
* @brief HP bar related attributes
*/

#ifndef POKEAGB_BATTLE_UI_H_
#define POKEAGB_BATTLE_UI_H_

#include "../types.h"
#include "../common.h"

POKEAGB_BEGIN_DECL

#define TILE_SIZE 32
#define NAME_TILE_PLAYER 10
#define NAME_TILE_OPPONENT 9
#define GENDER_TILE_SINGLE_PLAYER 72
#define GENDER_TILE_DOUBLES_PLAYER 40
#define GENDER_TILE_OPPONENT 40
#define LEVEL_TILE_SINGLE_PLAYER 74
#define LEVEL_TILE_OPPONENT 42
#define LEVEL_TILE_DOUBLES_PLAYER 42
#define HEALTH_NUMS_TILE_PLAYER 30
#define AILMENT_TILE_SINLE_PLAYER 26
#define AILMENT_TILE_DOUBLE_PLAYER 17
#define AILMENT_TILE_OPPONENT 16


/**
 * uncompresses and loads green hpbar and other gfx
 *
 * @address{BPRE,08034964}
 */
POKEAGB_EXTERN void load_gfxc_health_bar(void);

/**
 * Sets some data into dp11 struct?
 *
 * @address{BPRE,08048150}
 */
POKEAGB_EXTERN void hpbox_data_set(u8, u8, u32, u32, u8);

/**
 * Syncs dp11 struct data into vram maybe
 *
 * @address{BPRE,08049FD8}
 */
POKEAGB_EXTERN void sync_hpbox_vram(u8, u8, u8);

enum BattleTerrain {
    BATTLE_TERRAIN_GRASS = 0,
    BATTLE_TERRAIN_LONG_GRASS = 1,
    BATTLE_TERRAIN_DESERT = 2,
    BATTLE_TERRAIN_UNDERWATER = 3,
    BATTLE_TERRAIN_OCEAN = 4,
    BATTLE_TERRAIN_POND = 5,
    BATTLE_TERRAIN_MOUNTAIN = 6,
    BATTLE_TERRAIN_CAVE = 7,
    BATTLE_TERRAIN_UNKNOWN = 8,
    BATTLE_TERRAIN_TRAINER_DEFAULT = 9,
    BATTLE_TERRAIN_TRAINER_LINK = 10,
    BATTLE_TERRAIN_TRAINER_GYM = 11,
    BATTLE_TERRAIN_TRAINER_CLASS_x54 = 12,
    BATTLE_TERRAIN_TRAINER_BATTLE_TYPE_3 = 13,
    BATTLE_TERRAIN_TRAINER_TEAM_ROCKET = 14,
    BATTLE_TERRAIN_TRAINER_ELITE4_1 = 15,
    BATTLE_TERRAIN_TRAINER_ELITE4_2 = 16,
    BATTLE_TERRAIN_TRAINER_ELITE4_3 = 17,
    BATTLE_TERRAIN_TRAINER_ELITE4_4 = 18,
    BATTLE_TERRAIN_TRAINER_CHAMPION = 19,
};

/**
 * Get the environment for the battle.
 * @address{BPRE,0800FC2C}
 */
POKEAGB_EXTERN enum BattleTerrain get_bs_elem_env_index(void);

POKEAGB_END_DECL

#endif /* POKEAGB_BATTLE_UI_H_ */
