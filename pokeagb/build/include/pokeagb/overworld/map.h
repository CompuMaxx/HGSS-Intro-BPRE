/**
 * @file
 * @brief Overworld maps.
 */

#ifndef POKEAGB_OVERWORLD_MAP_H_
#define POKEAGB_OVERWORLD_MAP_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>
#include <pokeagb/version.h>
#include <pokeagb/overworld/item.h>
#include <pokeagb/overworld/npc.h>
#include <pokeagb/graphics/sprites.h>

POKEAGB_BEGIN_DECL

// TODO: Move this structure elsewhere.

/**
 * Tile map tile.
 */
struct Tile {
    /**
     * Character number.
     */
    u16 character : 10;

    /**
     * Horizontal Flip.
     */
    u16 h_flip : 1;

    /**
     * Vertical Flip.
     */
    u16 v_flip : 1;

    /**
     * Palette number.
     */
    u16 palette : 4;
};

/**
 * A tile on the map.
 */
struct MapTile {
    u16 tile : 10;
    u16 permission : 6;
};

ASSERT_SIZEOF(struct MapTile, 2);

#ifdef VERSION_FRLG
#define MAP_BLOCKSET_PRIMARY_MAX_BLOCKS 640
#define MAP_BLOCKSET_SECONDARY_MAX_BLOCKS 384
#define MAP_BLOCKSET_MAX_BLOCKS (MAP_BLOCKSET_PRIMARY_MAX_BLOCKS + MAP_BLOCKSET_SECONDARY_MAX_BLOCKS)
#endif

/**
 * The behavior of the block.
 */
struct MapBlockBehavior {
    /**
     * Block role.
     */
    u32 role : 9;

    /**
     * Unknown. 2 for grass, 4 for water.
     */
    u32 field1 : 5;
    u32 field2 : 4;
    u32 field3 : 6;

    /**
     * The encounter type of the block.
     */
    enum {
        MAP_BLOCK_ENCOUNTER_NONE,
        MAP_BLOCK_ENCOUNTER_GRASS,
        MAP_BLOCK_ENCOUNTER_WATER,
    } encounter : 3;             /* Encounter related. */

    u32 field5 : 2;

    /**
     * What background layers block tiles are drawn on.
     */
    enum {
        /**
         * Normal mode. Layer 2 goes above NPCs.
         *
         * Block layer 1 -> BG2
         * Block layer 2 -> BG1
         */
        MAP_BLOCK_BG_21,

        /**
         * NPCs appear on top of both layers.
         *
         * Block layer 1 -> BG3
         * Block layer 2 -> BG2
         */
        MAP_BLOCK_BG_32,

        /**
         * Seemingly unused.
         *
         * Block layer 1 -> BG3
         * Block layer 2 -> BG1
         */
        MAP_BLOCK_BG_31,
    } backgrounds: 2;

    u32 field7 : 1;
};

ASSERT_SIZEOF(struct MapBlockBehavior, 4);

/**
 * A single map block.
 */
struct MapBlock {
    struct Tile layer[2][4];
};

ASSERT_SIZEOF(struct MapBlock, 0x10);

/**
 * Blocks from which the map is constructed.
 */
struct MapBlockset {
    /**
     * Whether the tiles are compressed or not.
     */
    bool compressed;

    /**
     * Whether this tileset is to be used as a secondary tileset or primary tileset.
     */
    bool secondary;
    u16 padding;

    /**
     * Tiles used to build blocks.
     */
    void* tiles;

    /**
     * Palettes for the blockset.
     */
    void* palettes;

    /**
     * Block description.
     */
    struct MapBlock* blocks;

    /**
     * Tileset initialization function. Called to set up animation functions.
     */
    void (*function)(void);

    /**
     * Block behaviours.
     */
    struct MapBlockBehavior* behaviors;
};

ASSERT_SIZEOF(struct MapBlockset, 0x18);

/**
 * Map data.
 */
struct MapData {
    u32 width;
    u32 height;
    struct MapTile* border;
    struct MapTile* data;
    struct MapBlockset* blocksets[2];
#ifdef VERSION_FRLG
    u8 border_width;
    u8 border_height;
#endif
};

#ifdef VERSION_FRLG
ASSERT_SIZEOF(struct MapData, 0x1C);
#else
ASSERT_SIZEOF(struct MapData, 0x18);
#endif

/**
 * Warps.
 */
struct WarpData {
    /**
     * Target map bank.
     */
    u8 bank;

    /**
     * Target map.
     */
    u8 map;

    /**
     * Target warp id.
     */
    u8 id;

    /**
     * Warp co-ordinates.
     */
    struct Coords16 coordinates;
};

ASSERT_SIZEOF(struct WarpData, 8);

/**
 * Scripts that are run when the event is stepped on.
 */
struct TriggerData {
    /**
     * Trigger co-ordinates.
     */
    struct Coords16 coordinates;

    /**
     * Talking level.
     */
    u16 height;

    /**
     * Trigger variable.
     */
    u16 variable;

    /**
     * Trigger variable value. Runs the trigger if variable is equal to this value.
     */
    u16 value;
    u16 padding;

    /**
     * Script to run.
     */
    u8* script;
};

ASSERT_SIZEOF(struct TriggerData, 0x10);

enum SignpostType {
    /**
     * Regular signpost script.
     */
    MAP_SIGNPOST_SCRIPT,

    /**
     * Run script if the player is facing up.
     */
    MAP_SIGNPOST_SCRIPT_UP,

    /**
     * Run script if the player is facing down.
     */
    MAP_SIGNPOST_SCRIPT_DOWN,

    /**
     * Run script if the player is facing left.
     */
    MAP_SIGNPOST_SCRIPT_LEFT,

