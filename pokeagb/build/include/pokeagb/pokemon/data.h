/**
 * @file
 * @brief Pokemon data.
 */

#ifndef POKEAGB_POKEMON_DATA_H_
#define POKEAGB_POKEMON_DATA_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>
#include <pokeagb/core/string.h>
#include <pokeagb/overworld/item.h>
#include <pokeagb/pokemon/move.h>
#include <pokeagb/pokemon/species.h>

POKEAGB_BEGIN_DECL

#define POKEMON_MOVE_SLOTS 4
#define POKEMON_PARTY_SIZE 6
#define POKEMON_STAT_COUNT 6

/**
 * Pokemon Language.
 */
enum PokemonLanguage {
    /**
     * Japanese.
     */
    POKEMON_LANGUAGE_JA = 1,

    /**
     * English.
     */
    POKEMON_LANGUAGE_EN = 2,

    /**
     * French.
     */
    POKEMON_LANGUAGE_FR = 3,

    /**
     * Italian.
     */
    POKEMON_LANGUAGE_IT = 4,

    /**
     * German.
     */
    POKEMON_LANGUAGE_DE = 5,

    /**
     * Korean.
     */
    POKEMON_LANGUAGE_KO = 6,

    /**
     * Spanish.
     */
    POKEMON_LANGUAGE_ES = 7,
};

struct PokemonPPBonuses {
    u8 move1 : 2;
    u8 move2 : 2;
    u8 move3 : 2;
    u8 move4 : 2;
};

/**
 * Substructure containing growth related data.
 */
struct PokemonSubstructureGrowth {
    enum PokemonSpecies species;
    enum Item item;
    u32 experience;
    struct PokemonPPBonuses pp_bonuses;
    u8 friendship;
    u16 unknown;
};

ASSERT_SIZEOF(struct PokemonSubstructureGrowth, 12);

/**
 * Substructure containing attack related data.
 */
struct PokemonSubstructureAttacks {
    enum Move attacks[POKEMON_MOVE_SLOTS];
    u8 pp[4];
};

ASSERT_SIZEOF(struct PokemonSubstructureAttacks, 12);

/**
 * Substructure containing EV and condition related data.
 */
struct PokemonSubstructureCondition {
    u8 hp_ev;
    u8 atk_ev;
    u8 def_ev;
    u8 spd_ev;
    u8 spatk_ev;
    u8 spdef_ev;
    u8 coolness;
    u8 beauty;
    u8 cuteness;
    u8 smartness;
    u8 toughness;
    u8 feel;
};

ASSERT_SIZEOF(struct PokemonSubstructureCondition, 12);

/**
 * Substructure containing miscellaneous data.
 */
struct PokemonSubstructureMisc {
    u8 pokerus;
    u8 met_location;
    u16 origins_info;
    u32 ivs_egg_ability;
    u32 ribbons_obedience;
};

ASSERT_SIZEOF(struct PokemonSubstructureMisc, 12);

/**
 * Pokemon base data. This packed format is used for PC storage.
 */
#pragma pack(push, 1)
struct PokemonBase {
    /**
     * The personality value controls many things, including gender,
     * Unown's letter, Spinda's dots, any Pokémon's Nature, and more.
     */
    u32 pid;

    /**
     * The Original Trainer's ID number. This number is part of the
     * XOR encryption key for the data section, and is also used in
     * Shiny determination and the lottery. The least significant
     * bytes of this number are the Trainer ID visible on the status
     * screen.
     */
    u32 otid;

    /**
     * The Pokémon's nickname, limited to 10 characters. The
     * characters represented by each byte are determined by the
     * proprietary character set.
     */
    pchar nick[10];

    /**
     * The language of the game the Pokémon comes from.
     */
    enum PokemonLanguage font;

    /**
     * The low bit is high if the Pokemon is a bad egg.
     */
    u8 sanity;

    /**
     * The name of the Pokémon's Original Trainer. The characters
     * represented by each byte are determined by the proprietary
     * character set.
     */
    pchar otname[7];

