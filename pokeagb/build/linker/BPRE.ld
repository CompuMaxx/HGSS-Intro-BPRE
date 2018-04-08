__aeabi_idiv = 0x081E3B68|1;
__aeabi_idivmod = 0x081E3B68|1;
__aeabi_uidiv = 0x081E3B68|1;
__aeabi_uidivmod = 0x081E3B68|1;
/*
 * include/pokeagb/battle/command.h
 */

ability_something = 0x08019f18|1;
b_buffer_A = 0x02022bc4;
b_buffer_B = 0x020233c4;
b_buffers_awaiting_execution_bitfield = 0x02023bc8;
b_c = 0x03004f84;
b_x = 0x03004fe0;
bc_bs_exec = 0x080155c8|1;
bs0_start_attack = 0x08015ca0|1;
dp01_battle_side_mark_buffer_for_execution = 0x08017248|1;
dp01_build_cmdbuf_x07 = 0x0800e0d4|1;
dp01_build_cmdbuf_x09 = 0x0800e114|1;
dp01_build_cmdbuf_x10 = 0x0800e2d4|1;
dp01_build_cmdbuf_x21_a_bb = 0x0800e848|1;
dp01_build_cmdbuf_x22 = 0x0800e874|1;
dp01_build_cmdbuf_x34 = 0x0800eb28|1;
dp01_prepare_buffer = 0x0800d8b0|1;
dp01_scratchpad = 0x020233c4;
tai_pick_move = 0x080c6f44|1;
tai_prepare_struct = 0x080c6da0|1;

/*
 * include/pokeagb/battle/data.h
 */

absent_flags_for_banks = 0x02023d70;
b_active_side = 0x02023bc4;
b_attacker = 0x02023d6b;
b_attacker_partner = 0x02023d6d;
b_attackers_in_order = 0x02023bde;
b_defender = 0x02023d6c;
b_defender_partner = 0x02023d6e;
b_message_held_item = 0x02023d68;
b_num_active_sides = 0x02023bcc;
b_pokemon_team_id_by_side = 0x02023bce;
ball_number_to_ball_processing_index = 0x080ef52c|1;
ball_palettes = 0x082605cc;
ball_tiles = 0x0826056c;
battle_data = 0x02023be4;
battle_get_per_side_status = 0x080751d8|1;
battle_get_side_with_given_state = 0x080751e8|1;
battle_side_get_owner = 0x080751c4|1;
bs_mode_pbs_index = 0x02023be2;

/*
 * include/pokeagb/battle/flags.h
 */

battle_type_flags = 0x02022b4c;
battle_type_is_double = 0x08075290|1;

/*
 * include/pokeagb/battle/menu.h
 */

battle_draw_rbox = 0x080d87bc|1;
battle_fight_menu = 0x0802ea10|1;
battle_menu_draw_cursor = 0x080309cc|1;
battle_menu_draw_move_names = 0x08030830|1;
battle_menu_draw_move_pp = 0x080308a8|1;
battle_menu_draw_move_pp_value = 0x080308cc|1;
battle_menu_draw_move_type = 0x08030940|1;
battle_menu_erase_cursor = 0x08030a14|1;
battle_menu_fight_draw = 0x08032cb4|1;
move_index_chosen_per_side = 0x02023ffc;
selected_battle_side = 0x03004ff4;

/*
 * include/pokeagb/battle/script.h
 */

battle_script_active_side = 0x02023fdb;
battle_stuff = 0x02023fe8;

/*
 * include/pokeagb/battle/trainer.h
 */

add_task_trainer_walk = 0x08081e68|1;
battle_configure_by_script = 0x08080228|1;
check_if_npc_spotted_player = 0x08081b84|1;
player_unable_to_double_battle = 0x08040cc4|1;
pokemon_purge_opponent = 0x0803da34|1;
setup_opponent_party = 0x080112e0|1;
trainer_class_money_rate = 0x0824f220;
trainer_class_names = 0x0823e558;
trainer_data = 0x0823eac8;
trainer_flag_check = 0x08080424|1;
trainer_flag_clear = 0x08080450|1;
trainer_flag_set = 0x0808043c|1;
trainerbattle_flag_id = 0x020386ae;

