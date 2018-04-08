/**
 * @file
 * @brief Pokemon types.
 */

#ifndef POKEAGB_POKEMON_TYPE_H_
#define POKEAGB_POKEMON_TYPE_H_

#include <pokeagb/common.h>
#include <pokeagb/core/string.h>

POKEAGB_BEGIN_DECL

#define POKEAGB_TYPE_NAME_LENGTH 7

enum PokemonType {
    TYPE_NORMAL,
    TYPE_FIGHTING,
    TYPE_FLYING,
    TYPE_POISON,
    TYPE_GROUND,
    TYPE_ROCK,
    TYPE_BUG,
    TYPE_GHOST,
    TYPE_STEEL,
    TYPE_NONE, /**< ??? Type */
    TYPE_FIRE,
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_ELECTRIC,
    TYPE_PSYCHIC,
    TYPE_ICE,
    TYPE_DRAGON,
    TYPE_DARK,
    TYPE_MAX,
};

ASSERT_SIZEOF(enum PokemonType, 1);

/**
 * Pokemon type names table.
 *
 * @address{BPRE,0824F1A0}
 */
extern pchar pokemon_type_names[TYPE_MAX][POKEAGB_TYPE_NAME_LENGTH];

struct TypeEffectiveness {
    enum PokemonType attacker;
    enum PokemonType defender;
    u8 modifier;
};

/**
 * Type effectiveness chart.
 */
extern struct TypeEffectiveness type_effectiveness[112];

POKEAGB_END_DECL

#endif /* POKEAGB_POKEMON_TYPE_H_ */
