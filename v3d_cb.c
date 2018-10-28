#include "assert.h"
#include "types.h"
#include "v3d_cb.h"

#define CMD_HALT 0x00
#define CMD_NO_OP 0x01
#define CMD_FLUSH 0x04 // Add Return-From-Sub-List To Tile Lists & Then Flush Tile Lists To Memory (B)
#define CMD_FLUSH_ALL_STATE 0x05 // Same As Flush, But Preceded By The Forced Writing Of The Current State To The Tile Lists (B)
#define CMD_START_TILE_BINNING 0x06 // Advances State Counter So That Initial State Items Actually Go Into Tile Lists (B)
#define CMD_INCREMENT_SEMAPHORE 0x07 // After Tile Lists Are Flushed Or Last Tile Written
#define CMD_WAIT_ON_SEMAPHORE 0x08 // Wait For Frame To Complete In Other Thread

#define CMD_TILE_BINNING_MODE_CONFIGURATION 0x70 // Tile Binning Mode Configuration (B)

static void v3d_cb_push_u8(v3d_command_buffer_t * cb, u8 data)
{
    assert(cb->cursor + 1 < cb->storage_size);
    *((u8 *)cb->storage) = data;
    cb->cursor += 1;
}

static void v3d_cb_push_u32(v3d_command_buffer_t * cb, u32 data)
{
    assert(cb->cursor + 4 < cb->storage_size);
    *((u32 *)cb->storage) = data;
    cb->cursor += 4;
}

void v3d_cb_init(v3d_command_buffer_t * cb, u8 * storage, u32 storage_size)
{
    cb->storage = storage;
    cb->storage_size = storage_size;
    cb->cursor = 0;
}

void v3d_cb_add_tile_binning_mode_configuration(
        v3d_command_buffer_t * cb,
        u32 address,
        u32 size,
        u32 baseaddress,
        u8 width,
        u8 height,
        u8 data)
{
    v3d_cb_push_u8(cb, CMD_TILE_BINNING_MODE_CONFIGURATION);
    v3d_cb_push_u32(cb, address);
    v3d_cb_push_u32(cb, size);
    v3d_cb_push_u32(cb, baseaddress);
    v3d_cb_push_u8(cb, width);
    v3d_cb_push_u8(cb, height);
    v3d_cb_push_u8(cb, data);
}