/*
 * include/pokeagb/battle/ui.h
 */

get_bs_elem_env_index = 0x0800fc2c|1;
hpbox_data_set = 0x08048150|1;
load_gfxc_health_bar = 0x08034964|1;
sync_hpbox_vram = 0x08049fd8|1;

/*
 * include/pokeagb/core/audio.h
 */

audio_play = 0x080722cc|1;
audio_set_mono = 0x081de7d4|1;

/*
 * include/pokeagb/core/bios.h
 */

CpuSet = 0x081e3b64|1;
lz77UnCompVram = 0x081e3b6c|1;

/*
 * include/pokeagb/core/callback.h
 */

c2_exit_to_overworld_2_switch = 0x080567dc|1;
hblank_handler_set = 0x08000700|1;
set_callback1 = 0x080565e0|1;
set_callback2 = 0x08000544|1;
super = 0x030030f0;
vblank_handler_set = 0x080006f4|1;

/*
 * include/pokeagb/core/compression.h
 */

LZ77UnCompWram = 0x081e3b70|1;
malloc_and_LZ77UnComp = 0x080f6aa0|1;

/*
 * include/pokeagb/core/io.h
 */

interrupts_disable = 0x08000b94|1;
interrupts_enable = 0x08000b68|1;
lcd_io_get = 0x08000ac4|1;
lcd_io_set = 0x08000a38|1;
REG_BG0CNT = 0x04000008;
REG_BG0HOFS = 0x04000010;
REG_BG0VOFS = 0x04000012;
REG_BG1CNT = 0x0400000a;
REG_BG1HOFS = 0x04000014;
REG_BG1VOFS = 0x04000016;
REG_BG2CNT = 0x0400000c;
REG_BG2HOFS = 0x04000018;
REG_BG2PA = 0x04000020;
REG_BG2PB = 0x04000022;
REG_BG2PC = 0x04000024;
REG_BG2PD = 0x04000026;
REG_BG2VOFS = 0x0400001a;
REG_BG2X = 0x04000028;
REG_BG2Y = 0x0400002c;
REG_BG3CNT = 0x0400000e;
REG_BG3HOFS = 0x0400001c;
REG_BG3PA = 0x04000030;
REG_BG3PB = 0x04000032;
REG_BG3PC = 0x04000034;
REG_BG3PD = 0x04000036;
REG_BG3VOFS = 0x0400001e;
REG_BG3X = 0x04000038;
REG_BG3Y = 0x0400003c;
REG_BLDALPHA = 0x04000052;
REG_BLDCNT = 0x04000050;
REG_BLDY = 0x04000054;
REG_DISPCNT = 0x04000000;
REG_DISPSTAT = 0x04000004;
REG_DMA0CNT = 0x040000b8;
REG_DMA0DAD = 0x040000b4;
REG_DMA0SAD = 0x040000b0;
REG_DMA1CNT = 0x040000c4;
REG_DMA1DAD = 0x040000c0;
REG_DMA1SAD = 0x040000bc;
REG_DMA2CNT = 0x040000d2;
REG_DMA2DAD = 0x040000cc;
REG_DMA2SAD = 0x040000c8;
REG_DMA3CNT = 0x040000de;
REG_DMA3DAD = 0x040000d8;
REG_DMA3SAD = 0x040000d4;
REG_FIFO_A = 0x040000a0;
REG_FIFO_B = 0x040000a4;
REG_HALTCNT = 0x04000301;
REG_IE = 0x04000200;
REG_IF = 0x04000202;
REG_IME = 0x04000208;
REG_JOY_RECV = 0x04000150;
REG_JOY_TRANS = 0x04000154;
REG_JOYCNT = 0x04000140;
REG_JOYSTAT = 0x04000158;
REG_KEYCNT = 0x04000132;
REG_KEYINPUT = 0x04000130;
REG_MOSAIC = 0x0400004c;
REG_POSTFLG = 0x04000300;
REG_RCNT = 0x04000134;
REG_SIOCNT = 0x04000128;
REG_SIODATA32 = 0x04000120;
REG_SIODATA8 = 0x0400012a;
REG_SIOMLT_SEND = 0x0400012a;
REG_SIOMULTI0 = 0x04000120;
REG_SIOMULTI1 = 0x04000122;
REG_SIOMULTI2 = 0x04000124;
REG_SIOMULTI3 = 0x04000126;
REG_SOUND1CNT_H = 0x04000062;
REG_SOUND1CNT_L = 0x04000060;
REG_SOUND1CNT_X = 0x04000064;
REG_SOUND2CNT_H = 0x0400006c;
REG_SOUND2CNT_L = 0x04000068;
REG_SOUND3CNT_H = 0x04000072;
REG_SOUND3CNT_L = 0x04000070;
REG_SOUND3CNT_X = 0x04000074;
REG_SOUND4CNT_H = 0x0400007c;
REG_SOUND4CNT_L = 0x04000078;
REG_SOUNDCNT_H = 0x04000082;
REG_SOUNDCNT_L = 0x04000080;
REG_SOUNDCNT_X = 0x04000084;
REG_TM0CNT_H = 0x04000102;
REG_TM0CNT_L = 0x04000100;
REG_TM1CNT_H = 0x04000106;
REG_TM1CNT_L = 0x04000104;
REG_TM2CNT_H = 0x0400010a;
REG_TM2CNT_L = 0x04000108;
REG_TM3CNT_H = 0x0400010e;
REG_TM3CNT_L = 0x0400010c;
REG_VCOUNT = 0x04000006;
REG_WAITCNT = 0x04000204;
REG_WIN0H = 0x04000040;
REG_WIN0V = 0x04000044;
REG_WIN1H = 0x04000042;
REG_WIN1V = 0x04000046;
REG_WININ = 0x04000048;
REG_WINOUT = 0x0400004a;

