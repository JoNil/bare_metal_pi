#include "assert.h"
#include "types.h"
#include "uart.h"
#include "v3d_cb.h"
#include "str.h"

#define CMD_HALT                            0x00
#define CMD_NO_OP                           0x01
#define CMD_FLUSH                           0x04
#define CMD_FLUSH_ALL_STATE                 0x05
#define CMD_START_TILE_BINNING              0x06
#define CMD_INCREMENT_SEMAPHORE             0x07
#define CMD_WAIT_ON_SEMAPHORE               0x08
#define CMD_VERTEX_ARRAY_PRIMITIVES         0x21
#define CMD_NV_SHADER_STATE                 0x41
#define CMD_CONFIGURATION_BITS              0x60
#define CMD_CLIP_WINDOW                     0x66
#define CMD_VIEWPORT_OFFSET                 0x67
#define CMD_TILE_BINNING_MODE_CONFIGURATION 0x70

static void v3d_cb_push_u8(v3d_command_builder_t * cb, u8 data)
{
    assert(cb->cursor + 1 < cb->storage_size);
    *((u8 *)(cb->storage + cb->cursor)) = data;
    cb->cursor += 1;
}

static void v3d_cb_push_u16(v3d_command_builder_t * cb, u16 data)
{
    assert(cb->cursor + 2 < cb->storage_size);
    *((u16 *)(cb->storage + cb->cursor)) = data;
    cb->cursor += 2;
}

static void v3d_cb_push_u24(v3d_command_builder_t * cb, u32 data)
{
    assert(cb->cursor + 3 < cb->storage_size);
    u32 upper = *((u32 *)(cb->storage + cb->cursor - 1)) & 0xff;
    *((u32 *)(cb->storage + cb->cursor - 1)) = upper | (data << 8);
    cb->cursor += 3;
}

static void v3d_cb_push_u32(v3d_command_builder_t * cb, u32 data)
{
    uart_puts("aaaa\n");

    assert(cb->cursor + 4 < cb->storage_size);

    uart_puts("cccc\n");

    {
        char buffer[128] = {};
        i32_to_string(buffer, sizeof(buffer), (u32)(u64)cb->storage);

        uart_puts(buffer);
        uart_send('\n');
    }

    {
        char buffer[128] = {};
        i32_to_string(buffer, sizeof(buffer), (u32)(u64)cb->cursor);

        uart_puts(buffer);
        uart_send('\n');
    }

    *((u32 *)(cb->storage + cb->cursor)) = data;


    uart_puts("dddd\n");

    cb->cursor += 4;

    uart_puts("bbbb\n");
}

void v3d_cb_init(v3d_command_builder_t * cb, u8 * storage, u32 storage_size)
{
    uart_puts("3.1\n");

    cb->storage = storage;
    cb->storage_size = storage_size;
    cb->cursor = 0;
}

void v3d_cb_halt(v3d_command_builder_t * cb)
{
    v3d_cb_push_u8(cb, CMD_HALT);
}

void v3d_cb_no_op(v3d_command_builder_t * cb)
{
    v3d_cb_push_u8(cb, CMD_NO_OP);
}

void v3d_cb_flush(v3d_command_builder_t * cb)
{
    v3d_cb_push_u8(cb, CMD_FLUSH);
}

void v3d_cb_flush_all_state(v3d_command_builder_t * cb)
{
    v3d_cb_push_u8(cb, CMD_FLUSH_ALL_STATE);
}

void v3d_cb_start_tile_binning(v3d_command_builder_t * cb)
{
    uart_puts("3.3\n");
    v3d_cb_push_u8(cb, CMD_START_TILE_BINNING);
}

void v3d_cb_increment_semaphore(v3d_command_builder_t * cb)
{
    v3d_cb_push_u8(cb, CMD_INCREMENT_SEMAPHORE);
}

void v3d_cb_wait_on_semaphore(v3d_command_builder_t * cb)
{
    v3d_cb_push_u8(cb, CMD_WAIT_ON_SEMAPHORE);
}

void v3d_vertex_array_primitives(v3d_command_builder_t * cb, u8 primitive_mode, u16 length, u16 index)
{
    v3d_cb_push_u8(cb, CMD_VERTEX_ARRAY_PRIMITIVES);
    v3d_cb_push_u8(cb, primitive_mode);
    v3d_cb_push_u16(cb, length);
    v3d_cb_push_u16(cb, index);
}

void v3d_cb_nv_shader_state(v3d_command_builder_t * cb, nv_shader_state_t * nv_shader_state)
{
    v3d_cb_push_u8(cb, CMD_NV_SHADER_STATE);
    v3d_cb_push_u32(cb, (u32)(u64)nv_shader_state);
}

void v3d_cb_configuration_bits(
        v3d_command_builder_t * cb,
        u32 flags)
{
    v3d_cb_push_u8(cb, CMD_CONFIGURATION_BITS);
    v3d_cb_push_u24(cb, flags);
}

void v3d_cb_clip_window(
        v3d_command_builder_t * cb,
        u16 left,
        u16 bottom,
        u16 width,
        u16 height) 
{
    v3d_cb_push_u8(cb, CMD_CLIP_WINDOW);
    v3d_cb_push_u16(cb, left);
    v3d_cb_push_u16(cb, bottom);
    v3d_cb_push_u16(cb, width);
    v3d_cb_push_u16(cb, height);
}

void v3d_cb_viewport_offset(
        v3d_command_builder_t * cb,
        u16 x,
        u16 y) 
{
    v3d_cb_push_u8(cb, CMD_VIEWPORT_OFFSET);
    v3d_cb_push_u16(cb, x);
    v3d_cb_push_u16(cb, y);
}

void v3d_cb_tile_binning_mode_configuration(
        v3d_command_builder_t * cb,
        u32 address,
        u32 size,
        u32 baseaddress,
        u8 width,
        u8 height,
        u8 data)
{
    uart_puts("3.2\n");

    v3d_cb_push_u8(cb, CMD_TILE_BINNING_MODE_CONFIGURATION);
    uart_puts("1\n");
    v3d_cb_push_u32(cb, address);
    uart_puts("2\n");
    v3d_cb_push_u32(cb, size);
    uart_puts("3\n");
    v3d_cb_push_u32(cb, baseaddress);
    uart_puts("4\n");
    v3d_cb_push_u8(cb, width);
    uart_puts("5\n");
    v3d_cb_push_u8(cb, height);
    uart_puts("6\n");
    v3d_cb_push_u8(cb, data);

    uart_puts("3.2e\n");
}

