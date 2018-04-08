/**
 * @file
 * @brief Battle data
 */

#ifndef POKEAGB_BATTLE_DATA_H_
#define POKEAGB_BATTLE_DATA_H_

#include "../types.h"
#include "../common.h"
#include "../core/string.h"
#include "../pokemon.h"
#include "../graphics/sprites.h"

POKEAGB_BEGIN_DECL

#define BATTLE_SIDES 4

enum BattleSide {
    SIDE_PLAYER,
    SIDE_OPPONENT,
};

enum BattleBank {
    BANK_PLAYER,
    BANK_OPPONENT,
    BANK_PLAYER_ALLY,
    BANK_OPPONENT_ALLY,
};

/**
 * Data for the Pokemon currently battling.
 */
struct BattlePokemon {
  u16 species;
  u16 atk;
  u16 def;
  u16 spd;
  u16 spatk;
  u16 spdef;
  enum Move moves[4];
  u32 ivs;
  u8 hp_buff_maybe;
  u8 atk_buff;
  u8 def_buff;
  u8 spd_buff;
  u8 sp_atk_buff;
  u8 sp_def_buff;
  u8 acc_buff;
  u8 evasion_buff;
  enum PokemonAbility ability_id;
  u8 type1;
  u8 type2;
  u8 padding1;
  u8 current_pp[4];
  u16 current_hp;
  u8 level;
  u8 happiness;
  u16 max_hp;
  enum Item held_item;
  pchar name[11];
  u8 field_3B;
  pchar trainer_name[8];
  u32 padding2;
  u32 pid;
  u32 status;
  u32 status2;
  u32 otid;
};

ASSERT_SIZEOF(struct BattlePokemon, 0x58);

/**
 * @address{BPRE,0826056C}
 */
extern struct SpriteTiles ball_tiles[11];

/**
 * @address{BPRE,082605CC}
 */
extern struct SpritePalette ball_palettes[11];


/**
 * @address{BPRE,02023BC4}
 */
extern u8 b_active_side;

/**
 * @address{BPRE,02023BCC}
 */
extern u8 b_num_active_sides;

/**
 * @address{BPRE,02023D6B}
 */
extern u8 b_attacker;

/**
 * @address{BPRE,02023D6C}
 */
extern u8 b_defender;

/**
 * @address{BPRE,02023D6D}
 */
extern u8 b_attacker_partner;

/**
 * @address{BPRE,02023D6E}
 */
extern u8 b_defender_partner;

/**
 * @address{BPRE,02023D70}
 */
extern u8 absent_flags_for_banks;

/**
 * @address{BPRE,02023BE4}
 */
extern struct BattlePokemon battle_data[BATTLE_SIDES];

/**
 * @address{BPRE,080751C4}
 */
POKEAGB_EXTERN enum BattleSide battle_side_get_owner(enum BattleBank side);

/**
 * @address{BPRE,080751E8}
 */
POKEAGB_EXTERN u8 battle_get_side_with_given_state(u8 state);

/**
 * Uses the AI to pick a move index for the current Pokemon.
 *
 * @address{BPRE,080751D8}
 */
POKEAGB_EXTERN u8 battle_get_per_side_status(u8 bank);

/**
 * The Pokemon party index by bank number.
 *
 * @address{BPRE,02023BCE}
 */
extern u16 b_pokemon_team_id_by_side[BATTLE_SIDES];

/**
 * Pokemon banks sorted by turn order.
 *
 * @address{BPRE,02023BDE}
 */
extern u8 b_attackers_in_order[BATTLE_SIDES];

/**
 * @address{BPRE,02023BE2}
 */
extern u8 bs_mode_pbs_index;

/**
 * The item index to be displayed in messages about held item effects.
 * @address{BPRE,02023D68}
 */
extern enum Item b_message_held_item;


/**
 * Given a ball item id, gives index of ball gfx table
 *
 * @address{BPRE,080EF52C}
 */
POKEAGB_EXTERN u8 ball_number_to_ball_processing_index(u16 item_id);


POKEAGB_END_DECL

#endif /* POKEAGB_BATTLE_DATA_H_ */
