/**
 * @file
 * @brief GBA IO registers
 */

#ifndef POKEAGB_CORE_IO_H_
#define POKEAGB_CORE_IO_H_

#include "../common.h"
#include "../types.h"

/* Marker macro */
#define __writeonly

/*
 * IO Registers
 */

/**
 * LCD Control
 * @address{BPRE,04000000}
 */
extern volatile u16 REG_DISPCNT;
#define REG_ID_DISPCNT 0x0

/**
 * General LCD Status (STAT LYC)
 * @address{BPRE,04000004}
 */
extern volatile u16 REG_DISPSTAT;
#define REG_ID_DISPSTAT 0x4

/**
 * Vertical Counter (LY)
 * @address{BPRE,04000006}
 */
extern volatile const u16 REG_VCOUNT;
#define REG_ID_VCOUNT 0x6

/**
 * BG0 Control
 * @address{BPRE,04000008}
 */
extern volatile u16 REG_BG0CNT;
#define REG_ID_BG0CNT 0x8

/**
 * BG1 Control
 * @address{BPRE,0400000A}
 */
extern volatile u16 REG_BG1CNT;
#define REG_ID_BG1CNT 0xA

/**
 * BG2 Control
 * @address{BPRE,0400000C}
 */
extern volatile u16 REG_BG2CNT;
#define REG_ID_BG2CNT 0xC

/**
 * BG3 Control
 * @address{BPRE,0400000E}
 */
extern volatile u16 REG_BG3CNT;
#define REG_ID_BG3CNT 0xE

/**
 * BG0 X-Offset
 * @address{BPRE,04000010}
 */
extern volatile __writeonly u16 REG_BG0HOFS;
#define REG_ID_BG0HOFS 0x10

/**
 * BG0 Y-Offset
 * @address{BPRE,04000012}
 */
extern volatile __writeonly u16 REG_BG0VOFS;
#define REG_ID_BG0VOFS 0x12

/**
 * BG1 X-Offset
 * @address{BPRE,04000014}
 */
extern volatile __writeonly u16 REG_BG1HOFS;
#define REG_ID_BG1HOFS 0x14

/**
 * BG1 Y-Offset
 * @address{BPRE,04000016}
 */
extern volatile __writeonly u16 REG_BG1VOFS;
#define REG_ID_BG1VOFS 0x16

/**
 * BG2 X-Offset
 * @address{BPRE,04000018}
 */
extern volatile __writeonly u16 REG_BG2HOFS;
#define REG_ID_BG2HOFS 0x18

/**
 * BG2 Y-Offset
 * @address{BPRE,0400001A}
 */
extern volatile __writeonly u16 REG_BG2VOFS;
#define REG_ID_BG2VOFS 0x1A

/**
 * BG3 X-Offset
 * @address{BPRE,0400001C}
 */
extern volatile __writeonly u16 REG_BG3HOFS;
#define REG_ID_BG3HOFS 0x1C

/**
 * BG3 Y-Offset
 * @address{BPRE,0400001E}
 */
extern volatile __writeonly u16 REG_BG3VOFS;
#define REG_ID_BG3VOFS 0x1E

/**
 * BG2 Rotation/Scaling Parameter A (dx)
 * @address{BPRE,04000020}
 */
extern volatile __writeonly u16 REG_BG2PA;
#define REG_ID_BG2PA 0x20

/**
 * BG2 Rotation/Scaling Parameter B (dmx)
 * @address{BPRE,04000022}
 */
extern volatile __writeonly u16 REG_BG2PB;
#define REG_ID_BG2PB 0x22

/**
 * BG2 Rotation/Scaling Parameter C (dy)
 * @address{BPRE,04000024}
 */
extern volatile __writeonly u16 REG_BG2PC;
#define REG_ID_BG2PC 0x24

/**
 * BG2 Rotation/Scaling Parameter D (dmy)
 * @address{BPRE,04000026}
 */
extern volatile __writeonly u16 REG_BG2PD;
#define REG_ID_BG2PD 0x26

/**
 * BG2 Reference Point X-Coordinate
 * @address{BPRE,04000028}
 */
extern volatile __writeonly u32 REG_BG2X;
#define REG_ID_BG2X 0x28