/*
 * include/pokeagb/core/m4a.h
 */

CgbOscOff = 0x081ddba0|1;
CgbSound = 0x081ddc6c|1;
Clear64byte = 0x081dd48c|1;
ClearChain = 0x081dd478|1;
ClearModM = 0x081de224|1;
FadeOutBody = 0x081dd97c|1;
m4aMPlayLFOSpeedSet = 0x081de2b8|1;
m4aMPlayModDepthSet = 0x081de244|1;
m4aMPlayPanpotControl = 0x081de1bc|1;
m4aMPlayPitchControl = 0x081de148|1;
m4aMPlayStop = 0x081dd93c|1;
m4aMPlayTempoControl = 0x081de0b8|1;
m4aMPlayVolumeControl = 0x081de0e0|1;
m4aSoundMode = 0x081dd63c|1;
m4aSoundVSyncOff = 0x081dd728|1;
m4aSoundVSyncOn = 0x081dd7a4|1;
MidiKeyToCgbFreq = 0x081ddaf8|1;
mplay_BGM = 0x03007300;
mplay_SE1 = 0x03007340;
mplay_SE2 = 0x03007380;
mplay_SE3 = 0x030073d0;
MPlayContinue = 0x081dcff8|1;
MPlayExtender = 0x081dd35c|1;
MPlayFadeOut = 0x081dd014|1;
MPlayJumpTableCopy = 0x081dd474|1;
mplayMemAccArea = 0x030073c0;
MPlayOpen = 0x081dd7e0|1;
MPlayStart = 0x081dd858|1;
mplayTable = 0x084a329c;
pokemon_cry_music_players = 0x03006f70;
pokemon_cry_song = 0x030072c0;
pokemon_cry_songs = 0x03006f00;
pokemon_cry_tracks = 0x03007180;
SampleFreqSet = 0x081dd598|1;
song_table = 0x084a32cc;
SoundInit = 0x081dd4a0|1;
TrkVolPitSet = 0x081dda44|1;

/*
 * include/pokeagb/core/memory.h
 */

