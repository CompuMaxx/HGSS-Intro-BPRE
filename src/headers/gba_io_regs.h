//
// I/O Registers
//
 
#ifndef GBA_IO_REGS_H
#define GBA_IO_REGS_H
 
#define OAM_Data        ((u16*)0x6010000) // Sprite data (bitmapped)
#define FrontBuffer     ((u16*)0x6000000) // Front Display Memory (the screen in mode 3-5)
 
// LCD I/O Display Control
#define DISPCNT			*(u16*)0X4000000 // LCD Control (Read/Write)

// LCD I/O Interrupts and Status 
#define DISPSTAT		*(u16*)0x4000004 // General LCD Status (R/W)
#define VCOUNT			*(volatile u16*)0x4000006  // Vertical Counter (R)
#define vsync() while(REG_VCOUNT != 160);

// LCD I/O BG Control 
#define BG0CNT			*(u16*)0x4000008 // BG0 Control (R/W) (BG Modes 0,1 only)
#define BG1CNT			*(u16*)0x400000A // BG1 Control (R/W) (BG Modes 0,1 only)
#define BG2CNT			*(u16*)0x400000C // BG2 Control (R/W) (BG Modes 0,1,2 only)
#define BG3CNT			*(u16*)0x400000E // BG3 Control (R/W) (BG Modes 0,2 only)

// LCD I/O BG Scrolling 
#define BG0HOFF			*(u16*)0x4000010 // BG0 X-Offset (W)
#define BG0VOFF			*(u16*)0x4000012 // BG0 Y-Offset (W)
#define BG1HOFF			*(u16*)0x4000014 // BG1 X-Offset (W)
#define BG1VOFF			*(u16*)0x4000016 // BG1 Y-Offset (W)
#define BG2HOFF			*(u16*)0x4000018 // BG2 X-Offset (W)
#define BG2VOFF			*(u16*)0x400001A // BG2 Y-Offset (W)
#define BG3HOFF			*(u16*)0x400001C // BG3 X-Offset (W)
#define BG3VOFF			*(u16*)0x400001E // BG3 Y-Offset (W)

// LCD I/O BG Rotation/Scaling 
#define BG2PA			*(u16*)0x4000020 // BG2 Rotation/Scaling Parameter A (alias dx) (W)
#define BG2PB			*(u16*)0x4000022 // BG2 Rotation/Scaling Parameter B (alias dmx) (W)
#define BG2PC			*(u16*)0x4000024 // BG2 Rotation/Scaling Parameter C (alias dy) (W)
#define BG2PD			*(u16*)0x4000026 // BG2 Rotation/Scaling Parameter D (alias dmy) (W)
#define BG2X_L			*(u16*)0x4000028 // BG2 Reference Point X-Coordinate, lower 16 bit (W)
#define BG2X_H			*(u16*)0x400002A // BG2 Reference Point X-Coordinate, upper 12 bit (W)
#define BG2Y_L			*(u16*)0x400002C // BG2 Reference Point Y-Coordinate, lower 16 bit (W)
#define BG2Y_H			*(u16*)0x400002E // BG2 Reference Point Y-Coordinate, upper 12 bit (W)
#define BG3PA			*(u16*)0x4000030 // BG3 Rotation/Scaling Parameter A (alias dx) (W)
#define BG3PB			*(u16*)0x4000032 // BG3 Rotation/Scaling Parameter B (alias dmx) (W)
#define BG3PC			*(u16*)0x4000034 // BG3 Rotation/Scaling Parameter C (alias dy) (W)
#define BG3PD			*(u16*)0x4000036 // BG3 Rotation/Scaling Parameter D (alias dmy) (W)
#define BG3X_L			*(u16*)0x4000038 // BG3 Reference Point X-Coordinate, lower 16 bit (W)
#define BG3X_H			*(u16*)0x400003A // BG3 Reference Point X-Coordinate, upper 12 bit (W)
#define BG3Y_L			*(u16*)0x400003C // BG3 Reference Point Y-Coordinate, lower 16 bit (W)
#define BG3Y_H			*(u16*)0x400003E // BG3 Reference Point Y-Coordinate, upper 12 bit (W)

// LCD I/O Window Feature 
#define WIN0H			*(u16*)0x4000040 // Window 0 Horizontal Dimensions (W)
#define WIN1H			*(u16*)0x4000042 // Window 1 Horizontal Dimensions (W)
#define WIN0V			*(u16*)0x4000044 // Window 0 Vertical Dimensions (W)
#define WIN1V			*(u16*)0x4000046 // Window 1 Vertical Dimensions (W)
#define WININ			*(u16*)0x4000048 // Control of Inside of Window(s) (R/W)
#define WINOUT			*(u16*)0x400004A // Control of Outside of Windows & Inside of OBJ Window (R/W)

// LCD I/O Mosaic Function
#define MOSIAC			*(u16*)0x400001C // Mosaic Size (W)

// LCD I/O Color Special Effects
#define BLDCNT			*(u16*)0x4000050 // Color Special Effects Selection (R/W)
#define BLDALPHA		*(u16*)0x4000052 // Alpha Blending Coefficients (R/W) (not W)
#define BLDY			*(u16*)0x4000054 // Brightness (Fade-In/Out) Coefficient (W) (not R/W)

#endif