/**
 * BG2 Reference Point Y-Coordinate
 * @address{BPRE,0400002C}
 */
extern volatile __writeonly u32 REG_BG2Y;
#define REG_ID_BG2Y 0x2C

/**
 * BG3 Rotation/Scaling Parameter A (dx)
 * @address{BPRE,04000030}
 */
extern volatile __writeonly u16 REG_BG3PA;
#define REG_ID_BG3PA 0x30

/**
 * BG3 Rotation/Scaling Parameter B (dmx)
 * @address{BPRE,04000032}
 */
extern volatile __writeonly u16 REG_BG3PB;
#define REG_ID_BG3PB 0x32

/**
 * BG3 Rotation/Scaling Parameter C (dy)
 * @address{BPRE,04000034}
 */
extern volatile __writeonly u16 REG_BG3PC;
#define REG_ID_BG3PC 0x34

/**
 * BG3 Rotation/Scaling Parameter D (dmy)
 * @address{BPRE,04000036}
 */
extern volatile __writeonly u16 REG_BG3PD;
#define REG_ID_BG3PD 0x36

/**
 * BG3 Reference Point X-Coordinate
 * @address{BPRE,04000038}
 */
extern volatile __writeonly u32 REG_BG3X;
#define REG_ID_BG3X 0x38

/**
 * BG3 Reference Point Y-Coordinate
 * @address{BPRE,0400003C}
 */
extern volatile __writeonly u32 REG_BG3Y;
#define REG_ID_BG3Y 0x3C

/**
 * Window 0 Horizontal Dimensions
 * @address{BPRE,04000040}
 */
extern volatile __writeonly u16 REG_WIN0H;
#define REG_ID_WIN0H 0x40

/**
 * Window 1 Horizontal Dimensions
 * @address{BPRE,04000042}
 */
extern volatile __writeonly u16 REG_WIN1H;
#define REG_ID_WIN1H 0x42

/**
 * Window 0 Vertical Dimensions
 * @address{BPRE,04000044}
 */
extern volatile __writeonly u16 REG_WIN0V;
#define REG_ID_WIN0V 0x44

/**
 * Window 1 Vertical Dimensions
 * @address{BPRE,04000046}
 */
extern volatile __writeonly u16 REG_WIN1V;
#define REG_ID_WIN1V 0x46

/**
 * Inside of Window 0 and 1
 * @address{BPRE,04000048}
 */
extern volatile u16 REG_WININ;
#define REG_ID_WININ 0x48

/**
 * Inside of OBJ Window & Outside of Windows
 * @address{BPRE,0400004A}
 */
extern volatile u16 REG_WINOUT;
#define REG_ID_WINOUT 0x4A

/**
 * Mosaic Size
 * @address{BPRE,0400004C}
 */
extern volatile __writeonly u16 REG_MOSAIC;
#define REG_ID_MOSAIC 0x4C

/**
 * Color Special Effects Selection
 * @address{BPRE,04000050}
 */
extern volatile u16 REG_BLDCNT;
#define REG_ID_BLDCNT 0x50

/**
 * Alpha Blending Coefficients
 * @address{BPRE,04000052}
 */
extern volatile __writeonly u16 REG_BLDALPHA;
#define REG_ID_BLDALPHA 0x52

/**
 * Brightness (Fade-In/Out) Coefficient
 * @address{BPRE,04000054}
 */
extern volatile __writeonly u16 REG_BLDY;
#define REG_ID_BLDY 0x54

/**
 * Channel 1 Sweep register       (NR10)
 * @address{BPRE,04000060}
 */
extern volatile u16 REG_SOUND1CNT_L;
#define REG_ID_SOUND1CNT_L 0x60

/**
 * Channel 1 Duty/Length/Envelope (NR11  NR12)
 * @address{BPRE,04000062}
 */
extern volatile u16 REG_SOUND1CNT_H;
#define REG_ID_SOUND1CNT_H 0x62

/**
 * Channel 1 Frequency/Control    (NR13  NR14)
 * @address{BPRE,04000064}
 */
extern volatile u16 REG_SOUND1CNT_X;
#define REG_ID_SOUND1CNT_X 0x64

/**
 * Channel 2 Duty/Length/Envelope (NR21  NR22)
 * @address{BPRE,04000068}
 */
