/**
 * @file
 * @brief Trainer related data
 */

#ifndef POKEAGB_BATTLE_TRAINER_H_
#define POKEAGB_BATTLE_TRAINER_H_

#include "../types.h"
#include "../common.h"
#include "../pokemon.h"
#include "../overworld/item.h"
#include "../overworld/npc.h"

#define TRAINER_COUNT 743
#define TRAINER_CLASS_COUNT 107
#define TRAINER_ITEM_COUNT 4

struct TrainerMoneyRate {
    u8 trainer_class;
    u8 money;
    u16 field2;
};

struct TrainerPokemonBase {
    u8 iv;
    u8 field1;
    u8 level;
    u8 field3;
    enum PokemonSpecies species;

    /**
     * Can be non-zero if TRAINER_PARTY_HELD_ITEM is set.
     */
    enum Item Item;
};

struct TrainerPokemonMoves {
    struct TrainerPokemonBase base;
    enum Move moves[POKEMON_MOVE_SLOTS];
};

/**
 * The structure that describes the trainer's party.
 */
enum TrainerPartyFlag {
    TRAINER_PARTY_HELD_ITEM = 1,
    TRAINER_PARTY_MOVESET = 2,
};

/**
 * Pokemon trainer data.
 */
struct Trainer {
    enum TrainerPartyFlag flags;
    u8 trainer_class;
    u8 music;
    u8 sprite;
    pchar name[10];
    u16 field_E;
    enum Item items[TRAINER_ITEM_COUNT];
    u32 field_18;
    u32 ai;
    u32 party_size;

    /**
     * Type is either TrainerPokemonBase or TrainerPokemonMoves. Type
     * is TrainerPokemonMoves only if TRAINER_PARTY_MOVESET flag is
     * set.
     */
    void* party;
};

ASSERT_SIZEOF(struct Trainer, 0x28);

/**
 * @address{BPRE,0824F220}
 */
extern struct TrainerMoneyRate trainer_class_money_rate[TRAINER_CLASS_COUNT];

/**
 * @address{BPRE,0823EAC8}
 */
extern struct Trainer trainer_data[TRAINER_COUNT];

/**
 * @address{BPRE,0823E558}
 */
extern pchar trainer_class_names[TRAINER_CLASS_COUNT][13];

/**
 * Fill the trainer party using the Pokemon from the trainer data.
 *
 * @address{BPRE,080112E0}
 */
POKEAGB_EXTERN void setup_opponent_party(struct Pokemon* party, u16 trainer_id);

/**
 * Fill the trainer party using the Pokemon from the trainer data.
 *
 * @address{BPRE,0803DA34}
 */
POKEAGB_EXTERN void pokemon_purge_opponent(void);

/**
 * Returns non-zero if the NPC state for the given index spotted
 * the player. This is for trainers that walk up to the player.
 *
 * @address{BPRE,08081B84}
 */
POKEAGB_EXTERN u8 check_if_npc_spotted_player(u8 npc_state_index);

/**
 * Returns non-zero if the player can't double battle.
 *
 * @address{BPRE,08040CC4}
 */
POKEAGB_EXTERN u8 player_unable_to_double_battle(void);

/**
 * Configure a battle using script arguments. Should be a pointer to
 * the arguments, not the actual trainer battle command.
 *
 * @address{BPRE,08080228}
 */
POKEAGB_EXTERN void battle_configure_by_script(void* script_arguments);

/**
 * Setup the task necessary for the trainer `npc` to walk `distance`
 * squares. Uses some specials to operate.
 *
 * @address{BPRE,08081E68}
 */
POKEAGB_EXTERN void add_task_trainer_walk(struct NpcState* npc, u8 distance);

/**
 * @address{BPRE,0808043C}
 */
POKEAGB_EXTERN void trainer_flag_set(u16 trainer_id);

/**
 * @address{BPRE,08080450}
 */
POKEAGB_EXTERN void trainer_flag_clear(u16 trainer_id);

/**
 * @address{BPRE,08080424}
 */
POKEAGB_EXTERN bool trainer_flag_check(u16 trainer_id);

/**
 * @address{BPRE,020386AE}
 */
extern u16 trainerbattle_flag_id;

#endif /* POKEAGB_BATTLE_TRAINER_H_ */