    /**
     * The markings seen in the storage Box. These markings serve only
     * to aid in organizing large collections of Pokémon.
     */
    struct {
        u8 circle : 1;
        u8 square : 1;
        u8 triangle : 1;
        u8 heart : 1;
    } markings;

    /**
     * The checksum for the 48-byte data section of this structure. It
     * is computed by adding all of the unencrypted values of that
     * section one word at a time. If the computed sum and the stored
     * checksum do not match, the Pokémon is interpreted as a Bad Egg.
     */
    u16 checksum;

    u16 unused;

    /**
     * Certain data pertaining to the Pokémon that is stored in a
     * special and encrypted format.
     */
    union {
        u8 bytes[48];
        union {
            struct PokemonSubstructureGrowth growth;
            struct PokemonSubstructureAttacks attacks;
            struct PokemonSubstructureCondition effort;
            struct PokemonSubstructureMisc misc;
        };
    } data;
};
#pragma pack(pop)

ASSERT_SIZEOF(struct PokemonBase, 80);

enum PokemonAilment {
    AILMENTBITS_NONE = 0x0,
    AILMENTBITS_SLEEP = 0x7,
    AILMENTBITS_POISON = 0x8,
    AILMENTBITS_BURN = 0x10,
    AILMENTBITS_FREEZE = 0x20,
    AILMENTBITS_PARALYZE = 0x40,
    AILMENTBITS_TOXIC = 0x80,
};

/**
 * Extended Pokemon data.
 */
struct Pokemon {
    struct PokemonBase base;
    enum PokemonAilment __attribute__((aligned(4))) status;
    u8 level;
    u8 pokerus;
    u16 current_hp;
    u16 total_hp;
    u16 atk;
    u16 def;
    u16 spd;
    u16 spatk;
    u16 spdef;
};

ASSERT_SIZEOF(struct Pokemon, 100);

/**
 * Pokemon attribute request type. Not all attributes have been documented.
 */
enum PokemonDataRequest {
    /**
     * The personality ID of the Pokemon.
     * @see PokemonBase
     */
    REQUEST_PID = 0x0,

    /**
     * The original trainer ID (including secret ID) of the Pokemon.
     * @see PokemonBase
     */
    REQUEST_TID = 0x1,

    /**
     * The Pokemon's nickname.
     * @see PokemonBase
     */
    REQUEST_NICK = 0x2,

    /**
     * The language of the game the Pokémon comes from.
     * @see PokemonLanguage
     */
    REQUEST_FONT_LANG = 0x3,

    /**
     * Bad egg.
     * @see PokemonBase
     */
    REQUEST_SANITY_X4 = 0x4,

    /**
     * Unknown. Bit 1 of the sanity byte.
     * @see PokemonBase
     */
    REQUEST_SANITY_X5 = 0x5,

    /**
     * Seems be a second indicator for egg. Bit 2 of the sanity byte.
     * @see PokemonBase
     */
    REQUEST_SANITY_X6 = 0x6,

    /**
     * The name of the Pokmeon's original trainer.
     * @see PokemonBase
     */
    REQUEST_OT_NAME = 0x7,

    /**
     * The markings for the pokemon (heart, circle, etc.)
     * @see PokemonBase
     */
    REQUEST_MARKS = 0x8,

    /**
     * The data checksum. If this is invalid the Pokemon will become a
     * bad egg.
     * @see PokemonBase
     */
    REQUEST_CHECKSUM = 0x9,

    /**
     * The species of the Pokemon.
     * SPECIES_MAX if the Pokemon is a bad egg.
     * @see PokemonBase, PokemonSpecies
     */
    REQUEST_SPECIES = 0xB,

    /**
     * The Pokemon's held item.
     * @see PokemonSubstructureGrowth, Item
     */
    REQUEST_HELD_ITEM = 0xC,

    /**
     * The first move of the Pokemon.
     * @see PokemonSubstructureAttacks, Move
     */
    REQUEST_MOVE1 = 0xD,

