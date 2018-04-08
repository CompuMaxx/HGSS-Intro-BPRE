/**
 * @file
 * @brief Overworld scripting.
 */

#ifndef POKEAGB_OVERWORLD_SCRIPT_H_
#define POKEAGB_OVERWORLD_SCRIPT_H_

#include <pokeagb/common.h>
#include <pokeagb/types.h>
#include <pokeagb/core/callback.h>

POKEAGB_BEGIN_DECL

struct ScriptEnvironment;

/**
 * @return 0 to indicate succcess, 1 to enter wait state.
 */
typedef u8 (*ScriptCommand)(struct ScriptEnvironment* environment);

typedef u8 (*HMTask)(void);

/**
 * @return 1 when finished, 0 to keep executing.
 */
typedef u8 (*ScriptFunction)(void);

enum ScriptExecutionMode {
    /** The environment is not executing anything (wait state). */
    SCRIPT_EXECUTE_MODE_PAUSED,

    /** Normal script execution mode. */
    SCRIPT_EXECUTE_MODE_NORMAL,

    /** Executing pointer_asm function. */
    SCRIPT_EXECUTE_MODE_ASM,
};

struct ScriptEnvironment {
    /**
     * Call stack depth.
     */
    u8 depth;

    /**
     * Execution mode.
     */
    enum ScriptExecutionMode mode;

    /**
     * Function to run.
     */
    u8 cmp_result;
    u8 field_3;

    /**
     * Pointer to a function.  Executed when mode ==
     * SCRIPT_EXECUTE_MODE_ASM
     */
    ScriptFunction pointer_asm;

    /**
     * Pointer to a script.  Executed when mode ==
     * SCRIPT_EXECUTE_MODE_NORMAL
     */
    u8* pointer_script;

    /**
     * Call stack.
     */
    u8* stack[20];

    /**
     * Pointer to script commands.  This means we can hot swap
     * scripting commands to implent an ad-hoc custom script engine,
     * like the engine does with mystery gift. */
    ScriptCommand* cmd_table;

    /**
     * Pointer to the last command in the table.
     */
    ScriptCommand* cmd_table_max;

    /**
     * Script banks.  Bank 0 is used for loading a pointer to a message to display.
     */
    u32 vars[4];

    /**
     * Usually set to false during cutscenes.
     */
    bool enabled;
    u8 field_75;

    /**
     * Whether to enable the keypad.  Set to true during signpost
     * scripts so you can walk away to cancel the script.
     */
    u8 keypad_control_enabled;

    /**
     * Locks player movement.
     */
    u8 keypad_override_direction;
};

ASSERT_SIZEOF(struct ScriptEnvironment, 0x78);

/**
 * Primary script environment for regular scripts.
 *
 * @address{BPRE,03000EB0}
 */
extern struct ScriptEnvironment script_env_1;

/**
 * Secondary script environment for level scripts.
 *
 * @address{BPRE,03000F28}
 */
extern struct ScriptEnvironment script_env_2;

/**
 * Start of standard script command table.
 *
 * @address{BPRE,0815F9B4}
 */
extern ScriptCommand* script_cmds;

/**
 * End of standard script command table.
 *
 * @address{BPRE,0815FD08}
 */
extern ScriptCommand* script_cmds_max;

/**
 * Script temporary variable 0x8000
 * @address{BPRE,020370B8}
 */
extern u16 var_8000;

/**
 * Script temporary variable 0x8001
 * @address{BPRE,020370BA}
 */
extern u16 var_8001;

/**
 * Script temporary variable 0x8002
 * @address{BPRE,020370BC}
 */
extern u16 var_8002;

/**
 * Script temporary variable 0x8003
 * @address{BPRE,020370BE}
 */
extern u16 var_8003;

/**
 * Script temporary variable 0x8004
 * @address{BPRE,020370C0}
 */
extern u16 var_8004;

/**
 * Script temporary variable 0x8005
 * @address{BPRE,020370C2}
 */