    /**
     * Run script if the player is facing right.
     */
    MAP_SIGNPOST_SCRIPT_RIGHT,

    /**
     * Hidden item. Behaves identically to 5 and 6.
     */
    MAP_SIGNPOST_HIDDEN_ITEM = 7,

#ifdef VERSION_RSE
    /**
     * A secret base entrace. (CHECK)
     */
    MAP_SIGNPOST_SECRET_BASE,
#endif
};

struct SignpostData {
    /**
     * Signpost co-ordinates.
     */
    struct Coords16 coordinates;

    /**
     * Talking level.
     */
    u16 height;

    /**
     * The type of signpost.
     */
    enum SignpostType type;

    union {
        /**
         * Script to run. Only for script type signposts.
         */
        u8* script;

        /**
         * Hidden item configuration. Only for hidden item type signposts.
         */
        struct {
            /**
             * Item index.
             */
            enum Item index;

            /**
             * Hidden item ID. Should be globally unique.
             */
            u8 flag;

            /**
             * The quantity to give.
             */
            u8 amount : 7;

            /**
             * If true, no script will be run.
             */
            bool skip : 1;
        } item;
    };
};

ASSERT_SIZEOF(struct SignpostData, 0xC);

/**
 * Events on the map.
 */
struct MapEvents {
    u8 num_npcs;
    u8 num_warps;
    u8 num_triggers;
    u8 num_signposts;
    struct RomNpc* npcs;
    struct WarpData* warps;
    struct TriggerData* triggers;
    struct SignpostData* signposts;
};

ASSERT_SIZEOF(struct MapEvents, 0x14);

enum MapConnectionType {
    MAP_CONNECTION_NOTHING,
    MAP_CONNECTION_DOWN,
    MAP_CONNECTION_UP,
    MAP_CONNECTION_LEFT,
    MAP_CONNECTION_RIGHT,
    MAP_CONNECTION_DIVE,
    MAP_CONNECTION_EMERGE,
};

/**
 * How the map is connected to other maps.
 */
struct MapConnection {
    enum MapConnectionType direction;
    s32 offset;
    u8 bank;
    u8 map;
    u16 padding;
};

ASSERT_SIZEOF(struct MapConnection, 0xC);

struct MapConnections {
    u32 number;
    struct MapConnection* data;
};

/**
 * A map.
 */
struct MapHeader {
    struct MapData* data;
    struct MapEvents* events;
    void* scripts;
    struct MapConnections* connections;
    u16 music;
    u16 map_index;
    u8 name;
    u8 cave;
    u8 weather;
    u8 light;
    u8 field_18;
    u8 escape_rope;
    u8 show_name;
    u8 battle_type;
};

ASSERT_SIZEOF(struct MapHeader, 0x1C);


/**
 * Current map header 
 * @address{BPRE,02036DFC}
 */
 extern struct MapHeader currentmap_header;

/**
 * Current map header 
 * @address{BPRE,08058DC4}
 */ 
POKEAGB_EXTERN u8 cur_mapdata_get_middle2bit_at(s16 x, s16 y);

/**
 * Fetch the map header for the given map.
 * @address{BPRE,08055238}
 */
POKEAGB_EXTERN struct MapHeader* mapheader_by_mapnumbers(u8 bank, u8 map);


/**
 * Return height mismatch between NPC and position
 * @address{BPRE,080681B0}
 */
POKEAGB_EXTERN u8 cur_mapdata_height_mismatch(u8 height, s16 x, s16 y);

/**
 * Check if map light supports flying/teleporting. I.e not indoors or cave.
 * @address{BPRE,080561FC}
 */
POKEAGB_EXTERN bool is_light_level_1_2_3_or_6__opensky(u8 map_light);

/**
 * @address{BPRE,08056260}
 */
extern u8 get_map_name_index(void);

struct wild_pokemon {
    u8 min_level;
    u8 max_level;
    u16 species;
};

union wild_pokemon_densities {
    struct wild_pokemon wild_grass[12];
    struct wild_pokemon wild_water[5];
    struct wild_pokemon wild_tree[5];
    struct wild_pokemon wild_fishing[10];
};

struct pokemon_by_encounter_rate {
    u8 encounter_chance;
    u8 padding[3];
    union wild_pokemon_densities *wild_encounters;
};

struct map_wild_pokemon_data {
    u8 map_bank;
    u8 map_num;
    u16 padding;
    struct pokemon_by_encounter_rate *grass_encounter; // 12 slots
    struct pokemon_by_encounter_rate *water_encounter; // 5 slots 
    struct pokemon_by_encounter_rate *tree_encounter; // 5 slots
    struct pokemon_by_encounter_rate *fishing_encounter; // 10 slots

};

#define WILD_MAPS_MAX 133

/**
 * Wild data
 * @address{BPRE,083C9CB8}
 */
extern struct map_wild_pokemon_data wild_pokemon_data[WILD_MAPS_MAX]; // maybe it's not 133 and I can't count

/**
 * @address{BPRE,08082934}
 */
extern u8 get_wild_data_index_for_map(void);

/**
 * @address{BPRE,08058F48}
 */
extern u32 cur_mapdata_block_get_field_at(u16 x_coord, u16 y_coord, u8 unk);


/**
 * @address{BPRE,08058F1C}
 */
extern u32 blockinfo_get_field(u32 block_info, u8 field);


/**
 * @address{BPRE,0807F748}
 */
extern void exec_battle(void);


/**
 * Needs a better name. Logs coords 
 * and size of object to some structure
 * @address{BPRE,08063BC4}
 */
extern void log_coords_relative_camera(s32* x, s32* y, u8 size_x, u8 size_y);

POKEAGB_END_DECL

#endif /* POKEAGB_OVERWORLD_MAP_H_ */