    /**
     * The second move of the Pokemon.
     * @see PokemonSubstructureAttacks, Move
     */
    REQUEST_MOVE2 = 0xE,

    /**
     * The third move of the Pokemon.
     * @see PokemonSubstructureAttacks, Move
     */
    REQUEST_MOVE3 = 0xF,

    /**
     * The fourth move of the Pokemon.
     * @see PokemonSubstructureAttacks, Move
     */
    REQUEST_MOVE4 = 0x10,

    /**
     * The current PP for the Pokemon's first move.
     * @see PokemonSubstructureAttacks
     */
    REQUEST_PP1 = 0x11,

    /**
     * The current PP for the Pokemon's second move.
     * @see PokemonSubstructureAttacks
     */
    REQUEST_PP2 = 0x12,

    /**
     * The current PP for the Pokemon's third move.
     * @see PokemonSubstructureAttacks
     */
    REQUEST_PP3 = 0x13,

    /**
     * The current PP for the Pokemon's fourth move.
     * @see PokemonSubstructureAttacks
     */
    REQUEST_PP4 = 0x14,

    /**
     * How many PP bonuses have been applied.
     * @see PokemonSubstructureGrowth, PokemonPPBonuses
     */
    REQUEST_PP_BONUSES = 0x15,

    /**
     * The Pokemon's coolness stat.
     * @see PokemonSubstructureCondition
     */
    REQUEST_COOLNESS = 0x16,

    /**
     * The Pokemon's beauty stat.
     * @see PokemonSubstructureCondition
     */
    REQUEST_BEAUTY = 0x17,

    /**
     * The Pokemon's cuteness stat.
     * @see PokemonSubstructureCondition
     */
    REQUEST_CUTENESS = 0x18,

    /**
     * The Pokemon's experience.
     * @see PokemonSubstructureGrowth
     */
    REQUEST_EXP_POINTS = 0x19,

    /**
     * The Pokemon's HP effort value level.
     * @see PokemonSubstructureCondition
     */
    REQUEST_HP_EV = 0x1A,

    /**
     * The Pokemon's attack effort value level.
     * @see PokemonSubstructureCondition
     */
    REQUEST_ATK_EV = 0x1B,

    /**
     * The Pokemon's defense effort value level.
     * @see PokemonSubstructureCondition
     */
    REQUEST_DEF_EV = 0x1C,

    /**
     * The Pokemon's speed effort value level.
     * @see PokemonSubstructureCondition
     */
    REQUEST_SPD_EV = 0x1D,

    /**
     * The Pokemon's special attack effort value level.
     * @see PokemonSubstructureCondition
     */
    REQUEST_SPATK_EV = 0x1E,

    /**
     * The Pokemon's special defense effort value level.
     * @see PokemonSubstructureCondition
     */
    REQUEST_SPDEF_EV = 0x1F,

    /**
     * The Pokemon's happiness or friendship level.
     * @see PokemonSubstructureGrowth
     */
    REQUEST_HAPPINESS = 0x20,

    /**
     * The Pokemon's smartness stat.
     * @see PokemonSubstructureCondition
     */
    REQUEST_SMARTNESS = 0x21,

    /**
     * The Pokemon's Pokerus status.
     * @see PokemonSubstructureMisc
     */
    REQUEST_POKERUS = 0x22,

    /**
     * Where the pokemon was caught.
     * @see PokemonSubstructureMisc
     */
    REQUEST_CATCH_LOCATION = 0x23,

    /**
     * At what level the Pokemon was caught.
     * @see PokemonSubstructureMisc
     */
    REQUEST_CATCH_LEVEL = 0x24,

    /**
     * What game the Pokemon was caught in.
     * @see PokemonSubstructureMisc
     */
    REQUEST_GAME_OF_ORIGIN = 0x25,

    /**
     * The type of Pokeball that was used to catch the Pokemon.
     * @see PokemonSubstructureMisc
     */
    REQUEST_POKEBALL = 0x26,

    /**
     * The HP IV for the Pokemon.
     * @see PokemonSubstructureMisc
     */
    REQUEST_HP_IV = 0x27,

