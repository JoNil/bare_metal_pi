#pragma once

#include "types.h"

#define MBOX_BUFFER_SIZE 1024

extern volatile u32 mbox[MBOX_BUFFER_SIZE];

#define MBOX_REQUEST    0

#define MBOX_CH_POWER   0
#define MBOX_CH_FB      1
#define MBOX_CH_VUART   2
#define MBOX_CH_VCHIQ   3
#define MBOX_CH_LEDS    4
#define MBOX_CH_BTNS    5
#define MBOX_CH_TOUCH   6
#define MBOX_CH_COUNT   7
#define MBOX_CH_PROP    8

#define MBOX_TAG_GET_FIRMWARE_REVISION 0x00000001 // VideoCore: Get Firmware Revision (Response: Firmware Revision)
#define MBOX_TAG_GET_BOARD_MODEL       0x00010001 // Hardware: Get Board Model (Response: Board Model)
#define MBOX_TAG_GET_BOARD_REVISION    0x00010002 // Hardware: Get Board Revision (Response: Board Revision)
#define MBOX_TAG_GET_BOARD_MAC_ADDRESS 0x00010003 // Hardware: Get Board MAC Address (Response: MAC Address In Network Byte Order)
#define MBOX_TAG_GET_BOARD_SERIAL      0x00010004 // Hardware: Get Board Serial (Response: Board Serial)
#define MBOX_TAG_GET_ARM_MEMORY        0x00010005 // Hardware: Get ARM Memory (Response: Base Address In Bytes, Size In Bytes)
#define MBOX_TAG_GET_VC_MEMORY         0x00010006 // Hardware: Get VC Memory (Response: Base Address In Bytes, Size In Bytes)
#define MBOX_TAG_GET_CLOCKS            0x00010007 // Hardware: Get Clocks (Response: Parent Clock ID (0 For A Root Clock), Clock ID)
#define MBOX_TAG_GET_POWER_STATE       0x00020001 // Power: Get Power State (Response: Device ID, State)
#define MBOX_TAG_GET_TIMING            0x00020002 // Power: Get Timing (Response: Device ID, Enable Wait Time In Microseconds)
#define MBOX_TAG_SET_POWER_STATE       0x00028001 // Power: Set Power State (Response: Device ID, State)
#define MBOX_TAG_GET_CLOCK_STATE       0x00030001 // Clocks: Get Clock State (Response: Clock ID, State)
#define MBOX_TAG_GET_CLOCK_RATE        0x00030002 // Clocks: Get Clock Rate (Response: Clock ID, Rate In Hz)
#define MBOX_TAG_GET_VOLTAGE           0x00030003 // Voltage: Get Voltage (Response: Voltage ID, Value Offset From 1.2V In Units Of 0.025V)
#define MBOX_TAG_GET_MAX_CLOCK_RATE    0x00030004 // Clocks: Get Max Clock Rate (Response: Clock ID, Rate In Hz)
#define MBOX_TAG_GET_MAX_VOLTAGE       0x00030005 // Voltage: Get Max Voltage (Response: Voltage ID, Value Offset From 1.2V In Units Of 0.025V)
#define MBOX_TAG_GET_TEMPERATURE       0x00030006 // Voltage: Get Temperature (Response: Temperature ID, Value In Degrees C)
#define MBOX_TAG_GET_MIN_CLOCK_RATE    0x00030007 // Clocks: Get Min Clock Rate (Response: Clock ID, Rate In Hz)
#define MBOX_TAG_GET_MIN_VOLTAGE       0x00030008 // Voltage: Get Min Voltage (Response: Voltage ID, Value Offset From 1.2V In Units Of 0.025V)
#define MBOX_TAG_GET_TURBO             0x00030009 // Clocks: Get Turbo (Response: ID, Level)
#define MBOX_TAG_GET_MAX_TEMPERATURE   0x0003000A // Voltage: Get Max Temperature (Response: Temperature ID, Value In Degrees C)
#define MBOX_TAG_ALLOCATE_MEMORY       0x0003000C // Memory: Allocates Contiguous Memory On The GPU (Response: Handle)
#define MBOX_TAG_LOCK_MEMORY           0x0003000D // Memory: Lock Buffer In Place, And Return A Bus Address (Response: Bus Address)
#define MBOX_TAG_UNLOCK_MEMORY         0x0003000E // Memory: Unlock Buffer (Response: Status)
#define MBOX_TAG_RELEASE_MEMORY        0x0003000F // Memory: Free The Memory Buffer (Response: Status)
#define MBOX_TAG_EXECUTE_CODE          0x00030010 // Memory: Calls The Function At Given (Bus) Address And With Arguments Given
#define MBOX_TAG_EXECUTE_QPU           0x00030011 // QPU: Calls The QPU Function At Given (Bus) Address And With Arguments Given (Response: Number Of QPUs, Control, No Flush, Timeout In ms)
#define MBOX_TAG_ENABLE_QPU            0x00030012 // QPU: Enables The QPU (Response: Enable State)
#define MBOX_TAG_GET_EDID_BLOCK        0x00030020 // HDMI: Read Specificed EDID Block From Attached HDMI/DVI Device (Response: Block Number, Status, EDID Block (128 Bytes))
#define MBOX_TAG_SET_CLOCK_STATE       0x00038001 // Clocks: Set Clock State (Response: Clock ID, State)
#define MBOX_TAG_SET_CLOCK_RATE        0x00038002 // Clocks: Set Clock Rate (Response: Clock ID, Rate In Hz)
#define MBOX_TAG_SET_VOLTAGE           0x00038003 // Voltage: Set Voltage (Response: Voltage ID, Value Offset From 1.2V In Units Of 0.025V)
#define MBOX_TAG_SET_TURBO             0x00038009 // Clocks: Set Turbo (Response: ID, Level)
#define MBOX_TAG_ALLOCATE_BUFFER       0x00040001 // Frame Buffer: Allocate Buffer (Response: Frame Buffer Base Address In Bytes, Frame Buffer Size In Bytes)
#define MBOX_TAG_BLANK_SCREEN          0x00040002 // Frame Buffer: Blank Screen (Response: State)
#define MBOX_TAG_GET_PHYSICAL_DISPLAY  0x00040003 // Frame Buffer: Get Physical (Display) Width/Height (Response: Width In Pixels, Height In Pixels)
#define MBOX_TAG_GET_VIRTUAL_BUFFER    0x00040004 // Frame Buffer: Get Virtual (Buffer) Width/Height (Response: Width In Pixels, Height In Pixels)
#define MBOX_TAG_GET_DEPTH             0x00040005 // Frame Buffer: Get Depth (Response: Bits Per Pixel)
#define MBOX_TAG_GET_PIXEL_ORDER       0x00040006 // Frame Buffer: Get Pixel Order (Response: State)
#define MBOX_TAG_GET_ALPHA_MODE        0x00040007 // Frame Buffer: Get Alpha Mode (Response: State)
#define MBOX_TAG_GET_PITCH             0x00040008 // Frame Buffer: Get Pitch (Response: Bytes Per Line)
#define MBOX_TAG_GET_VIRTUAL_OFFSET    0x00040009 // Frame Buffer: Get Virtual Offset (Response: X In Pixels, Y In Pixels)
#define MBOX_TAG_GET_OVERSCAN          0x0004000A // Frame Buffer: Get Overscan (Response: Top In Pixels, Bottom In Pixels, Left In Pixels, Right In Pixels)
#define MBOX_TAG_GET_PALETTE           0x0004000B // Frame Buffer: Get Palette (Response: RGBA Palette Values (Index 0 To 255))
#define MBOX_TAG_TEST_PHYSICAL_DISPLAY 0x00044003 // Frame Buffer: Test Physical (Display) Width/Height (Response: Width In Pixels, Height In Pixels)
#define MBOX_TAG_TEST_VIRTUAL_BUFFER   0x00044004 // Frame Buffer: Test Virtual (Buffer) Width/Height (Response: Width In Pixels, Height In Pixels)
#define MBOX_TAG_TEST_DEPTH            0x00044005 // Frame Buffer: Test Depth (Response: Bits Per Pixel)
#define MBOX_TAG_TEST_PIXEL_ORDER      0x00044006 // Frame Buffer: Test Pixel Order (Response: State)
#define MBOX_TAG_TEST_ALPHA_MODE       0x00044007 // Frame Buffer: Test Alpha Mode (Response: State)
#define MBOX_TAG_TEST_VIRTUAL_OFFSET   0x00044009 // Frame Buffer: Test Virtual Offset (Response: X In Pixels, Y In Pixels)
#define MBOX_TAG_TEST_OVERSCAN         0x0004400A // Frame Buffer: Test Overscan (Response: Top In Pixels, Bottom In Pixels, Left In Pixels, Right In Pixels)
#define MBOX_TAG_TEST_PALETTE          0x0004400B // Frame Buffer: Test Palette (Response: RGBA Palette Values (Index 0 To 255))
#define MBOX_TAG_RELEASE_BUFFER        0x00048001 // Frame Buffer: Release Buffer (Response: Releases And Disables The Frame Buffer)
#define MBOX_TAG_SET_PHYSICAL_DISPLAY  0x00048003 // Frame Buffer: Set Physical (Display) Width/Height (Response: Width In Pixels, Height In Pixels)
#define MBOX_TAG_SET_VIRTUAL_BUFFER    0x00048004 // Frame Buffer: Set Virtual (Buffer) Width/Height (Response: Width In Pixels, Height In Pixels)
#define MBOX_TAG_SET_DEPTH             0x00048005 // Frame Buffer: Set Depth (Response: Bits Per Pixel)
#define MBOX_TAG_SET_PIXEL_ORDER       0x00048006 // Frame Buffer: Set Pixel Order (Response: State)
#define MBOX_TAG_SET_ALPHA_MODE        0x00048007 // Frame Buffer: Set Alpha Mode (Response: State)
#define MBOX_TAG_SET_VIRTUAL_OFFSET    0x00048009 // Frame Buffer: Set Virtual Offset (Response: X In Pixels, Y In Pixels)
#define MBOX_TAG_SET_OVERSCAN          0x0004800A // Frame Buffer: Set Overscan (Response: Top In Pixels, Bottom In Pixels, Left In Pixels, Right In Pixels)
#define MBOX_TAG_SET_PALETTE           0x0004800B // Frame Buffer: Set Palette (Response: RGBA Palette Values (Index 0 To 255))
#define MBOX_TAG_GET_COMMAND_LINE      0x00050001 // Config: Get Command Line (Response: ASCII Command Line String)
#define MBOX_TAG_GET_DMA_CHANNELS      0x00060001 // Shared Resource Management: Get DMA Channels (Response: Bits 0-15: DMA channels 0-15)
#define MBOX_TAG_LAST                  0

#define CLK_EMMC_ID  0x1 // EMMC
#define CLK_UART_ID  0x2 // UART
#define CLK_ARM_ID   0x3 // ARM
#define CLK_CORE_ID  0x4 // CORE
#define CLK_V3D_ID   0x5 // V3D
#define CLK_H264_ID  0x6 // H264
#define CLK_ISP_ID   0x7 // ISP
#define CLK_SDRAM_ID 0x8 // SDRAM
#define CLK_PIXEL_ID 0x9 // PIXEL
#define CLK_PWM_ID   0xA // PWM

i32 mbox_call(u8 ch);