extern volatile u16 REG_SOUND2CNT_L;
#define REG_ID_SOUND2CNT_L 0x68

/**
 * Channel 2 Frequency/Control    (NR23  NR24)
 * @address{BPRE,0400006C}
 */
extern volatile u16 REG_SOUND2CNT_H;
#define REG_ID_SOUND2CNT_H 0x6C

/**
 * Channel 3 Stop/Wave RAM select (NR30)
 * @address{BPRE,04000070}
 */
extern volatile u16 REG_SOUND3CNT_L;
#define REG_ID_SOUND3CNT_L 0x70

/**
 * Channel 3 Length/Volume        (NR31  NR32)
 * @address{BPRE,04000072}
 */
extern volatile u16 REG_SOUND3CNT_H;
#define REG_ID_SOUND3CNT_H 0x72

/**
 * Channel 3 Frequency/Control    (NR33  NR34)
 * @address{BPRE,04000074}
 */
extern volatile u16 REG_SOUND3CNT_X;
#define REG_ID_SOUND3CNT_X 0x74

/**
 * Channel 4 Length/Envelope      (NR41  NR42)
 * @address{BPRE,04000078}
 */
extern volatile u16 REG_SOUND4CNT_L;
#define REG_ID_SOUND4CNT_L 0x78

/**
 * Channel 4 Frequency/Control    (NR43  NR44)
 * @address{BPRE,0400007C}
 */
extern volatile u16 REG_SOUND4CNT_H;
#define REG_ID_SOUND4CNT_H 0x7C

/**
 * Control Stereo/Volume/Enable   (NR50  NR51)
 * @address{BPRE,04000080}
 */
extern volatile u16 REG_SOUNDCNT_L;
#define REG_ID_SOUNDCNT_L 0x80

/**
 * Control Mixing/DMA Control
 * @address{BPRE,04000082}
 */
extern volatile u16 REG_SOUNDCNT_H;
#define REG_ID_SOUNDCNT_H 0x82

/**
 * Control Sound on/off           (NR52)
 * @address{BPRE,04000084}
 */
extern volatile u16 REG_SOUNDCNT_X;
#define REG_ID_SOUNDCNT_X 0x84

/**
 * Channel A FIFO  Data 0-3
 * @address{BPRE,040000A0}
 */
extern volatile __writeonly u32 REG_FIFO_A;
#define REG_ID_FIFO_A 0xA0

/**
 * Channel B FIFO  Data 0-3
 * @address{BPRE,040000A4}
 */
extern volatile __writeonly u32 REG_FIFO_B;
#define REG_ID_FIFO_B 0xA4

/**
 * DMA 0 Source Address
 * @address{BPRE,040000B0}
 */
extern volatile __writeonly u32 REG_DMA0SAD;
#define REG_ID_DMA0SAD 0xB0

/**
 * DMA 0 Destination Address
 * @address{BPRE,040000B4}
 */
extern volatile __writeonly u32 REG_DMA0DAD;
#define REG_ID_DMA0DAD 0xB4

/**
 * DMA 0 Word Count
 * @address{BPRE,040000B8}
 */
extern volatile u32 REG_DMA0CNT;
#define REG_ID_DMA0CNT 0xB8

/**
 * DMA 1 Source Address
 * @address{BPRE,040000BC}
 */
extern volatile __writeonly u32 REG_DMA1SAD;
#define REG_ID_DMA1SAD 0xBC

/**
 * DMA 1 Destination Address
 * @address{BPRE,040000C0}
 */
extern volatile __writeonly u32 REG_DMA1DAD;
#define REG_ID_DMA1DAD 0xC0

/**
 * DMA 1 Word Count
 * @address{BPRE,040000C4}
 */
extern volatile u32 REG_DMA1CNT;
#define REG_ID_DMA1CNT 0xC4

/**
 * DMA 2 Source Address
 * @address{BPRE,040000C8}
 */
extern volatile __writeonly u32 REG_DMA2SAD;
#define REG_ID_DMA2SAD 0xC8

/**
 * DMA 2 Destination Address
 * @address{BPRE,040000CC}
 */
extern volatile __writeonly u32 REG_DMA2DAD;
#define REG_ID_DMA2DAD 0xCC