    /**
     * The Attack IV for the Pokemon.
     * @see PokemonSubstructureMisc
     */
    REQUEST_ATK_IV = 0x28,

    /**
     * The Defense IV for the Pokemon.
     * @see PokemonSubstructureMisc
     */
    REQUEST_DEF_IV = 0x29,

    /**
     * The Speed IV for the Pokemon.
     * @see PokemonSubstructureMisc
     */
    REQUEST_SPD_IV = 0x2A,

    /**
     * The Special Attack IV for the Pokemon.
     * @see PokemonSubstructureMisc
     */
    REQUEST_SPATK_IV = 0x2B,

    /**
     * The Special Defense IV for the Pokemon.
     * @see PokemonSubstructureMisc
     */
    REQUEST_SPDEF_IV = 0x2C,

    /**
     * True if the Pokemon is an egg.
     * @see PokemonSubstructureMisc
     */
    REQUEST_IS_EGG = 0x2D,

    /**
     * 1 if the Pokemon use it's second ability or 0 for the first ability.
     * @see PokemonSubstructureMisc
     */
    REQUEST_ABILITY_BIT = 0x2E,

    /**
     * The Pokemon's toughness stat.
     * @see PokemonSubstructureCondition
     */
    REQUEST_TOUGHNESS = 0x2F,

    /**
     * Pokeblock
     * [feel](http://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9block#Feel)
     * level. 0 - 255
     * @see PokemonSubstructureCondition
     */
    REQUEST_SHEEN = 0x30,

    /**
     * The gender of the Pokemon's original trainer.
     * @see PokemonSubstructureMisc
     */
    REQUEST_OT_GENDER = 0x31,

    /**
     * The status ailment of the Pokemon.
     * @invariant Needs an extended Pokemon struct instead of PokemonBase.
     * @see Pokemon
     */
    REQUEST_STATUS_AILMENT = 0x37,

    /**
     * The level of the Pokemon. Calculated using level_by_exp.
     * @invariant Needs an extended Pokemon struct instead of PokemonBase.
     * @see Pokemon
     */
    REQUEST_LEVEL = 0x38,

    /**
     * The Pokemon's current health.
     * @invariant Needs an extended Pokemon struct instead of PokemonBase.
     * @see Pokemon
     */
    REQUEST_CURRENT_HP = 0x39,

    /**
     * The Pokemon's total health.
     * @invariant Needs an extended Pokemon struct instead of PokemonBase.
     * @see Pokemon
     */
    REQUEST_TOTAL_HP = 0x3A,

    /**
     * The Pokemon's current attack stat.
     * @invariant Needs an extended Pokemon struct instead of PokemonBase.
     * @see Pokemon
     */
    REQUEST_ATK = 0x3B,

    /**
     * The Pokemon's current defense stat.
     * @invariant Needs an extended Pokemon struct instead of PokemonBase.
     * @see Pokemon
     */
    REQUEST_DEF = 0x3C,

    /**
     * The Pokemon's current speed stat.
     * @invariant Needs an extended Pokemon struct instead of PokemonBase.
     * @see Pokemon
     */
    REQUEST_SPD = 0x3D,

    /**
     * The Pokemon's current special attack stat.
     * @invariant Needs an extended Pokemon struct instead of PokemonBase.
     * @see Pokemon
     */
    REQUEST_SPATK = 0x3E,

    /**
     * The Pokemon's current special defense stat.
     * @invariant Needs an extended Pokemon struct instead of PokemonBase.
     * @see Pokemon
     */
    REQUEST_SPDEF = 0x3F,

    /**
     * The days remaining of the Pokerus virus.
     * @invariant Needs an extended Pokemon struct instead of PokemonBase.
     * @see Pokemon
     */
    REQUEST_POKERUS_REMAINING = 0x40,

    /**
     * Get species only if the Pokemon is not an egg.
     * @see PokemonBase, PokemonSpecies
     */
    REQUEST_SPECIES2 = 0x41,

