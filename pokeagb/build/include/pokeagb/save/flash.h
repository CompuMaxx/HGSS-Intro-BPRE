/**
 * @file
 * @brief Flash memory functions for saving.
 */

#ifndef POKEAGB_SAVE_FLASH_H_
#define POKEAGB_SAVE_FLASH_H_

POKEAGB_BEGIN_DECL

#define FLASH_SECTORS 32
#define FLASH_SECTOR_SIZE 4096
#define FLASH_SECTOR_MAGIC 0x08012025
#define FLASH_SAVE_SECTORS 14

struct SaveSectorMeta {
    u16 id;
    u16 checksum;
    u32 magic;
    u32 counter;
};

#define FLASH_SECTOR_DATA_SIZE (FLASH_SECTOR_SIZE - sizeof(struct SaveSectorMeta))

struct SaveSector {
    u8 data[FLASH_SECTOR_DATA_SIZE];
    struct SaveSectorMeta meta;
};

ASSERT_SIZEOF(struct SaveSector, FLASH_SECTOR_SIZE);

/**
 * @address{BPRE,03005394}
 */
extern struct SaveSector* flash_sector_buffer;

/**
 * Reads a sector into the buffer from flash memory.
 * @param sector A number less than FLASH_SECTORS
 * @param buffer A buffer of at least FLASH_SECTOR_SIZE bytes
 * @return Always 1
 * @address{BPRE,080DA190}
 */
POKEAGB_EXTERN int flash_load_sector(u16 sector, void* buffer);

/**
 * Reads a sector into flash memory.
 * @param sector A number less than FLASH_SECTORS
 * @param buffer A buffer of at least FLASH_SECTOR_SIZE bytes
 * @address{BPRE,080D99D8}
 */
POKEAGB_EXTERN int flash_write_sector(u16 sector, void* buffer);

/**
 * Calculates a checksum for saving.
 * @address{BPRE,080DA1A8}
 */
POKEAGB_EXTERN u16 save_calculate_checksum(void* data, u16 size);

/**
 * The number of times the game has been saved.
 * @address{BPRE,03005390}
 */
extern u32 save_count;

/**
 * Move the saveblocks around.
 * @address{BPRE,0804C058}
 */
POKEAGB_EXTERN void saveblock_randomize_position(void);

/**
 * Reset globals used for tracking save failure and count.
 * @address{BPRE,080D9750}
 */
POKEAGB_EXTERN void flash_reset_globals(void);

/**
 * Read the saved game.
 * @address{BPRE,080DA4FC}
 */
POKEAGB_EXTERN void flash_read(u8 mode);

/**
 * The result of reading the save.
 * @address{BPRE,030053A0}
 */
extern u16 save_load_result;

POKEAGB_END_DECL

#endif /* POKEAGB_SAVE_FLASH_H_ */
