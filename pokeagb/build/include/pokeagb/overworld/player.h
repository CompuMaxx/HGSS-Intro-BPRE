/**
 * @file
 * @brief The player's overworld character.
 */

#ifndef POKEAGB_OVERWORLD_PLAYER_H_
#define POKEAGB_OVERWORLD_PLAYER_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>

POKEAGB_BEGIN_DECL

/**
 * The player's movement state.
 */
struct Walkrun {
    u8 step_speed : 3;
    u8 is_surfing : 1;
    u8 bitfield : 4;
    u8 bike;
    u8 running2;
    u8 running1;
    u8 oamid;
    u8 npcid;
    u8 lock;
    u8 gender;
    u8 xmode;
    u8 field9;
    u8 fieldA;
    u8 fieldB;
    u32 fieldC;
    u32 field10;
    u32 field14;
    u8 field18;
    u8 field19;
    u16 field1A;
    u16 most_recent_override_tile;
};

enum PlayerAvatarType {
    PLAYER_AVATAR_WALKING,
    PLAYER_AVATAR_BIKE,
    PLAYER_AVATAR_SURFING,
    PLAYER_AVATAR_POKEBALL_VS_SEEKER,
    PLAYER_AVATAR_FISHING,
};

/**
 * Fetch the NPC type number (overworld sprite) for the given player state.
 * @address{BPRE,0805C808}
 */
u8 player_avatar_get_type(enum PlayerAvatarType type);

POKEAGB_END_DECL

#endif
