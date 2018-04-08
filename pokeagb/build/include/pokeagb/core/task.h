/**
 * @file
 * @brief Game engine tasks.
 */

#ifndef POKEAGB_CORE_TASK_H_
#define POKEAGB_CORE_TASK_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>

POKEAGB_BEGIN_DECL

/**
 * Task function.
 *
 * @param id The ID of the the current task
 */
typedef void (*TaskCallback)(u8 id);

/**
 * A short-lived background function with state.
 */
struct Task {
    TaskCallback function; /**< Function to run */
    bool inuse;
    u8 prev;
    u8 next;
    u8 priority;
    s16 priv[16]; /**< State variables */
};

/**
 * Start a new task.
 *
 * @param func Function pointer
 * @return Task ID
 * @address{BPRE,0807741C}
 */
POKEAGB_EXTERN u8 task_add(TaskCallback func, u8 priority);

/**
 * Delete a task.
 * @address{BPRE,08077508}
 */
POKEAGB_EXTERN void task_del(u8 id);

/**
 * Execute all active tasks once.
 * @address{BPRE,08077578}
 */
POKEAGB_EXTERN void task_exec(void);

/**
 * All the tasks.
 * @address{BPRE,03005090}
 */
extern struct Task tasks[16];

/**
 * Check if the given task is running.
 *
 * @address{BPRE,08077650}
 */
POKEAGB_EXTERN bool task_is_running(TaskCallback func);

/**
 * Find the ID of first task running the given function.
 *
 * @returns Task ID or 255 on failure
 * @address{BPRE,08077688}
 */
POKEAGB_EXTERN u8 task_find_id_by_functpr(TaskCallback func);

/**
 * @address{BPRE,080773BC}
 */
POKEAGB_EXTERN void tasks_init(void);

POKEAGB_END_DECL

#endif /* POKEAGB_CORE_TASK_H_ */
