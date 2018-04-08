/**
 * @file
 * @brief Internal battle commands
 */

#ifndef POKEAGB_BATTLE_COMMAND_H_
#define POKEAGB_BATTLE_COMMAND_H_

#include "../types.h"
#include "../common.h"
#include "data.h"

#define BATTLE_COMMAND_BUFFER_SIZE 0x200

enum BattleBuffer {
    BUFFER_A,
    BUFFER_B,
};

/**
 * @address{BPRE,03004FE0}
 */
extern void (*b_x[BATTLE_SIDES])(void);

/**
 * Main battle callback.
 *
 * @address{BPRE,03004F84}
 */
extern void (*b_c)(void);

/**
 * @address{BPRE,02023BC8}
 */
extern u32 b_buffers_awaiting_execution_bitfield;

/**
 * @address{BPRE,02022BC4}
 */
extern u8 b_buffer_A[BATTLE_SIDES][BATTLE_COMMAND_BUFFER_SIZE];

/**
 * @address{BPRE,020233C4}
 */
extern u8 b_buffer_B[BATTLE_SIDES][BATTLE_COMMAND_BUFFER_SIZE];

/**
 * Used to create commands before copying to b_buffer_A or b_buffer_B
 * @address{BPRE,020233C4}
 */
extern u8 dp01_scratchpad[BATTLE_COMMAND_BUFFER_SIZE];

/**
 * Prepare the AI for the current Pokemon.
 *
 * @address{BPRE,080C6DA0}
 */
POKEAGB_EXTERN void tai_prepare_struct(void);

/**
 * Uses the AI to pick a move index for the current Pokemon.
 *
 * @address{BPRE,080C6F44}
 */
POKEAGB_EXTERN u8 tai_pick_move(void);

/**
 * Mark the buffer as needing execution
 *
 * @address{BPRE,08017248}
 */
POKEAGB_EXTERN void dp01_battle_side_mark_buffer_for_execution(u8 bank);

/**
 * Select a move to attack with.
 *
 * @address{BPRE,0800E848}
 */
POKEAGB_EXTERN u8 dp01_build_cmdbuf_x21_a_bb(enum BattleBuffer buffer, u8, u16 data);

/**
 * Perform a switch in.
 *
 * @address{BPRE,0800E874}
 */
POKEAGB_EXTERN u8 dp01_build_cmdbuf_x22(enum BattleBuffer buffer, u8 index, u8);

/**
 * Play a special animation, like the castform switch.
 *
 * @address{BPRE,0800EB28}
 */
POKEAGB_EXTERN u8 dp01_build_cmdbuf_x34(enum BattleBuffer buffer, u8, u8*);

/**
 * Select a move to attack with.
 *
 * @address{BPRE,0800E0D4}
 */
POKEAGB_EXTERN u8 dp01_build_cmdbuf_x07(enum BattleBuffer buffer);

/**
 * Slide out OAM on the bank.
 *
 * @address{BPRE,0800E114}
 */
POKEAGB_EXTERN u8 dp01_build_cmdbuf_x09(enum BattleBuffer buffer);

/**
 * Display message from the battle message table.
 *
 * @address{BPRE,0800E2D4}
 */
POKEAGB_EXTERN u8 dp01_build_cmdbuf_x10(enum BattleBuffer buffer, u16 message);

/**
 * Copy a command to a buffer.
 *
 * @address{BPRE,0800D8B0}
 */
POKEAGB_EXTERN void dp01_prepare_buffer(enum BattleBuffer buffer, u8* data, u16 length);

/**
 * @address{BPRE,080155C8}
 */
POKEAGB_EXTERN void bc_bs_exec(void);

/**
 * Starts the attack.
 *
 * @address{BPRE,08015CA0}
 */
POKEAGB_EXTERN void bs0_start_attack(void);

/**
 * More like ability_everything.
 * @address{BPRE,08019F18}
 */
POKEAGB_EXTERN bool ability_something(u8 mode, u8 bank, u8 c, u16 ability_override, u16 move);

#endif /* POKEAGB_BATTLE_COMMAND_H_ */