    /**
     * True if the Pokemon has been used to beat the Pokemon League.
     * @see PokemonSubstructureMisc
     */
    REQUEST_HALL_OF_FAME_RIBBON = 0x43,

    /**
     * Determines the obedience of Mew and Deoxys. If this bit is not
     * set, Mew and Deoxys cannot be traded to or from Pokémon
     * FireRed, LeafGreen, or Emerald, and will always disobey the
     * player in battle in those games (except in link battles). If
     * this bit is set on a Pokémon that is transferred to a later
     * generation, the Pokémon will be treated as having had a fateful
     * encounter.
     * @see PokemonSubstructureMisc
     */
    REQUEST_OBEDIENCE = 0x50,
};

/**
 * Read a Pokemon attribute.
 *
 * @param pokemon A Pokemon. Some attributes need the full Pokemon struct.
 * @param attribute The attribute to read.
 * @param output Pointer to a buffer to write strings to if the
 *               request returns a string.
 * @return The attribute value or amount of bytes copied.
 * @address{BPRE,0803FBE8}
 */
POKEAGB_EXTERN u32 pokemon_getattr(void* pokemon,
                                   enum PokemonDataRequest attribute,
                                   pchar* output);


/**
 * Set a Pokemon attribute.
 *
 * @param pokemon A Pokemon. Some attributes need the full Pokemon struct.
 * @param attribute The attribute to write.
 * @param data Pointer to the new attribute value.
 * @address{BPRE,0804037C}
 */
POKEAGB_EXTERN void pokemon_setattr(void* pokemon,
                                    enum PokemonDataRequest attribute,
                                    void* data);

/**
 * Calculate the Pokemon's level using its experience points.
 * @adddress{BPRE,0803E7C4}
 */
POKEAGB_EXTERN int level_by_exp(struct PokemonBase* pokemon);

/**
 * The amount of Pokemon in the player's party.
 * @address{BPRE,02024029}
 */
extern u8 pokemon_quantity;

/**
 * Count the number of Pokemon in the player's party and update pokemon_quantity.
 * @address{BPRE,08040C3E}
 */
POKEAGB_EXTERN u8 party_count_pokemon(void);

/**
 * @address{BPRE,02024284}
 */
extern struct Pokemon party_player[POKEMON_PARTY_SIZE];

/**
 * @address{BPRE,0202402C}
 */
extern struct Pokemon party_opponent[POKEMON_PARTY_SIZE];

/**
 * Clear and create a new Pokemon structure.
 *
 * @param dst The destination Pokemon slot to create the Pokemon in.
 * @param species The species of the generated Pokemon.
 * @param level The Pokemon's level
 * @param iv Anything below 0x20 to set all IVs to that value,
 * otherwise randomly generate IV values.
 * @param use_pid true if PID should be used, otherwise randomly generate one.
 * @param pid The provided PID (use_pid must be true)
 * @param use_tid How to get the trainer ID. 2 to randomly generate
 * one, 1 to use the provided tid, anything else to use the player's
 * TID.
 * @param tid The provided TID (use_tid must be 1)
 * @address{BPRE,0803DAC4}
 */
POKEAGB_EXTERN void pokemon_make(struct PokemonBase* dst,
                                 enum PokemonSpecies species,
                                 u8 level,
                                 u8 iv,
                                 bool use_pid,
                                 u32 pid,
                                 u8 use_tid,
                                 u32 tid);
/**
 * Same as pokemon_make, but using a full 100 byte Pokemon structure
 * as the destination.
 * @address{BPRE,0803DA54}
 */
POKEAGB_EXTERN void pokemon_make_full(struct Pokemon* dst,
                                      enum PokemonSpecies species,
                                      u8 level,
                                      u8 iv,
                                      bool use_pid,
                                      u32 pid,
                                      u8 use_tid,
                                      u32 tid);

/**
 * Clear a PokemonBase slot.
 * @address{BPRE,0803D97C}
 */
POKEAGB_EXTERN void pokemon_slot_purge(struct PokemonBase* dst);

/**
 * Clear a 100 byte Pokemon slot.
 * @address{BPRE,0803D994}
 */