/**
 * DMA 2 Control
 * @address{BPRE,040000D2}
 */
extern volatile u32 REG_DMA2CNT;
#define REG_ID_DMA2CNT 0xD2

/**
 * DMA 3 Source Address
 * @address{BPRE,040000D4}
 */
extern volatile __writeonly u32 REG_DMA3SAD;
#define REG_ID_DMA3SAD 0xD4

/**
 * DMA 3 Destination Address
 * @address{BPRE,040000D8}
 */
extern volatile __writeonly u32 REG_DMA3DAD;
#define REG_ID_DMA3DAD 0xD8

/**
 * DMA 3 Control
 * @address{BPRE,040000DE}
 */
extern volatile u32 REG_DMA3CNT;
#define REG_ID_DMA3CNT 0xDE

/**
 * Timer 0 Counter/Reload
 * @address{BPRE,04000100}
 */
extern volatile u16 REG_TM0CNT_L;
#define REG_ID_TM0CNT_L 0x100

/**
 * Timer 0 Control
 * @address{BPRE,04000102}
 */
extern volatile u16 REG_TM0CNT_H;
#define REG_ID_TM0CNT_H 0x102

/**
 * Timer 1 Counter/Reload
 * @address{BPRE,04000104}
 */
extern volatile u16 REG_TM1CNT_L;
#define REG_ID_TM1CNT_L 0x104

/**
 * Timer 1 Control
 * @address{BPRE,04000106}
 */
extern volatile u16 REG_TM1CNT_H;
#define REG_ID_TM1CNT_H 0x106

/**
 * Timer 2 Counter/Reload
 * @address{BPRE,04000108}
 */
extern volatile u16 REG_TM2CNT_L;
#define REG_ID_TM2CNT_L 0x108

/**
 * Timer 2 Control
 * @address{BPRE,0400010A}
 */
extern volatile u16 REG_TM2CNT_H;
#define REG_ID_TM2CNT_H 0x10A

/**
 * Timer 3 Counter/Reload
 * @address{BPRE,0400010C}
 */
extern volatile u16 REG_TM3CNT_L;
#define REG_ID_TM3CNT_L 0x10C

/**
 * Timer 3 Control
 * @address{BPRE,0400010E}
 */
extern volatile u16 REG_TM3CNT_H;
#define REG_ID_TM3CNT_H 0x10E

/**
 * SIO Data (Normal-32bit Mode; shared with below)
 * @address{BPRE,04000120}
 */
extern volatile u32 REG_SIODATA32;
#define REG_ID_SIODATA32 0x120

/**
 * SIO Data 0 (Parent)    (Multi-Player Mode)
 * @address{BPRE,04000120}
 */
extern volatile u16 REG_SIOMULTI0;
#define REG_ID_SIOMULTI0 0x120

/**
 * SIO Data 1 (1st Child) (Multi-Player Mode)
 * @address{BPRE,04000122}
 */
extern volatile u16 REG_SIOMULTI1;
#define REG_ID_SIOMULTI1 0x122

/**
 * SIO Data 2 (2nd Child) (Multi-Player Mode)
 * @address{BPRE,04000124}
 */
extern volatile u16 REG_SIOMULTI2;
#define REG_ID_SIOMULTI2 0x124

/**
 * SIO Data 3 (3rd Child) (Multi-Player Mode)
 * @address{BPRE,04000126}
 */
extern volatile u16 REG_SIOMULTI3;
#define REG_ID_SIOMULTI3 0x126

/**
 * SIO Control Register
 * @address{BPRE,04000128}
 */
extern volatile u16 REG_SIOCNT;
#define REG_ID_SIOCNT 0x128

/**
 * SIO Data (Local of MultiPlayer; shared below)
 * @address{BPRE,0400012A}
 */
extern volatile u16 REG_SIOMLT_SEND;
#define REG_ID_SIOMLT_SEND 0x12A

/**
 * SIO Data (Normal-8bit and UART Mode)
 * @address{BPRE,0400012A}
 */
extern volatile u16 REG_SIODATA8;
#define REG_ID_SIODATA8 0x12A

/**
 * Key Status
 * @address{BPRE,04000130}
 */