dynamic_area = 0x02000000;
free = 0x08002bc4|1;
init_malloc = 0x08002b80|1;
malloc = 0x08002b9c|1;
malloc_and_clear = 0x08002bb0|1;
memcpy = 0x081e5e78|1;
memset = 0x081e5ed8|1;

/*
 * include/pokeagb/core/random.h
 */

rand = 0x08044ec8|1;
seed_from_timer1 = 0x08000564|1;
set_rand_seed = 0x08044ee8|1;
start_timer1 = 0x08000558|1;

/*
 * include/pokeagb/core/string.h
 */

battle_show_message = 0x080d87bc|1;
battlebox_mark_usable = 0x0800f380|1;
box_curved = 0x080f7768|1;
box_related_one = 0x080f6cd0|1;
box_status_and_type = 0x0203709c;
dialogid_was_acknowledged = 0x08002e64|1;
fcode_buffer0 = 0x02022100;
fcode_buffer2 = 0x02021cd0;
fcode_buffer3 = 0x02021cf0;
fcode_buffer4 = 0x02021d04;
fdecoder = 0x08008fcc|1;
fmt_int_10 = 0x08008e78|1;
font_get_width_of_string = 0x08005ed4|1;
pstrcat = 0x08008da4|1;
pstrcpy = 0x08008d84|1;
pstrlen = 0x08008e08|1;
rbox_init_battlebox = 0x08003b24|1;
rbox_to_vram = 0x0804a6e8|1;
rboxes = 0x020204b4;
rboxes_free = 0x08003ecc|1;
rboxid_add_812E5A4 = 0x0812e5a4|1;
rboxid_clean = 0x0810f4d8|1;
rboxid_clear_pixels = 0x0800445c|1;
rboxid_draw_text = 0x08002c48|1;
rboxid_free = 0x08003e3c|1;
rboxid_get_field = 0x08004950|1;
rboxid_init = 0x08003ce4|1;
rboxid_print = 0x0812e51c|1;
rboxid_tilemap_update = 0x08003fa0|1;
rboxid_update = 0x08003f20|1;
remo_reset_acknowledgement_flags = 0x08002c28|1;
remoboxes_upload_tilesets = 0x08002de8|1;
script_buffer_functions = 0x08231e70;
string_buffer = 0x02021d18;
textbox_close = 0x080694f4|1;
textbox_fdecode_auto_and_task_add = 0x080694c8|1;
textbox_spawn_scroll_arrows = 0x08133a20|1;
textbox_task_delete_scroll_arrows = 0x08133c30|1;
write_to_rbox = 0x0804a648|1;

/*
 * include/pokeagb/core/task.h
 */

task_add = 0x0807741c|1;
task_del = 0x08077508|1;
task_exec = 0x08077578|1;
task_find_id_by_functpr = 0x08077688|1;
task_is_running = 0x08077650|1;
tasks = 0x03005090;
tasks_init = 0x080773bc|1;

/*
 * include/pokeagb/graphics/background.h
 */

bg2_scale_bg = 0x08001e80|1;
BG_CNT = 0x04000008;
bg_config2 = 0x030008e8;
bg_positions_reset = 0x0812d594|1;
bg_vram_set = 0x08001658|1;
bg_vram_setup = 0x08001658|1;
bgid_mark_for_sync = 0x080f67a4|1;
bgid_mod_x_offset = 0x08001b90|1;
bgid_mod_y_offset = 0x08001d08|1;
bgid_nullify_tilemap = 0x08001fd4|1;
bgid_send_tilemap = 0x080020bc|1;
bgid_set_tilemap = 0x08001fa0|1;
callback_clear_and_init = 0x080f4e24|1;
copy_queue_process = 0x08007610|1;
decompress_with_fallback_maybe = 0x080f6878|1;
gpu_copy_tilemap = 0x08002040|1;
gpu_copy_to_tileset = 0x080017d0|1;
gpu_sprites_upload = 0x08007320|1;
gpu_sync_bg_hide = 0x080019d0|1;
gpu_sync_bg_show = 0x080019bc|1;
gpu_tile_bg_drop_all_sets = 0x08001618|1;
overworld_free_bgmaps = 0x080563f0|1;
rot_scale_bg = 0x08001e80|1;
textbox_something = 0x08002de8|1;
tilemaps_sync = 0x080f67b8|1;

