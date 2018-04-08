/**
 * @file
 * @brief Game engine sprites.
 */

#ifndef POKEAGB_GRAPHICS_SPRITES_H_
#define POKEAGB_GRAPHICS_SPRITES_H_

#include <pokeagb/types.h>

POKEAGB_BEGIN_DECL

#define SPRITE_RAM 0x6010000

struct Object;

/**
 * Sprite object callback.
 * @param o The object the callback belongs to
 */
typedef void (*ObjectCallback)(struct Object* o);

/**
 * 8 bit coordinates
 */
struct Coords8 {
    u8 x;
    u8 y;
};

/**
 * 16 bit coordinates;
 */
struct Coords16 {
    s16 x;
    s16 y;
};

/**
 * Tile animation frame
 */
struct Frame {
    u16 data;
    u8 duration : 6;
    u8 hflip : 1;
    u8 vflip : 1;
};

ASSERT_SIZEOF(struct Frame, 4);

#define FRAME_LOOP 0xFFFE
#define FRAME_END 0xFFFF

/**
 * Rotation/Scaling frame
 */
struct RotscaleFrame {
    u16 scale_delta_x;
    u16 scale_delta_y;
    u8 rot_delta;
    u8 duration;
    u16 field_6;
};

/**
 * OAM Structure
 */

struct OamData {
    u32 y : 8;

    /**
     * 0=Normal, 1=Affine, 2=Disable, 3=Double Size
     */
    u32 affine_mode : 2;

    /**
     * 0=Normal, 1=Semi-Transparent, 2=OBJ Window, 3=Prohibited
     */
    u32 obj_mode : 2;

    /**
     * Enable mosaic
     */
    u32 mosaic : 1;

    /**
     * 1=256 colours
     */
    u32 bpp : 1;

    /**
     * 0=Square,1=Horizontal,2=Vertical,3=Prohibited
     */
    u32 shape : 2;

    u32 x : 9;
    u32 matrix_num : 3; // bits 3/4 are h-flip/v-flip if not in affine mode
    u32 h_flip : 1;
    u32 v_flip : 1;
    /**
     * Size  Square   Horizontal  Vertical
     * 0     8x8      16x8        8x16
     * 1     16x16    32x8        8x32
     * 2     32x32    32x16       16x32
     * 3     64x64    64x32       32x64
     */
    u32 size : 2;

    u16 tile_num : 10;

    /**
     * 0-3; 0=Highest
     */
    u16 priority : 2;
    u16 palette_num : 4;
    u16 affine_param;
};

/**
 * Tileset Data
 */
struct SpriteTiles {
    const void* data;
    u16 size;
    u16 tag;
};

struct SpritePalette {
    const void* data;
    u16 tag;
};

/**
 * A template for a sprite object
 */
struct Template {
    u16 tiles_tag;
    u16 pal_tag;
    const struct OamData* oam;

    /**
     * Animation table. Each entry is a pointer to an array of frames.
     */
    const struct Frame **animation;
    const struct SpriteTiles* graphics;
    const struct RotscaleFrame **rotscale;
    ObjectCallback callback;
};

/**
 * Sprite object
 */
struct Object {
    struct OamData final_oam;
    struct Frame **animation_table;
    struct SpriteTiles* gfx_table;
    struct RotscaleFrame **rotscale_table;
    struct Template* object_template;
    u32 field18;
    ObjectCallback callback;
    struct Coords16 pos1;
    struct Coords16 pos2;
    struct Coords8 shift;
    u8 anim_number;
    u8 anim_frame;
    u8 anim_delay;
    u8 counter;
    u16 priv[8];
    u8 bitfield2;
    u8 bitfield;
    u16 anim_data_offset;
    u8 field42;

    /**
     * Changes order of sprites in OAM. Allows fine-grained control of
     * hardware sprite priority. A lower value indicates higher
     * priority.  Sprites must have equal priority in OAM for this to
     * have any effect.
     */
    u8 y_height_related;
};

/**
 * All the objects
 * @address{BPRE,0202063C}
 */
extern struct Object objects[64];

/**
 * @address{BPRE,08231CFC}
 */
extern const struct RotscaleFrame *rotscale_empty;

/**
 * @address{BPRE,08231CF0}
 */
extern const struct Frame *anim_image_empty;

#define SPRITE_NO_ANIMATION (&anim_image_empty)
#define SPRITE_NO_ROTSCALE (&rotscale_empty)

/**
 * @address{BPRE,0800760C}
 */
POKEAGB_EXTERN void oac_nullsub(struct Object* o);

/**
 * @address{BPRE,08006B5C}
 */
POKEAGB_EXTERN void objc_exec(void);

/**
 * @address{BPRE,08006FE0}
 */
POKEAGB_EXTERN u8 template_instanciate_reverse_search(struct Template*, s16 x, s16 y, u8 height);

