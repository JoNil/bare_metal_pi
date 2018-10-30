#include "assert.h"
#include "mbox.h"
#include "types.h"
#include "uart.h"
#include "v3d.h"
#include "v3d_cb.h"

static u8 bin_memory[2 * 1024 * 1024] __attribute__ ((aligned(16)));
static u8 bin_base[48*(4096/32)*(4096/32)] __attribute__ ((aligned(16)));

static u8 binning_command_buffer[4096] __attribute__ ((aligned(16)));

static nv_shader_state_t shader_state __attribute__ ((aligned(16)));

typedef struct vertex_s {
    u16 x; // X In 12.4 Fixed Point
    u16 y; // Y In 12.4 Fixed Point
    float z;
    float one_over_w;
    float varying_r;
    float varying_g;
    float varying_b;
} vertex_t;

static const vertex_t vertex_data[] __attribute__ ((aligned(16))) = {
    {
        320 * 16,
        32 * 16,
        1.0,
        1.0,
        1.0,
        0.0,
        0.0,
    },
    {
        32 * 16,
        448 * 16,
        1.0,
        1.0,
        0.0,
        1.0,
        0.0,
    },
    {
        608 * 16,
        448 * 16,
        1.0,
        1.0,
        0.0,
        0.0,
        1.0,
    },
};

static const u32 fragment_shader[] __attribute__ ((aligned(16))) = {
    0x958E0DBF,
    0xD1724823, // mov r0, vary; mov r3.8d, 1.0
    0x818E7176,
    0x40024821, // fadd r0, r0, r5; mov r1, vary
    0x818E7376,
    0x10024862, // fadd r1, r1, r5; mov r2, vary
    0x819E7540,
    0x114248A3, // fadd r2, r2, r5; mov r3.8a, r0
    0x809E7009,
    0x115049E3, // nop; mov r3.8b, r1
    0x809E7012,
    0x116049E3, // nop; mov r3.8c, r2
    0x159E76C0,
    0x30020BA7, // mov tlbc, r3; nop; thrend
    0x009E7000,
    0x100009E7, // nop; nop; nop
    0x009E7000,
    0x500009E7, // nop; nop; sbdone
};

void v3d_init(i32 width, i32 height)
{
    uart_puts("1\n");

    {
        mbox[0] = 12*4;
        mbox[1] = MBOX_REQUEST;

        mbox[2] = MBOX_TAG_SET_CLOCK_RATE;
        mbox[3] = 8;
        mbox[4] = 8;
        mbox[5] = CLK_V3D_ID;
        mbox[6] = 250*1000*1000;

        mbox[7] = MBOX_TAG_ENABLE_QPU;
        mbox[8] = 4;
        mbox[9] = 4;
        mbox[10] = 1;

        mbox[11] = MBOX_TAG_LAST;

        i32 ret = mbox_call(MBOX_CH_PROP);
        assert(ret);
    }

    uart_puts("2\n");

    {
        shader_state.flags = 0;
        shader_state.stride = 6 * 4;
        shader_state.fragment_shader_uniforms = 0;
        shader_state.fragment_shader_varyings = 3;
        shader_state.fragment_shader_code_address = (u32)(u64)fragment_shader;
        shader_state.fragment_shader_uniforms_address = 0;
        shader_state.vertex_data_address = (u32)(u64)vertex_data;
    }

    uart_puts("3\n");

    {
        v3d_command_builder_t cb = {0};

        v3d_cb_init(&cb, binning_command_buffer, ARRAY_COUNT(binning_command_buffer));

        v3d_cb_tile_binning_mode_configuration(
                &cb,
                (u32)(u64)bin_memory,
                ARRAY_COUNT(bin_memory),
                (u32)(u64)bin_base,
                (width + 63) / 64,
                (height + 63) / 64,
                TILE_BINNING_FLAGS_AUTO_INITIALISE_TILE_STATE_DATA_ARRAY);
        v3d_cb_start_tile_binning(&cb);

        v3d_cb_clip_window(&cb, 0, 0, width, height);
        v3d_cb_viewport_offset(&cb, 0, 0);
        v3d_cb_configuration_bits(
                &cb,
                CONFIGURATION_BIT_ENABLE_FORWARD_FACING_PRIMITIVE |
                CONFIGURATION_BIT_ENABLE_REVERSE_FACING_PRIMITIVE |
                CONFIGURATION_BIT_EARLY_Z_UPDATES_ENABLE);
        
        v3d_cb_nv_shader_state(&cb, &shader_state);
        v3d_vertex_array_primitives(&cb, PRIMITIVE_MODE_TRIANGLES, 3, 0);
        
        v3d_cb_flush(&cb);
    }
    uart_puts("4\n");
}