/*
 * include/pokeagb/graphics/palette.h
 */

fade_and_return_progress_probably = 0x080704d0|1;
fade_screen = 0x08070588|1;
gpu_pal_allocator_reset = 0x080088f0|1;
gpu_pal_apply = 0x080703ec|1;
gpu_pal_apply_compressed = 0x080703a8|1;
gpu_pal_tag_search_lower_boundary = 0x03003e58;
gpu_pal_upload = 0x08070474|1;
pal_fade_control = 0x02037ab8;
pal_fade_control_and_dead_struct_reset = 0x08070528|1;
pal_fill_black = 0x0807dc00|1;
palette_bg_faded_fill_black = 0x0807db38|1;
process_palfade = 0x080704d0|1;
stdpal_get = 0x08150408|1;

/*
 * include/pokeagb/graphics/sprites.h
 */

affine_reset_all = 0x08007390|1;
anim_image_empty = 0x08231cf0;
get_pingpong = 0x08044e30|1;
gpu_pal_decompress_alloc_tag_and_upload = 0x0800f078|1;
gpu_pal_free_by_tag = 0x08008a30|1;
gpu_pal_obj_alloc_tag_and_apply = 0x08008928|1;
gpu_pal_tags = 0x03000de8;
gpu_pal_tags_index_of = 0x080089e8|1;
gpu_tile_obj_alloc_tag_and_upload = 0x080086dc|1;
gpu_tile_obj_decompress_alloc_tag_and_upload = 0x0800f034|1;
gpu_tile_obj_free_by_tag = 0x0800874c|1;
gpu_tile_obj_tag_range_for_tag = 0x08008804|1;
gpu_tile_obj_tags_reset = 0x080087c4|1;
oac_nullsub = 0x0800760c|1;
oac_pingpong = 0x08133904|1;
obj_and_aux_reset_all = 0x08006b10|1;
obj_anim_image_start = 0x0800838c|1;
obj_apply_bldpalfade = 0x08070588|1;
obj_delete = 0x080073dc|1;
obj_delete_and_free = 0x08007804|1;
obj_free = 0x080836b4|1;
obj_id_set_rotscale = 0x08075858|1;
obj_sync_something = 0x08006ba8|1;
obj_sync_superstate = 0x08006ba8|1;
objc_exec = 0x08006b5c|1;
object_clone = 0x0805fb6c|1;
objects = 0x0202063c;
rotscale_empty = 0x08231cfc;
template_instanciate_forward_search = 0x08006f8c|1;
template_instanciate_reverse_search = 0x08006fe0|1;

/*
 * include/pokeagb/misc/titlescreen.h
 */

c2_erase_save_menu = 0x080796cc|1;
c2_main_menu_or_new_game = 0x0800c300|1;

/*
 * include/pokeagb/overworld/effects.h
 */

oe_active_list_remove = 0x080837fc|1;
oe_adjust_coordinates = 0x08063bc4|1;
oe_exec = 0x08083444|1;
oe_state = 0x020386e0;
oe_stop = 0x080836d8|1;

/*
 * include/pokeagb/overworld/item.h
 */

check_item = 0x08099f40|1;
get_item_quantity = 0x0809a000|1;
items = 0x083db028;

/*
 * include/pokeagb/overworld/loading.h
 */

c1_overworld = 0x08056534|1;
c1_overworld_normal = 0x0805644c|1;
c2_overworld = 0x080565b4|1;
map_loading_loop = 0x08056e5c|1;
map_loading_loop_minimal = 0x08057300|1;
map_post_load_hook = 0x03005020;
mapldr_default = 0x0807df64|1;
new_game = 0x08054a60|1;

/*
 * include/pokeagb/overworld/map.h
 */

