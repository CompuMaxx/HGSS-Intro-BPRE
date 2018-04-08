/**
 * @file
 * @brief The overworld map in memory.
 */

#ifndef POKEAGB_OVERWORLD_VIRTUAL_MAP_H_
#define POKEAGB_OVERWORLD_VIRTUAL_MAP_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>
#include <pokeagb/overworld/map.h>

POKEAGB_BEGIN_DECL

/**
 * The amount of extra blocks to add to the map height to create a virtual map.
 */
#define VIRTUAL_MAP_VERTICAL_PADDING 14

/**
 * The amount of extra blocks to add to the map width to create a virtual map.
 */
#define VIRTUAL_MAP_HORIZONTAL_PADDING 15

/**
 * The amount of blocks in the border of the virtual map.
 */
#define VIRTUAL_MAP_BORDER_SIZE 7

/**
 * The maximum amount of map blocks that can fit in a map
 */
#define VIRTUAL_MAP_MAX_BLOCKS 0x1400

/**
 * The map loaded in memory. It includes the blocks from adjacent,
 * connected maps in the padding area.
 */
struct VirtualMapHeader {
    u32 width;
    u32 height;
    struct MapTile* data;
};

/**
 * Fetch the block index at the given position for the current map.
 * Uses virtual map coordinates.
 * @address{BPRE,08058E48}
 */
POKEAGB_EXTERN u16 cur_mapdata_get_blockid_at(u16 x, u16 y);

/**
 * Set the block index and permissions at the given position for the
 * current map.  Uses virtual map coordinates.
 * @address{BPRE,08058FEC}
 * @see MapTile
 */
POKEAGB_EXTERN void setmaptile_four_nibbles(u16 x, u16 y, u16 tile);

/**
 * Get the height bits at the given coordinates.
 * @address{BPRE,08058D44}
 */
POKEAGB_EXTERN u8 cur_mapdata_get_height_bits_at(u16 x, u16 y);

/**
 * Redraw the tile at the given position.
 * Uses virtual map coordinates.
 * @address{BPRE,0805A8E8}
 */
POKEAGB_EXTERN void cur_mapdata_draw_block_at(u16 x, u16 y);

/**
 * Redraw the tiles visible from the camera's current position.
 * @address{BPRE,0805A684}
 */
POKEAGB_EXTERN void cur_mapdata_full_redraw(void);

/**
 * The currently loaded map's header.
 *
 * @address{BPRE,03005040}
 */
extern struct VirtualMapHeader virtual_map_header;

/**
 * The currently loaded map's data. This includes the padding: data
 * from connected maps and the map border tiles.
 *
 * @address{BPRE,02031DFC}
 */
extern struct MapTile virtual_map_data[VIRTUAL_MAP_MAX_BLOCKS];

/**
 * The currently loaded map header.
 * @address{BPRE,02036DFC}
 */
extern struct MapHeader current_map_header;

POKEAGB_END_DECL

#endif /* POKEAGB_OVERWORLD_VIRTUAL_MAP_H_ */
