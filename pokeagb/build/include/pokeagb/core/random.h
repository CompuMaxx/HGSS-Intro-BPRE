/**
 * @file
 * @brief PRNG.
 */

#ifndef POKEAGB_CORE_RANDOM_H_
#define POKEAGB_CORE_RANDOM_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>

POKEAGB_BEGIN_DECL

#define RAND_MAX 0xFFFF

/**
 * Generate a pseudo-random integer between 0 and RAND_MAX.
 *
 * @address{BPRE,08044EC8}
 */
POKEAGB_EXTERN u16 rand();

/**
 * Initialize the PRNG with seed.
 *
 * @address{BPRE,08044EE8}
 */
POKEAGB_EXTERN void set_rand_seed(u16 seed);

/**
 * Start TM1CNT. Used for gathering entropy.
 * @address{BPRE,08000558}
 */
void start_timer1(void);

/**
 * Gather entropy setting the seed to the amount of time it takes for
 * the player perform a given action.
 * @address{BPRE,08000564}
 */
void seed_from_timer1(void);

POKEAGB_END_DECL

#endif /* POKEAGB_CORE_RANDOM_H_ */