blockinfo_get_field = 0x08058f1c|1;
cur_mapdata_block_get_field_at = 0x08058f48|1;
cur_mapdata_get_middle2bit_at = 0x08058dc4|1;
cur_mapdata_height_mismatch = 0x080681b0|1;
currentmap_header = 0x02036dfc;
exec_battle = 0x0807f748|1;
get_map_name_index = 0x08056260|1;
get_wild_data_index_for_map = 0x08082934|1;
is_light_level_1_2_3_or_6__opensky = 0x080561fc|1;
log_coords_relative_camera = 0x08063bc4|1;
mapheader_by_mapnumbers = 0x08055238|1;
wild_pokemon_data = 0x083c9cb8;

/*
 * include/pokeagb/overworld/npc.h
 */

an_exclamation_mark = 0x08066920|1;
coordinates_move_direction = 0x08063a20|1;
npc_change_sprite = 0x0805f060|1;
npc_half_reset = 0x08063d1c|1;
npc_half_reset_no_checks = 0x08063d34|1;
npc_half_reset_when_bit7_is_set = 0x08063d7c|1;
npc_id_by_local_id = 0x0805df60|1;
npc_id_by_local_id_and_map_ret_success = 0x0805df84|1;
npc_id_by_pos_and_height = 0x0805f894|1;
npc_instanciation_something = 0x0805e72c|1;
npc_set_state_2 = 0x08063ca4|1;
npc_states = 0x02036e38;
npc_turn = 0x0805f218|1;
rom_npc_by_local_id_and_map = 0x0805fd5c|1;
walkrun_state = 0x02037078;

/*
 * include/pokeagb/overworld/ow_ui.h
 */

c2_overworld_switch_start_menu = 0x080568a8|1;
help_system_disable__sp198 = 0x0812b478|1;
safari_stepscount_close = 0x0806ef18|1;
sm_close_description = 0x080f7998|1;
sm_close_menu = 0x0806fea0|1;

/*
 * include/pokeagb/overworld/player.h
 */

player_avatar_get_type = 0x0805c808|1;

/*
 * include/pokeagb/overworld/script.h
 */

flag_check = 0x0806e6d0|1;
flag_set = 0x0806e680|1;
hm_phase_1 = 0x03005024;
script_cmds = 0x0815f9b4;
script_cmds_max = 0x0815fd08;
script_env_1 = 0x03000eb0;
script_env_2 = 0x03000f28;
script_env_2_is_enabled = 0x08069958|1;
script_env_disable = 0x0806994c|1;
script_env_enable = 0x08069940|1;
script_env_init_script = 0x08069ae4|1;
scripting_npc = 0x03005074;
select_pokemon_launch = 0x0811fb28|1;
special_9F = 0x080bf8fc|1;
special_is_finished = 0x0807aa70|1;
trade_pokemon = 0x08054440|1;
var_8000 = 0x020370b8;
var_8001 = 0x020370ba;
var_8002 = 0x020370bc;
var_8003 = 0x020370be;
var_8004 = 0x020370c0;
var_8005 = 0x020370c2;
var_8006 = 0x020370c4;
var_8007 = 0x020370c6;
var_8008 = 0x020370c8;
var_8009 = 0x020370ca;
var_800A = 0x020370cc;
var_800B = 0x020370ce;
var_800C = 0x020370be;
var_800D = 0x020370be;
var_800E = 0x020370be;
var_800F = 0x020370d2;
var_8010 = 0x020370d6;
var_8011 = 0x020370d8;
var_access = 0x0806e454|1;
var_load = 0x0806e568|1;
var_set = 0x0806e584|1;

/*
 * include/pokeagb/overworld/virtual_map.h
 */

cur_mapdata_draw_block_at = 0x0805a8e8|1;
cur_mapdata_full_redraw = 0x0805a684|1;
cur_mapdata_get_blockid_at = 0x08058e48|1;
cur_mapdata_get_height_bits_at = 0x08058d44|1;
current_map_header = 0x02036dfc;
setmaptile_four_nibbles = 0x08058fec|1;
virtual_map_data = 0x02031dfc;
virtual_map_header = 0x03005040;

/*
 * include/pokeagb/pokemon/ability.h
 */