/**
 * @address{BPRE,08006BA8}
 */
POKEAGB_EXTERN DEPRECATED void obj_sync_something(void);

/**
 * @address{BPRE,08006BA8}
 */
POKEAGB_EXTERN void obj_sync_superstate(void);

/**
 * @address{BPRE,08006F8C}
 */
POKEAGB_EXTERN u8 template_instanciate_forward_search(const struct Template*,
                                                      u16 x,
                                                      u16 y,
                                                      u8 priority);

/**
 * @address{BPRE,08007804}
 */
POKEAGB_EXTERN u8 obj_delete_and_free(struct Object*);

/**
 * @address{BPRE,0800F078}
 */
POKEAGB_EXTERN void gpu_pal_decompress_alloc_tag_and_upload(struct SpritePalette* pal);

/**
 * @address{BPRE,08008928}
 */
POKEAGB_EXTERN void gpu_pal_obj_alloc_tag_and_apply(struct SpritePalette* pal);

/**
 * @address{BPRE,0800F034}
 */
POKEAGB_EXTERN void gpu_tile_obj_decompress_alloc_tag_and_upload(struct SpriteTiles* tile);

/**
 * @address{BPRE,080086DC}
 */
POKEAGB_EXTERN void gpu_tile_obj_alloc_tag_and_upload(struct SpriteTiles* tile);

/**
 * @address{BPRE,08008804}
 */
POKEAGB_EXTERN u16 gpu_tile_obj_tag_range_for_tag(u16 tile_tag);

/**
 * @address{BPRE,08008A30}
 */
POKEAGB_EXTERN u16 gpu_pal_free_by_tag(u16 pal_tag);

/**
 * @address{BPRE,08006B10}
 */
POKEAGB_EXTERN void obj_and_aux_reset_all(void);

/**
 * @address{BPRE,080087C4}
 */
POKEAGB_EXTERN void gpu_tile_obj_tags_reset(void);

/**
 * @address{BPRE,080836B4}
 */
POKEAGB_EXTERN void obj_free(struct Object *obj);


/**
 * @address{BPRE,0800874C}
 */
POKEAGB_EXTERN void gpu_tile_obj_free_by_tag(u16 tag);

/**
 * @address{BPRE,080073DC}
 */
POKEAGB_EXTERN void obj_delete(struct Object *obj);

/**
 * Bouncing object. Uses private variables for control.
 * private[0] = 0 - Start object animation before bounce, 1 - Just bounce, other - disable
 * private[1] = Animation to start if private[0] == 0
 * private[2] = Direction: 0 - horizontal, 1 - vertical
 * private[3] = Distance
 * private[4] = Speed
 * private[5] = Phase Shift
 * @address{BPRE,08133904}
 */
POKEAGB_EXTERN void oac_pingpong(struct Object*);

/**
 * Sine wave. Used to animate bouncing objects.
 * @param phase The current phase or the x in sin(x)
 * @param scale The amplitude of the wave
 * @address{BPRE,08044E30}
 */
POKEAGB_EXTERN s16 get_pingpong(s16 phase, u16 scale);

/**
 * reset affine
 * @address{BPRE,08007390}
 */
POKEAGB_EXTERN void affine_reset_all(void);

/**
 * apply palfade for transparent objects
 * @address{BPRE,08070588}
 */
POKEAGB_EXTERN void obj_apply_bldpalfade(u32, s16, s16, s16, u32);

/**
 * set oam matrix rotscale manually
 * @address{BPRE,08075858}
 */
POKEAGB_EXTERN void obj_id_set_rotscale(u8 objid, u32 pa, u32 pb, u32 pc, u32 pd);

/**
 * set oam animation start
 * @address{BPRE,0800838C}
 */
POKEAGB_EXTERN void obj_anim_image_start(struct Object* obj, u8 animation_num);

/**
 * Given a tag, return's it's index in sprite pal RAM
 * @address{BPRE,080089E8}
 */
 POKEAGB_EXTERN u8 gpu_pal_tags_index_of(u16 pal_tag);

 /**
  * List of pal tags for objects used, indexed by pal slot
  * @address{BPRE,03000DE8}
  */
  extern u8 gpu_pal_tags[0x20];

/* A sine wave with a 180 degree period.
 * @param phase The current phase.
 * @address{BPRE,08044E6C}
 */
POKEAGB_EXTERN s16 get_spring_animation(s16 phase);

/**
 * Duplicate the object and place it at the given coordinates. Used for reflective surfaces.
 * @address{BPRE,0805FB6C}
 */
POKEAGB_EXTERN u8 object_clone(struct Object* src, s16 x, s16 y, u8 priority);


POKEAGB_END_DECL

#endif /* POKEAGB_GRAPHICS_SPRITES_H_ */
