/**
 * @file
 * @brief Pokemon evolutions.
 */

#ifndef POKEAGB_POKEMON_EVOLUTION_H_
#define POKEAGB_POKEMON_EVOLUTION_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>
#include <pokeagb/overworld/item.h>
#include <pokeagb/pokemon/species.h>
#include <pokeagb/pokemon/base.h>

POKEAGB_BEGIN_DECL

#define EVOLUTIONS_PER_POKEMON 5

enum EvolutionType {
    /**
     * High friendship (220 or greater).
     */
    EVOLUTION_FRIENDSHIP = 1,

    /**
     * Espeon.
     */
    EVOLUTION_FRIENDSHIP_DAY,

    /**
     * Umbreon.
     */
    EVOLUTION_FRIENDSHIP_NIGHT,

    /**
     * Standard evolution type. Argument is the level.
     */
    EVOLUTION_LEVEL_UP,

    /**
     * Evolves in a trade.
     */
    EVOLUTION_TRADE,

    /**
     * Evolves if traded while holding an item. Argument is the item to be held.
     */
    EVOLUTION_TRADE_ITEM,

    /**
     * Evolves if given an evolutionary stone. Argument is the stone item index.
     */
    EVOLUTION_STONE,

    /**
     * Hitmonlee.
     */
    EVOLUTION_ATK_GT_DEF,

    /**
     * Hitmontop.
     */
    EVOLUTION_ATK_EQ_DEF,

    /**
     * Hitmonchan.
     */
    EVOLUTION_ATK_LT_DEF,

    /**
     * Silcoon.
     */
    EVOLUTION_PID_SILCOON,

    /**
     * Cascoon.
     */
    EVOLUTION_PID_CASCOON,

    /**
     * Evolve at levelup, but create a new Pokemon (needs an
     * additional entry with the type EVOLUTION_SPAWNED). Used for Ninjask.
     */
    EVOLUTION_SPAWN,

    /**
     * Create a new Pokemon (companion to EVOLUTION_SPAWN). Used for Shedinja.
     */
    EVOLUTION_SPAWNED,

    /**
     * Milotic.
     */
    EVOLUTION_BEAUTY,

};

struct EvolutionEntry {
    /**
     * The type of evolution.
     */
    enum EvolutionType type;

    /**
     * The parameter for the evolution. Changes depending on type.
     */
    union {
        u16 raw;
        u16 level;
        enum Item item;
    } argument;

    /**
     * The species to evolve into.
     */
    enum PokemonSpecies species;

    /**
     * Padding.
     */
    u16 unknown;
};

ASSERT_SIZEOF(struct EvolutionEntry, 8);
ASSERT_OFFSETOF(struct EvolutionEntry, type, 0);
ASSERT_OFFSETOF(struct EvolutionEntry, argument, 2);
ASSERT_OFFSETOF(struct EvolutionEntry, species, 4);
ASSERT_OFFSETOF(struct EvolutionEntry, unknown, 6);

/**
 * @address{BPRE,08259754}
 */
extern struct EvolutionEntry evolution_table[POKEAGB_POKEMON_SLOTS][EVOLUTIONS_PER_POKEMON];


/**
 * @address{BPRE,08045970}
 */
extern u16 get_base_species(u16);

POKEAGB_END_DECL

#endif /* POKEAGB_POKEMON_EVOLUTION_H_ */