pokemon_ability_names = 0x0824fc40;

/*
 * include/pokeagb/pokemon/base.h
 */

build_edition_identifier = 0x081e9f10;
exp_curves = 0x08253ae4;
game_language = 0x081e9f11;
pokemon_base_stats = 0x08254784;
pokemon_get_weight = 0x08088e38|1;
pokemon_names = 0x08245ee0;

/*
 * include/pokeagb/pokemon/data.h
 */

copy_pokemon_name = 0x08040fd0|1;
get_nature_from_pid = 0x08042eb4|1;
nature_stat_bonuses = 0x08252b48;
nature_stat_mod = 0x08043698|1;
party_count_pokemon = 0x08040c3e|1;
party_opponent = 0x0202402c;
party_player = 0x02024284;
pokemon_calc_checksum = 0x0803e3e8|1;
pokemon_get_gender = 0x0803f720|1;
pokemon_get_nature = 0x08042e9c|1;
pokemon_getattr = 0x0803fbe8|1;
pokemon_make = 0x0803dac4|1;
pokemon_make_full = 0x0803da54|1;
pokemon_nickname_to_string = 0x08008d28|1;
pokemon_quantity = 0x02024029;
pokemon_restore_pp = 0x080442e4|1;
pokemon_setattr = 0x0804037c|1;
pokemon_slot_purge = 0x0803d97c|1;
pokemon_slot_purge_full = 0x0803d994|1;
recalculate_stats = 0x0803e47c|1;
set_pokemon_data_2 = 0x080404d0|1;

/*
 * include/pokeagb/pokemon/evolution.h
 */

evolution_table = 0x08259754;
get_base_species = 0x08045970|1;

/*
 * include/pokeagb/pokemon/move.h
 */

pokemon_eggmoves = 0x0825ef0c;
pokemon_learnset = 0x0825d7b4;
pokemon_move_names = 0x08247094;
pokemon_moves = 0x08250c04;

/*
 * include/pokeagb/pokemon/pokedex.h
 */

dex_flag = 0x08088e74|1;
dex_flag_pokedex_index = 0x08088e74|1;
pokedex_index_to_species = 0x08043200|1;
pokedex_order = 0x08251fee;
species_to_pokedex_index = 0x08043298|1;

/*
 * include/pokeagb/pokemon/pokeicons.h
 */

gfx_heldicons = 0x0845a3ac;
load_party_icon_palette_index = 0x080971f8|1;
load_party_icon_tiles_with_form = 0x08097054|1;
pal_heldicons = 0x0845a3ec;
pokeicon_pal_indices = 0x083d3e80;
pokeicon_pals = 0x083d3740;
pokeicon_table = 0x083d37a0;
storage_hand_palette = 0x083d2bcc;
storage_hand_template = 0x083d350c;
storage_hand_tiles = 0x083d2bec;

/*
 * include/pokeagb/pokemon/sprites.h
 */

pokemon_graphics_back = 0x0823654c;
pokemon_graphics_front = 0x082350ac;
pokemon_palette_normal = 0x0823730c;
pokemon_palette_shiny = 0x082380cc;
pokemon_player_xy_table = 0x08235e6c;

/*
 * include/pokeagb/pokemon/type.h
 */

pokemon_type_names = 0x0824f1a0;

/*
 * include/pokeagb/save/block.h
 */

initialize_savebocks = 0x08054a18|1;
reset_save_mapped_memory = 0x08054a28|1;
saveblock1 = 0x03005008;
saveblock2 = 0x0300500c;
saveblock3 = 0x03005010;
saveblock_randomize_position = 0x0804c058|1;

/*
 * include/pokeagb/save/flash.h
 */

flash_load_sector = 0x080da190|1;
flash_read = 0x080da4fc|1;
flash_reset_globals = 0x080d9750|1;
flash_sector_buffer = 0x03005394;
flash_write_sector = 0x080d99d8|1;
save_calculate_checksum = 0x080da1a8|1;
save_count = 0x03005390;
save_load_result = 0x030053a0;

