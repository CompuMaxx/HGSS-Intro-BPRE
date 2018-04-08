/**
 * @file
 * @brief Memory related functions.
 */

#ifndef POKEAGB_CORE_MEMORY_H_
#define POKEAGB_CORE_MEMORY_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>

#define ADDR_VRAM 0x06000000

POKEAGB_BEGIN_DECL

/**
 * Allocates a block of size bytes of memory, returning a pointer to the beginning of the block.
 *
 * @address{BPRE,08002B9C}
 */
POKEAGB_EXTERN void* malloc(u32 size);

/**
 * Allocates a block of size bytes of memory and zero fills it.
 *
 * @address{BPRE,08002BB0}
 */
POKEAGB_EXTERN void* malloc_and_clear(u32 size);

/**
 * Deallocate a block of memory previously allocated with malloc.
 *
 * @address{BPRE,08002BC4}
 */
POKEAGB_EXTERN void free(void* ptr);

/**
 * Copies size bytes from src to dst.
 *
 * @address{BPRE,081E5E78}
 */
POKEAGB_EXTERN void* memcpy(void* dst, const void* src, u32 size);

/**
 * Set size bytes at dst to value.
 *
 * @address{BPRE,081E5ED8}
 */
POKEAGB_EXTERN void memset(void* dst, u8 value, u32 size);

/**
 * @address{BPRE,08002B80}
 */
POKEAGB_EXTERN void init_malloc(void* memory, u32 size);

/**
 * @address{BPRE,02000000}
 */
extern u8 dynamic_area[0x1C000];

POKEAGB_END_DECL

#endif /* POKEAGB_CORE_MEMORY_H_ */
