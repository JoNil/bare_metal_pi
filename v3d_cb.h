#include "types.h"

typedef struct v3d_command_builder_s {
    u8 * storage;
    u32 storage_size;
    u32 cursor;
} v3d_command_builder_t;

void v3d_cb_init(v3d_command_builder_t * cb, u8 * storage, u32 storage_size);

void v3d_cb_halt(v3d_command_builder_t * cb);                
void v3d_cb_no_op(v3d_command_builder_t * cb);
void v3d_cb_flush(v3d_command_builder_t * cb);               // Add Return-From-Sub-List To Tile Lists & Then Flush Tile Lists To Memory (B)
void v3d_cb_flush_all_state(v3d_command_builder_t * cb);     // Same As Flush, But Preceded By The Forced Writing Of The Current State To The Tile Lists (B)
void v3d_cb_start_tile_binning(v3d_command_builder_t * cb);  // Advances State Counter So That Initial State Items Actually Go Into Tile Lists (B)
void v3d_cb_increment_semaphore(v3d_command_builder_t * cb); // After Tile Lists Are Flushed Or Last Tile Written
void v3d_cb_wait_on_semaphore(v3d_command_builder_t * cb);   // Wait For Frame To Complete In Other Thread

#define PRIMITIVE_MODE_POINTS         0
#define PRIMITIVE_MODE_LINES          1
#define PRIMITIVE_MODE_LINE_LOOP      2
#define PRIMITIVE_MODE_LINE_STRIP     3
#define PRIMITIVE_MODE_TRIANGLES      4
#define PRIMITIVE_MODE_TRIANGLE_STRIP 5
#define PRIMITIVE_MODE_TRIANGLE_FAN   6

void v3d_vertex_array_primitives(
        v3d_command_builder_t * cb,
        u8 primitive_mode,
        u16 length, // Length (Number Of Vertices)
        u16 index); // Index Of First Vertex

#define NV_SHADER_STATE_FLAG_FRAGMENT_SHADER_SINGLE_THREADED                        0x1
#define NV_SHADER_STATE_FLAG_STRIDE_POINT_SIZE_INCLUDED_IN_SHADED_VERTEX_DATA       0x2
#define NV_SHADER_STATE_FLAG_ENABLE_CLIPPING                                        0x4
#define NV_SHADER_STATE_FLAG_CLIP_COORDINATES_HEADER_INCLUDED_IN_SHADED_VERTEX_DATA 0x8

typedef struct __attribute__ ((packed, aligned(16))) nv_shader_state_s {
    u8 flags;
    u8 stride;
    u8 fragment_shader_uniforms;
    u8 fragment_shader_varyings;
    u32 fragment_shader_code_address;
    u32 fragment_shader_uniforms_address;
    u32 vertex_data_address;
} nv_shader_state_t;

_Static_assert(sizeof(nv_shader_state_t) == 16, "Error");
_Static_assert(_Alignof(nv_shader_state_t) == 16, "Error");

void v3d_cb_nv_shader_state(v3d_command_builder_t * cb, nv_shader_state_t * nv_shader_state);

