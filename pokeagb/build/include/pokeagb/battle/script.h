/**
 * @file
 * @brief Battle scripts.
 */

#ifndef POKEAGB_BATTLE_SCRIPT_H_
#define POKEAGB_BATTLE_SCRIPT_H_

#include "../common.h"
#include "../types.h"
#include "../pokemon.h"

/**
 * @address{BPRE,02023FDB}
 */
extern u8 battle_script_active_side;

struct dp08_d3 {
  u8 data[3];
};

struct BattleStuff {
    u8 padding_0[16];
    u8 party_index_10;
    u8 field_11;
    u8 field_12;
    enum PokemonType move_to_execute_type_override;
    u8 padding_14[53];
    u8 byte_49;
    u8 money_multiplier;
    u8 bs_mode_pbs_index;
    u8 padding_4C[4];
    u8 byte_50;
    u8 gap_51[1];
    u8 party_index_52;
    u8 field_53;
    u8 padding_54[8];
    u8 team_id_by_side_5C[4];
    struct dp08_d3 blobs_60[4];
    u8 padding_6C[12];
    u8 byte_78;
    u8 byte_79_randparam;
    u8 byte_7A_randparam;
    u8 byte_7B_randparam;
    u8 byte_7C;
    u8 objid_7D;
    u8 objid_7E;
    u8 byte_7F;
    u8 moveset_indices_pbs[11];
    u8 byte_8B;
    u8 byte_8C;
    u8 byte_8D;
    u8 type_8E;
    u8 byte_8F;
    u8 field_90;
    u8 field_91;
    u8 switchout_index_maybe[2];
    u8 byte_94;
    u8 byte_95;
    u8 index_96;
    u8 subindex_97;
    u8 padding_98[16];
    u16 hp_by_party_A8[2];
    u8 byte_AC;
    u8 byte_AD;
    u8 byte_AE;
    u8 pading_AF[6];
    u8 multiplayer_id_B5;
    u8 field_B6;
    u8 field_B7;
    u16 items_pbs[4];
    u8 item_usage[26];
    u8 byte_DA;
    u8 field_DB;
    u8 padding_DC[3];
    u8 field_DF;
    u8 padding_E0[32];
    u8 pading_100[132];
    u8 field_184[32];
    u8 pading_1A4[92];
};

/**
 * @address{BPRE,02023FE8}
 */
extern struct BattleStuff* battle_stuff;

ASSERT_SIZEOF(struct BattleStuff, 0x200);

#endif /* POKEAGB_BATTLE_SCRIPT_H_ */
