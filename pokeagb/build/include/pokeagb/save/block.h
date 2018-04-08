/**
 * @file
 * @brief Game save data.
 */

#ifndef POKEAGB_SAVE_BLOCK_H_
#define POKEAGB_SAVE_BLOCK_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>
#include <pokeagb/version.h>
#include <pokeagb/core/string.h>
#include <pokeagb/overworld/npc.h>
#include <pokeagb/overworld/map.h>
#include <pokeagb/pokemon/data.h>

POKEAGB_BEGIN_DECL

// TODO: Emerald and Ruby/Sapphire saves

/**
 * An entry in the log for the "previously on your quest" feature.
 */
struct QuestLogStory {
  u8 active;
  u8 field_1[1638];
  u8 field_667;
};

ASSERT_SIZEOF(struct QuestLogStory, 0x668);

/**
 * Main save game data.
 */
#pragma pack(push, 1)
struct SaveBlock1 {
    s16 camera_x;
    s16 camera_y;
    struct WarpData location;
    struct WarpData saved_warp;
    struct WarpData field_14;
    struct WarpData whiteout_related;
    struct WarpData save_warp_2;
    u16 field_2C;
    u8 weather_probably;
    u8 gap_2F[1];
    u8 flash_used_on_map;
    u8 gap_31[1];
    u16 mapdata_idx_plus_1;
    u8 num_party_pokemon;
    u8 gap_35[603];
    u32 money_maybe;
    u8 pcitems[124];
    u32 bag_probably[42];
    u8 ghu_2_x3B8[120];
    u32 field_430[13];
    u8 ghu_1_x464[232];
    u8 field_54C[172];
    u8 pokemon_flags_1[52];
    u8 field_62C[12];
    u16 field_638;
    u32 field_63A;
    u8 field_63E[98];
    struct NpcState npc_states[16];
    struct RomNpc rom_npcs[64];
    u8 field_EE0[64];
    u32 field_F20;
    u8 field_F24[220];
    u16 var_4000[256];
    u8 field_1200[256];
    struct QuestLogStory questlog[4];
    u8 field_2CA0[48];
    struct NpcState field_2CD0[16];
    u8 field_2F10[112];
    u32 daycare_data;
    u8 field_2F84[332];
    u8 field_30D0[28];
    u8 field_30EC[28];
    u16 engima_berry_data[9];
    u8 field_311A[458];
    u8 mevent_related_1[332];
    u32 field_3430;
    u8 mevent_related_2[332];
    u8 field_3580[156];
    u32 ereader_script;
    u8 field_3620[4];
    u8 field_3624[1012];
    u8 pokemon_flags_2[52];
    u8 rival_name[8];
    u8 field_3A54[736];
    u8 field_3D34[14];
    u8 field_3D42[12];
    u8 field_3D4E[153];
    u8 last_field;
};
#pragma pack(pop)

ASSERT_SIZEOF(struct SaveBlock1, 0x3DE8);

enum Gender {
    GENDER_MALE,
    GENDER_FEMALE,
};

enum OptionsButtonMode {
    OPTIONS_BUTTON_MODE_NORMAL,
    OPTIONS_BUTTON_MODE_LR,
    OPTIONS_BUTTON_MODE_L_EQUALS_A
};

enum OptionsTextSpeed {
    OPTIONS_TEXT_SPEED_SLOW,
    OPTIONS_TEXT_SPEED_MID,
    OPTIONS_TEXT_SPEED_FAST
};

enum OptionsSound {
    OPTIONS_SOUND_MONO,
    OPTIONS_SOUND_STEREO
};

enum OptionsBattleStyle {
    OPTIONS_BATTLE_STYLE_SHIFT,
    OPTIONS_BATTLE_STYLE_SET
};

enum OptionsBattleScene {
    OPTIONS_BATTLE_SCENE_ON,
    OPTIONS_BATTLE_SCENE_OFF,
};

/**
 * Trainer and miscellaneous save data.
 */
struct SaveBlock2 {
    u8 name[8];
    enum Gender gender;
    u8 field_9;
    u16 trainerid;
    u16 secretid;
    u16 playtime_hours;
    u8 playtime_minutes;
    u8 playtime_seconds;
    u8 playtime_frames;
    enum OptionsButtonMode options_button_style;
    enum OptionsTextSpeed options_text_speed : 3;
    u8 options_window_frame : 5;
    enum OptionsSound options_sound : 1;
    enum OptionsBattleStyle options_battle_style : 1;
    enum OptionsBattleScene options_battle_scene_off : 1;
    u8 field_15[6];
    u32 unown_pid;
    u32 spinda_pid;
    u32 field_24;
    u8 pokemon_flags_3[52];
    u8 pokemon_flags_4[52];
    u8 field_90[1044];
    u8 fourCharacters[4];
    u8 field_4A8[1008];
    u8 mapdata[1672];
    u32 bag_item_quantity_xor_value;
    u8 field_F24[127];
    u8 last_byte_in_sav2;
};

ASSERT_SIZEOF(struct SaveBlock2, 0xFA4);

/**
 * Pokemon storage related save data.
 */
struct SaveBlock3 {
  u8 preferred_box;
  u8 gap_1[3];
  struct PokemonBase lanettes_boxes[420];
  pchar box_names[14][9];
};

ASSERT_SIZEOF(struct SaveBlock3, 0x83C2);

/**
 * @address{BPRE,03005008}
 */
extern struct SaveBlock1* saveblock1;

/**
 * @address{BPRE,0300500C}
 */
extern struct SaveBlock2* saveblock2;

/**
 * @address{BPRE,03005010}
 */
extern struct SaveBlock3* saveblock3;

/**
 * Move the saveblocks around.
 * @address{BPRE,0804C058}
 */
POKEAGB_EXTERN void saveblock_randomize_position(void);

/**
 * Reset the save globals mapped to save memory (outside of the saveblocks)
 * @address{BPRE,08054A28}
 */
POKEAGB_EXTERN void reset_save_mapped_memory(void);

/**
 * Clean saveblocks.
 * @address{BPRE,08054A18}
 */
POKEAGB_EXTERN void initialize_savebocks();

POKEAGB_END_DECL

#endif /* POKEAGB_SAVE_BLOCKH_ */