#define CONFIGURATION_BIT_ENABLE_FORWARD_FACING_PRIMITIVE  0x000001 // Enable Forward Facing Primitive
#define CONFIGURATION_BIT_ENABLE_REVERSE_FACING_PRIMITIVE  0x000002 // Enable Reverse Facing Primitive
#define CONFIGURATION_BIT_CLOCKWISE_PRIMITIVES             0x000004 // Clockwise Primitives
#define CONFIGURATION_BIT_ENABLE_DEPTH_OFFSET              0x000008 // Enable Depth Offset
#define CONFIGURATION_BIT_ANTIALIASED_POINTS_LINES         0x000010 // Antialiased Points & Lines (Not Actually Supported)
#define CONFIGURATION_BIT_COVERAGE_READ_TYPE_LEVEL_4_8     0x000000 // Coverage Read Type = 4*8-Bit Level
#define CONFIGURATION_BIT_COVERAGE_READ_TYPE_MASK_16       0x000020 // Coverage Read Type = 16-Bit Mask
#define CONFIGURATION_BIT_RASTERISER_OVERSAMPLE_MODE_NONE  0x000000 // Rasteriser Oversample Mode = None
#define CONFIGURATION_BIT_RASTERISER_OVERSAMPLE_MODE_4X    0x000040 // Rasteriser Oversample Mode = 4X
#define CONFIGURATION_BIT_RASTERISER_OVERSAMPLE_MODE_16X   0x000080 // Rasteriser Oversample Mode = 16X
#define CONFIGURATION_BIT_COVERAGE_PIPE_SELECT             0x000100 // Coverage Pipe Select
#define CONFIGURATION_BIT_COVERAGE_UPDATE_MODE_NON_ZERO    0x000000 // Coverage Update Mode = Non Zero
#define CONFIGURATION_BIT_COVERAGE_UPDATE_MODE_ODD         0x000200 // Coverage Update Mode = Odd
#define CONFIGURATION_BIT_COVERAGE_UPDATE_MODE_OR          0x000400 // Coverage Update Mode = OR
#define CONFIGURATION_BIT_COVERAGE_UPDATE_MODE_ZERO        0x000600 // Coverage Update Mode = Zero
#define CONFIGURATION_BIT_COVERAGE_READ_MODE_CLEAR_ON_READ 0x000000 // Coverage Read Mode = Clear On Read
#define CONFIGURATION_BIT_COVERAGE_READ_MODE_LEAVE_ON_READ 0x000800 // Coverage Read Mode = Leave On Read
#define CONFIGURATION_BIT_DEPTH_TEST_FUNCTION_NEVER        0x000000 // Depth-Test Function = Never
#define CONFIGURATION_BIT_DEPTH_TEST_FUNCTION_LT           0x001000 // Depth-Test Function = Less Than (LT)
#define CONFIGURATION_BIT_DEPTH_TEST_FUNCTION_EQ           0x002000 // Depth-Test Function = Equal (EQ)
#define CONFIGURATION_BIT_DEPTH_TEST_FUNCTION_LE           0x003000 // Depth-Test Function = Less Equal (LE)
#define CONFIGURATION_BIT_DEPTH_TEST_FUNCTION_GT           0x004000 // Depth-Test Function = Greater Than (GT)
#define CONFIGURATION_BIT_DEPTH_TEST_FUNCTION_NE           0x005000 // Depth-Test Function = Not Equal (NE)
#define CONFIGURATION_BIT_DEPTH_TEST_FUNCTION_GE           0x006000 // Depth-Test Function = Greater Equal (GE)
#define CONFIGURATION_BIT_DEPTH_TEST_FUNCTION_ALWAYS       0x007000 // Depth-Test Function = Always
#define CONFIGURATION_BIT_Z_UPDATES_ENABLE                 0x008000 // Z Updates Enable
#define CONFIGURATION_BIT_EARLY_Z_ENABLE                   0x010000 // Early Z Enable
#define CONFIGURATION_BIT_EARLY_Z_UPDATES_ENABLE           0x020000 // Early Z Updates Enable

void v3d_cb_configuration_bits(v3d_command_builder_t * cb, u32 flags);
void v3d_cb_viewport_offset(v3d_command_builder_t * cb, u16 x, u16 y);
void v3d_cb_clip_window(v3d_command_builder_t * cb, u16 left, u16 bottom, u16 width, u16 height);

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

void v3d_cb_tile_binning_mode_configuration(
        v3d_command_builder_t * cb,
        u32 address,     // Tile Allocation Memory Address
        u32 size,        // Tile Allocation Memory Size
        u32 baseaddress, // Tile State Data Array Base Address (16-Byte Aligned, Size Of 48 Bytes * Num Tiles)
        u8 width,
        u8 height,
        u8 flags);