extern volatile const u16 REG_KEYINPUT;
#define REG_ID_KEYINPUT 0x130

/**
 * Key Interrupt Control
 * @address{BPRE,04000132}
 */
extern volatile u16 REG_KEYCNT;
#define REG_ID_KEYCNT 0x132

/**
 * SIO Mode Select/General Purpose Data
 * @address{BPRE,04000134}
 */
extern volatile u16 REG_RCNT;
#define REG_ID_RCNT 0x134

/**
 * SIO JOY Bus Control
 * @address{BPRE,04000140}
 */
extern volatile u16 REG_JOYCNT;
#define REG_ID_JOYCNT 0x140

/**
 * SIO JOY Bus Receive Data
 * @address{BPRE,04000150}
 */
extern volatile u32 REG_JOY_RECV;
#define REG_ID_JOY_RECV 0x150

/**
 * SIO JOY Bus Transmit Data
 * @address{BPRE,04000154}
 */
extern volatile u32 REG_JOY_TRANS;
#define REG_ID_JOY_TRANS 0x154

/**
 * SIO JOY Bus Receive Status
 * @address{BPRE,04000158}
 */
extern volatile const u16 REG_JOYSTAT;
#define REG_ID_JOYSTAT 0x158

/**
 * Interrupt Enable Register
 * @address{BPRE,04000200}
 */
extern volatile u16 REG_IE;
#define REG_ID_IE 0x200

/**
 * Interrupt Request Flags / IRQ Acknowledge
 * @address{BPRE,04000202}
 */
extern volatile u16 REG_IF;
#define REG_ID_IF 0x202

/**
 * Game Pak Waitstate Control
 * @address{BPRE,04000204}
 */
extern volatile u16 REG_WAITCNT;
#define REG_ID_WAITCNT 0x204

/**
 * Interrupt Master Enable Register
 * @address{BPRE,04000208}
 */
extern volatile u16 REG_IME;
#define REG_ID_IME 0x208

/**
 * Undocumented - Post Boot Flag
 * @address{BPRE,04000300}
 */
extern volatile u8 REG_POSTFLG;
#define REG_ID_POSTFLG 0x300

/**
 * Undocumented - Power Down Control
 * @address{BPRE,04000301}
 */
extern volatile __writeonly u8 REG_HALTCNT;
#define REG_ID_HALTCNT 0x301

/*
 * IO Register Values
 */

#define DISPCNT_MODE_MASK 7
#define DISPCNT_MODE0 (0 << 0)
#define DISPCNT_MODE1 (1 << 0)
#define DISPCNT_MODE2 (2 << 0)
#define DISPCNT_MODE3 (3 << 0)
#define DISPCNT_MODE4 (4 << 0)
#define DISPCNT_MODE5 (5 << 0)
/**
 * Indicates GameBoy Color mode. Read-only.
 */
#define DISPCNT_CGB (1 << 3)
/**
 * In BG Modes 4 and 5, this indicates the current page for page-flipping (double buffering).
 */
#define DISPCNT_PAGE (1 << 4)
/**
 * Allows OAM to be updated in H-Blank. Using this feature reduces the
 * number of sprites that can be displayed per line.
 */
#define DISPCNT_OAM_HBLANK (1 << 5)
#define DISPCNT_OAM_1D (1 << 6)
/**
 * Forced VBlank
 */
#define DISPCNT_BLANK (1 << 7)
#define DISPCNT_BG0 (1 << 8)
#define DISPCNT_BG1 (1 << 9)
#define DISPCNT_BG2 (1 << 10)
#define DISPCNT_BG3 (1 << 11)
#define DISPCNT_OBJ (1 << 12)
#define DISPCNT_WIN0 (1 << 13)
#define DISPCNT_WIN1 (1 << 14)
#define DISPCNT_WINOBJ (1 << 15)

#define DISPSTAT_VBLANK_FLAG (1 << 0)
#define DISPSTAT_HBLANK_FLAG (1 << 1)
#define DISPSTAT_VCOUNT_FLAG (1 << 2)
#define DISPSTAT_VBLANK_IRQ (1 << 3)
#define DISPSTAT_HBLANK_IRQ (1 << 4)
#define DISPSTAT_VCOUNT_IRQ (1 << 5)
/**
 * @param mode Interrupts to enable
 * @param vcount VCOUNT value to trigger VCOUNT IRQ at
 */
