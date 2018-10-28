#include "types.h"

typedef struct v3d_command_buffer_s {
    u8 * storage;
    u32 storage_size;
    u32 cursor;
} v3d_command_buffer_t;

void v3d_cb_init(v3d_command_buffer_t * cb, u8 * storage, u32 storage_size);

void v3d_cb_add_halt(v3d_command_buffer_t * cb);                
void v3d_cb_add_no_op(v3d_command_buffer_t * cb);
void v3d_cb_add_flush(v3d_command_buffer_t * cb);               // Add Return-From-Sub-List To Tile Lists & Then Flush Tile Lists To Memory (B)
void v3d_cb_add_flush_all_state(v3d_command_buffer_t * cb);     // Same As Flush, But Preceded By The Forced Writing Of The Current State To The Tile Lists (B)
void v3d_cb_add_start_tile_binning(v3d_command_buffer_t * cb);  // Advances State Counter So That Initial State Items Actually Go Into Tile Lists (B)
void v3d_cb_add_increment_semaphore(v3d_command_buffer_t * cb); // After Tile Lists Are Flushed Or Last Tile Written
void v3d_cb_add_wait_on_semaphore(v3d_command_buffer_t * cb);   // Wait For Frame To Complete In Other Thread

#define TILE_BINNING_FLAGS_MULTISAMPLE_MODE_4X                    0x01 // Multisample Mode (4X)
#define TILE_BINNING_FLAGS_BUFFER_COLOR_DEPTH_64                  0x02 // Tile Buffer 64-Bit Color Depth
#define TILE_BINNING_FLAGS_AUTO_INITIALISE_TILE_STATE_DATA_ARRAY  0x04 // Auto-Initialise Tile State Data Array
#define TILE_BINNING_FLAGS_TILE_ALLOCATION_INITIAL_BLOCK_SIZE_32  0x00 // Tile Allocation Initial Block Size = 32 Bytes
#define TILE_BINNING_FLAGS_TILE_ALLOCATION_INITIAL_BLOCK_SIZE_64  0x08 // Tile Allocation Initial Block Size = 64 Bytes
#define TILE_BINNING_FLAGS_TILE_ALLOCATION_INITIAL_BLOCK_SIZE_128 0x10 // Tile Allocation Initial Block Size = 128 Bytes
#define TILE_BINNING_FLAGS_TILE_ALLOCATION_INITIAL_BLOCK_SIZE_256 0x18 // Tile Allocation Initial Block Size = 256 Bytes
#define TILE_BINNING_FLAGS_TILE_ALLOCATION_BLOCK_SIZE_32          0x00 // Tile Allocation Block Size = 32 Bytes
#define TILE_BINNING_FLAGS_TILE_ALLOCATION_BLOCK_SIZE_64          0x20 // Tile Allocation Block Size = 64 Bytes
#define TILE_BINNING_FLAGS_TILE_ALLOCATION_BLOCK_SIZE_128         0x40 // Tile Allocation Block Size = 128 Bytes
#define TILE_BINNING_FLAGS_TILE_ALLOCATION_BLOCK_SIZE_256         0x60 // Tile Allocation Block Size = 256 Bytes
#define TILE_BINNING_FLAGS_DOUBLE_BUFFER_IN_NON_MS_MODE           0x80 // Double-Buffer In Non-MS Mode

void v3d_cb_add_tile_binning_mode_configuration(
        v3d_command_buffer_t * cb,
        u32 address,     // Tile Allocation Memory Address (Bit 0..31)
        u32 size,        // Tile Allocation Memory Size (Bytes) (Bit 32..63)
        u32 baseaddress, // Tile State Data Array Base Address (16-Byte Aligned, Size Of 48 Bytes * Num Tiles) (Bit 64..95)
        u8 width,        // Width (In Tiles) (Bit 96..103)
        u8 height,       // Height (In Tiles) (Bit 104..111)
        u8 flags);       // Flags (Bit 112..119))