POKEAGB_EXTERN void pokemon_slot_purge_full(struct Pokemon* dst);

/**
 * Calculate the stats for the Pokemon. Can be used to expand a
 * PokemonBase struct into a full Pokemon struct.
 *
 * @address{BPRE,0803E47C}
 */
POKEAGB_EXTERN void recalculate_stats(struct Pokemon* pokemon);

/**
 *
 * @address{BPRE,080404D0}
 */
POKEAGB_EXTERN void set_pokemon_data_2(struct Pokemon* pokemon, enum PokemonDataRequest, void* data);

/**
 *
 * @address{BPRE,0803E3E8}
 */
POKEAGB_EXTERN u16 pokemon_calc_checksum(struct Pokemon* pokemon);

/**
 *
 * @address{BPRE,08040FD0}
 */
POKEAGB_EXTERN void copy_pokemon_name(pchar* dst, enum PokemonSpecies);

/**
 * Adds a string terminator (in place) to the end of the 10 byte
 * Pokemon string if it needs it.
 * @address{BPRE,08008D28}
 */
POKEAGB_EXTERN void pokemon_nickname_to_string(pchar* nickname);

enum PokemonGender {
    PKMN_GENDER_BOY = 0,
    PKMN_GENDER_GIRL = 0xFE,
    PKMN_GENDER_NONE = 0xFF,
};

/**
 * Retrieve gender using PID and base stats table
 *
 * @address{BPRE,0803F720}
 */
POKEAGB_EXTERN u8 pokemon_get_gender(struct Pokemon* pokemon);

enum PokemonNature {
    NATURE_HARDY,
    NATURE_LONELY,
    NATURE_BRAVE,
    NATURE_ADAMANT,
    NATURE_NAUGHTY,
    NATURE_BOLD,
    NATURE_DOCILE,
    NATURE_RELAXED,
    NATURE_IMPISH,
    NATURE_LAX,
    NATURE_TIMID,
    NATURE_HASTY,
    NATURE_SERIOUS,
    NATURE_JOLLY,
    NATURE_NAIVE,
    NATURE_MODEST,
    NATURE_MILD,
    NATURE_QUIET,
    NATURE_BASHFUL,
    NATURE_RASH,
    NATURE_CALM,
    NATURE_GENTLE,
    NATURE_SASSY,
    NATURE_CAREFUL,
    NATURE_QUIRKY,
    NATURE_MAX,
};

/**
 * Nature stat bonus table. HP is not included, so the stat order here
 * is: attack, defense, speed, special attack, special_defense.  The
 * value will be -1 to indicate the nature decreases the stat, and +1
 * to indicate and increase in the stat.
 * @address{BPRE,08252B48}
 */
extern s8 nature_stat_bonuses[NATURE_MAX][POKEMON_STAT_COUNT - 1];

/**
 * Apply nature bonuses to a stat.
 * @address{BPRE,08043698}
 */
POKEAGB_EXTERN u16 nature_stat_mod(enum PokemonNature nature, u16 stat_value, u8 stat_index);

/**
 * Get the nature for a Pokemon.
 * @address{BPRE,08042E9C}
 */
POKEAGB_EXTERN enum PokemonNature pokemon_get_nature(void* pokemon);

/**
 * Get the nature from a PID
 * @address{BPRE,08042EB4}
 */
POKEAGB_EXTERN enum PokemonNature get_nature_from_pid(u32 pid);

/**
 * Restore a Pokemon's PP fully
 * @address{BPRE,080442E4}
 */
 POKEAGB_EXTERN void pokemon_restore_pp(struct Pokemon* pokemon);

#define STATUS_SLEEP_TURNS 7
#define STATUS_POISON (1 << 3)
#define STATUS_BURN (1 << 4)
#define STATUS_FREEZE (1 << 5)
#define STATUS_PARALYSIS (1 << 6)
#define STATUS_BAD_POISON (1 << 7)

POKEAGB_END_DECL

#endif /* POKEAGB_POKEMON_DATA_H_ */