#define DISPSTAT_BUILD(mode, vcount) ((mode) | ((vcount) << 8))

#define WIN_BG0 (1 << 0)
#define WIN_BG1 (1 << 1)
#define WIN_BG2 (1 << 2)
#define WIN_BG3 (1 << 3)
#define WIN_OBJ (1 << 4)
#define WIN_BLD (1 << 5)
/**
 * @param win0 Window 0 Control
 * @param win1 Window 1 Control
 */
#define WININ_BUILD(win0, win1) ((win0) | ((win1) << 8))
/**
 * @param outside Window Outside Control
 * @param object Object Window Control
 */
#define WINOUT_BUILD(outside, object) ((outside) | ((object) << 8))

#define BLDCNT_BG0_SRC (1 << 0)
#define BLDCNT_BG1_SRC (1 << 1)
#define BLDCNT_BG2_SRC (1 << 2)
#define BLDCNT_BG3_SRC (1 << 3)
#define BLDCNT_SPRITES_SRC (1 << 4)
#define BLDCNT_BACKDROP_SRC (1 << 5)
#define BLDCNT_BLEND_MODE_MASK (3 << 6)
#define BLDCNT_ALPHA_BLEND (1 << 6)
#define BLDCNT_LIGHTEN (2 << 6)
#define BLDCNT_DARKEN (3 << 6)
#define BLDCNT_BG0_DST (1 << 8)
#define BLDCNT_BG1_DST (1 << 9)
#define BLDCNT_BG2_DST (1 << 10)
#define BLDCNT_BG3_DST (1 << 11)
#define BLDCNT_SPRITES_DST (1 << 12)
#define BLDCNT_BACKDROP_DST (1 << 13)

/**
 * @param eva EVA Coefficient (1st Target) (0..16 = 0/16..16/16, 17..31=16/16)
 * @param ebv EVB Coefficient (2nd Target) (0..16 = 0/16..16/16, 17..31=16/16)
 */
#define BLDALPHA_BUILD(eva, evb) ((eva) | ((evb) << 8))

#define DMA_COUNT_MASK 0xFFFF

#define DMA_DST_INC (0 << 0x15)
#define DMA_DST_DEC (1 << 0x15)
#define DMA_DST_FIXED (2 << 0x15)
#define DMA_DST_RELOAD (3 << 0x15)
#define DMA_DST_MODE_MASK (3 << 0x15)

#define DMA_SRC_INC (0 << 0x17)
#define DMA_SRC_DEC (1 << 0x17)
#define DMA_SRC_FIXED (2 << 0x17)
#define DMA_SRC_MODE_MASK (3 << 0x17)

#define DMA_REPEAT (1 << 0x19)

#define DMA_16 (0 << 0x1A)
#define DMA_32 (1 << 0x1A)

#define DMA_NOW (0 << 0x1C)
#define DMA_AT_VBLANK (1 << 0x1C)
#define DMA_AT_HBLANK (2 << 0x1C)
#define DMA_AT_REFRESH (3 << 0x1C)

#define DMA_IRQ (1 << 0x1E)
#define DMA_ENABLE (1 << 0x1F)

/*
 * GameFreak Engine IO register buffer and helper functions
 */

/**
 * @param reg_id The register to modify (REG_ID_X)
 * @address{BPRE,08000A38}
 */
POKEAGB_EXTERN void lcd_io_set(u8 reg_id, u16 value);

/**
 * @param reg_id The register to read (REG_ID_X)
 * @address{BPRE,08000AC4}
 */
POKEAGB_EXTERN u16 lcd_io_get(u8 reg_id);

enum Interrupts {
    INTERRUPT_VBLANK = (1 << 0),
    INTERRUPT_HBLANK = (1 << 1),
};

/**
 * @address{BPRE,08000B68}
 */
POKEAGB_EXTERN void interrupts_enable(enum Interrupts disable);

/**
 * @address{BPRE,08000B94}
 */
POKEAGB_EXTERN void interrupts_disable(enum Interrupts disable);

#endif /* POKEAGB_CORE_IO_H_ */