extern u16 var_8005;

/**
 * Script temporary variable 0x8006
 * @address{BPRE,020370C4}
 */
extern u16 var_8006;

/**
 * Script temporary variable 0x8007
 * @address{BPRE,020370C6}
 */
extern u16 var_8007;

/**
 * Script temporary variable 0x8008
 * @address{BPRE,020370C8}
 */
extern u16 var_8008;

/**
 * Script temporary variable 0x8009
 * @address{BPRE,020370CA}
 */
extern u16 var_8009;

/**
 * Script temporary variable 0x800A
 * @address{BPRE,020370CC}
 */
extern u16 var_800A;

/**
 * Script temporary variable 0x800B
 * @address{BPRE,020370CE}
 */
extern u16 var_800B;

/**
 * Script temporary variable 0x800C
 * @address{BPRE,020370BE}
 */
extern u16 var_800C;

/**
 * Script temporary variable 0x800D
 * @address{BPRE,020370BE}
 */
extern u16 var_800D;

/**
 * Script temporary variable 0x800E
 * @address{BPRE,020370BE}
 */
extern u16 var_800E;

/**
 * Local ID of the NPC last spoken to.
 * @address{BPRE,020370D2}
 */
extern u16 var_800F;

/**
 * Script temporary variable 0x8010
 * @address{BPRE,020370D6}
 */
extern u16 var_8010;

/**
 * Script temporary variable 0x8011
 * @address{BPRE,020370D8}
 */
extern u16 var_8011;


/**
 * Read the value in a script variable
 * @address{BPRE,0806E568}
 */
POKEAGB_EXTERN u16 var_load(u16 variable);

/**
 * Read the value in a script variable
 * @address{BPRE,0806E454}
 */
POKEAGB_EXTERN u16* var_access(u16 variable);

/**
 * Set a value to a script variable
 * @address{BPRE,0806E584}
 */
POKEAGB_EXTERN u16* var_set(u16 variable, u16 value);

/**
 * NPC state id of the NPC running the script
 * @address{BPRE,03005074}
 */
extern u8 scripting_npc;

/**
 * Initialise the script state with the given instruction pointer.
 * @address{BPRE,08069AE4}
 */
POKEAGB_EXTERN void script_env_init_script(void* script);

/**
 * Mark state as script is running
 * @address{BPRE,08069940}
 */
POKEAGB_EXTERN void script_env_enable(void);

/**
 * Mark state as script is not running
 * @address{BPRE,0806994C}
 */
POKEAGB_EXTERN void script_env_disable(void);

/**
 * Set a flag
 * @address{BPRE,0806E680}
 */
POKEAGB_EXTERN void flag_set(u16 flag);

/**
 * Check a flag's status
 * @address{BPRE,0806E6D0}
 */
 POKEAGB_EXTERN bool flag_check(u16 flag);

/**
 * Check script_env_2 is enabled 
 * @address{BPRE,08069958}
 */
POKEAGB_EXTERN bool script_env_2_is_enabled(void);


/**
 * Function holder to be executed
 * @address{BPRE,03005024}
 */
extern HMTask hm_phase_1;

/**
 * Special 0x9F
 * @address{BPRE,080BF8FC}
 */
POKEAGB_EXTERN void special_9F(void);


/**
 * Special completed check
 * @address{BPRE,0807AA70}
 */
POKEAGB_EXTERN u8 special_is_finished(void);

/**
 * Select pokemon launch
 * @address{BPRE,0811FB28}
 */
POKEAGB_EXTERN void select_pokemon_launch(u8, u8, u8, u8, u8, SuperCallback);

/**
 * Trades Pokemon in slot indicated by var 08004, with opponent's first slot pkmn.
 * @address{BPRE,08054440}
 */
POKEAGB_EXTERN void trade_pokemon(void);

POKEAGB_END_DECL

#endif /* POKEAGB_OVERWORLD_SCRIPT_H_ */
