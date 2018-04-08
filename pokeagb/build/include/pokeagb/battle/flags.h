/**
 * @file
 * @brief Internal battle commands
 */

#ifndef POKEAGB_BATTLE_FLAGS_H_
#define POKEAGB_BATTLE_FLAGS_H_

#include "../types.h"

POKEAGB_BEGIN_DECL


enum BattleFlag {
    BATTLE_FLAG_DOUBLE = 1,
    BATTLE_FLAG_LINK = 2,
    BATTLE_FLAG_WILD = 4,
    BATTLE_FLAG_TRAINER = 8,
    BATTLE_FLAG_OAK_TUTORIAL = 0x10,
    BATTLE_FLAG_PARTNER = 0x40,
    BATTLE_FLAG_SAFARI = 0x80,
    BATTLE_FLAG_OLD_MAN = 0x200,
    BATTLE_FLAG_ROAMING = 0x400,
    BATTLE_FLAG_GHOST = 0x8000,
    BATTLE_FLAG_POKE_DUDE = 0x10000
};

/**
 * @address{BPRE,02022B4C}
 */
extern enum BattleFlag battle_type_flags;

/**
 * @address{BPRE,08075290}
 */
POKEAGB_EXTERN u8 battle_type_is_double(void);

POKEAGB_END_DECL

#endif /* POKEAGB_BATTLE_FLAGS_H_ */
