#pragma once

// Raspberry Pi VideoCoreIV

// V3D Register Address Map
#define V3D_BASE   0xC00000 // Address ($20C00000 PHYSICAL, $7EC00000 BUS)
#define V3D_IDENT0  0x00000 // 0 (V3D Block Identity)
#define V3D_IDENT1  0x00004 // 1 (V3D Configuration A)
#define V3D_IDENT2  0x00008 // 2 (V3D Configuration B)
#define V3D_IDENT3  0x0000C // 3 (V3D Configuration C)
#define V3D_SCRATCH 0x00010 // Register
#define V3D_L2CACTL 0x00020 // Cache Control
#define V3D_SLCACTL 0x00024 // Cache Control
#define V3D_INTCTL  0x00030 // Control
#define V3D_INTENA  0x00034 // Enables
#define V3D_INTDIS  0x00038 // Disables
#define V3D_CT0CS   0x00100 // List Executor Thread 0 Control & Status
#define V3D_CT1CS   0x00104 // List Executor Thread 1 Control & Status
#define V3D_CT0EA   0x00108 // List Executor Thread 0 End Address
#define V3D_CT1EA   0x0010C // List Executor Thread 1 End Address
#define V3D_CT0CA   0x00110 // List Executor Thread 0 Current Address
#define V3D_CT1CA   0x00114 // List Executor Thread 1 Current Address
#define V3D_CT0RA0  0x00118 // List Executor Thread 0 Return Address
#define V3D_CT1RA0  0x0011C // List Executor Thread 1 Return Address
#define V3D_CT0LC   0x00120 // List Executor Thread 0 List Counter
#define V3D_CT1LC   0x00124 // List Executor Thread 1 List Counter
#define V3D_CT0PC   0x00128 // List Executor Thread 0 Primitive List Counter
#define V3D_CT1PC   0x0012C // List Executor Thread 1 Primitive List Counter
#define V3D_PCS     0x00130 // Control & Status
#define V3D_BFC     0x00134 // Mode Flush Count
#define V3D_RFC     0x00138 // Mode Frame Count
#define V3D_BPCA    0x00300 // Address Of Binning Memory Pool
#define V3D_BPCS    0x00304 // Size Of Binning Memory Pool
#define V3D_BPOA    0x00308 // Of Overspill Binning Memory Block
#define V3D_BPOS    0x0030C // Of Overspill Binning Memory Block
#define V3D_BXCF    0x00310 // Debug
#define V3D_SQRSV0  0x00410 // QPUs 0-7
#define V3D_SQRSV1  0x00414 // QPUs 8-15
#define V3D_SQCNTL  0x00418 // Scheduler Control
#define V3D_SQCSTAT 0x0041C // Scheduler State
#define V3D_SRQPC   0x00430 // User Program Request Program Address
#define V3D_SRQUA   0x00434 // User Program Request Uniforms Address
#define V3D_SRQUL   0x00438 // User Program Request Uniforms Length
#define V3D_SRQCS   0x0043C // User Program Request Control & Status
#define V3D_VPACNTL 0x00500 // Allocator Control
#define V3D_VPMBASE 0x00504 // Base (User) Memory Reservation
#define V3D_PCTRC   0x00670 // Counter Clear
#define V3D_PCTRE   0x00674 // Counter Enables
#define V3D_PCTR0   0x00680 // Counter Count 0
#define V3D_PCTRS0  0x00684 // Counter Mapping 0
#define V3D_PCTR1   0x00688 // Counter Count 1
#define V3D_PCTRS1  0x0068C // Counter Mapping 1
#define V3D_PCTR2   0x00690 // Counter Count 2
#define V3D_PCTRS2  0x00694 // Counter Mapping 2
#define V3D_PCTR3   0x00698 // Counter Count 3
#define V3D_PCTRS3  0x0069C // Counter Mapping 3
#define V3D_PCTR4   0x006A0 // Counter Count 4
#define V3D_PCTRS4  0x006A4 // Counter Mapping 4
#define V3D_PCTR5   0x006A8 // Counter Count 5
#define V3D_PCTRS5  0x006AC // Counter Mapping 5
#define V3D_PCTR6   0x006B0 // Counter Count 6
#define V3D_PCTRS6  0x006B4 // Counter Mapping 6
#define V3D_PCTR7   0x006B8 // Counter Count 7
#define V3D_PCTRS7  0x006BC // Counter Mapping 7
#define V3D_PCTR8   0x006C0 // Counter Count 8
#define V3D_PCTRS8  0x006C4 // Counter Mapping 8
#define V3D_PCTR9   0x006C8 // Counter Count 9
#define V3D_PCTRS9  0x006CC // Counter Mapping 9
#define V3D_PCTR10  0x006D0 // Counter Count 10
#define V3D_PCTRS10 0x006D4 // Counter Mapping 10
#define V3D_PCTR11  0x006D8 // Counter Count 11
#define V3D_PCTRS11 0x006DC // Counter Mapping 11
#define V3D_PCTR12  0x006E0 // Counter Count 12
#define V3D_PCTRS12 0x006E4 // Counter Mapping 12
#define V3D_PCTR13  0x006E8 // Counter Count 13
#define V3D_PCTRS13 0x006EC // Counter Mapping 13
#define V3D_PCTR14  0x006F0 // Counter Count 14
#define V3D_PCTRS14 0x006F4 // Counter Mapping 14
#define V3D_PCTR15  0x006F8 // Counter Count 15
#define V3D_PCTRS15 0x006FC // Counter Mapping 15
#define V3D_DBCFG   0x00E00 // #define V3D_DBSCS   0x00E04 // Control & Status
#define V3D_DBSCFG  0x00E08 // Configure
#define V3D_DBSSR   0x00E0C // SR
#define V3D_DBSDR0  0x00E10 // R0
#define V3D_DBSDR1  0x00E14 // R1
#define V3D_DBSDR2  0x00E18 // R2
#define V3D_DBSDR3  0x00E1C // R3
#define V3D_DBQRUN  0x00E20 // Run
#define V3D_DBQHLT  0x00E24 // Halt
#define V3D_DBQSTP  0x00E28 // Step
#define V3D_DBQITE  0x00E2C // Interrupt Enables
#define V3D_DBQITC  0x00E30 // Interrupt Control
#define V3D_DBQGHC  0x00E34 // GHC
#define V3D_DBQGHG  0x00E38 // GHG
#define V3D_DBQGHH  0x00E3C // GHH
#define V3D_DBGE    0x00F00 // Error Signals
#define V3D_FDBGO   0x00F04 // Overrun Error Signals
#define V3D_FDBGB   0x00F08 // Interface Ready & Stall Signals, FEP Busy Signals
#define V3D_FDBGR   0x00F0C // Internal Ready Signals
#define V3D_FDBGS   0x00F10 // Internal Stall Input Signals
#define V3D_ERRSTAT 0x00F20 // Error Signals (VPM, VDW, VCD, VCM, L2C)


// V3D Identity Registers

// V3D_IDENT0: V3D Identification 0 (V3D Block Identity) Register Description
#define V3D_IDENT0_IDSTR 0x00FFFFFF // V3D ID String (Reads As "V3D") READ
#define V3D_IDENT0_TVER  0xFF000000 // V3D Technology Version (Reads Technology Version = 2) READ

// V3D_IDENT1: V3D Identification 1 (V3D Configuration A) Register Description
#define V3D_IDENT1_REVR  0x0000000F // V3D Revision READ
#define V3D_IDENT1_NSLC  0x000000F0 // Number Of Slices READ
#define V3D_IDENT1_QUPS  0x00000F00 // Number Of QPUs Per Slice READ
#define V3D_IDENT1_TUPS  0x0000F000 // Number Of TMUs Per Slice READ
#define V3D_IDENT1_NSEM  0x00FF0000 // Number Of Semaphores READ
#define V3D_IDENT1_HDRT  0x0F000000 // HDR Support (0 = Not Supported, 1 = Supported) READ
#define V3D_IDENT1_VPMSZ 0xF0000000 // VPM Memory Size (Multiples Of 1K, 0 => 16K) READ

// V3D_IDENT2: V3D Identification 2 (V3D Configuration B) Register Description
#define V3D_IDENT2_VRISZ 0x0000000F // VRI Memory Size (0 = Half Size, 1 = Full Size) READ
#define V3D_IDENT2_TLBSZ 0x000000F0 // Tile Buffer Size (0 = Quarter Size, 1 = Half Size, 2 = Full Size (32x32msm)) READ
#define V3D_IDENT2_TLBDB 0x00000F00 // Tile Buffer Double-Buffer Mode Support (0 = Not Supported, 1 = Supported) READ


// V3D Miscellaneous Registers

// V3D_SCRATCH: V3D Scratch Register Description
#define V3D_SCRATCH_SCRATCH 0xFFFFFFFF // Scratch Register (Read/Write Registers For General Purposes) READ/WRITE


// V3D Cache Control Registers

// V3D_L2CACTL: V3D L2 Cache Control Register Description
#define V3D_L2CACTL_L2CENA 0x00000001 // L2 Cache Enable (Reads State Of Cache Enable Bit, Write To Enable The L2 Cache) READ/WRITE
#define V3D_L2CACTL_L2CDIS 0x00000002 // L2 Cache Disable (Write To Disable The L2 Cache) WRITE
#define V3D_L2CACTL_L2CCLR 0x00000004 // L2 Cache Clear (Write To Clear The L2 Cache) WRITE

// V3D_SLCACTL: V3D Slices Cache Control Register Description
#define V3D_SLCACTL_ICCS0_to_ICCS3   0x0000000F // Instruction Cache Clear Bits (Write To Clear Instruction Cache) WRITE
#define V3D_SLCACTL_UCCS0_to_UCCS3   0x00000F00 // Uniforms Cache Clear Bits (Write To Clear Uniforms Cache) WRITE
#define V3D_SLCACTL_T0CCS0_to_T0CCS3 0x000F0000 // TMU0 Cache Clear Bits (Write To Clear TMU0 Cache) WRITE
#define V3D_SLCACTL_T1CCS0_to_T1CCS3 0x0F000000 // TMU1 Cache Clear Bits (Write To Clear TMU1 Cache) WRITE


// V3D Pipeline Interrupt Control

// V3D_INTCTL: V3D Interrupt Control Register Description
#define V3D_INTCTL_INT_FRDONE   0x00000001 // Render Mode Frame Done Interrupt Status (Set When All Tiles Of The Frame Have Been Written To Memory) READ/WRITE
#define V3D_INTCTL_INT_FLDONE   0x00000002 // Binning Mode Flush Done Interrupt Status (Set When Binning Is Complete With All Tile Lists Flushed To Memory) READ/WRITE
#define V3D_INTCTL_INT_OUTOMEM  0x00000004 // Binner Out Of Memory Interrupt Status (Set While The Binner Needs More Memory To Complete) READ/WRITE
#define V3D_INTCTL_INT_SPILLUSE 0x00000008 // Binner Used Overspill Memory Interrupt Status (Set When The Binner Starts Using The (Valid) Overspill Memory Buffer) READ/WRITE

// V3D_INTENA: V3D Interrupt Enables Register Description
#define V3D_INTENA_EI_FRDONE   0x00000001 // Render Mode Frame Done Interrupt Enable (Set When The INT_FRDONE Interrupt Is Set) READ/WRITE
#define V3D_INTENA_EI_FLDONE   0x00000002 // Binning Mode Flush Done Interrupt Enable (Set When The INT_FLDONE Interrupt Is Set) READ/WRITE
#define V3D_INTENA_EI_OUTOMEM  0x00000004 // Binner Out Of Memory Interrupt Enable (Set When The INT_OUTOMEM Interrupt Is Set) READ/WRITE
#define V3D_INTENA_EI_SPILLUSE 0x00000008 // Binner Used Overspill Memory Interrupt Enable (Set When The INT_SPILLUSE Interrupt Is Set) READ/WRITE

// V3D_INTDIS: V3D Interrupt Disables Register Description
#define V3D_INTDIS_DI_FRDONE   0x00000001 // Render Mode Frame Done Interrupt Disable (Set When The INT_FRDONE Interrupt Is Set) READ/WRITE
#define V3D_INTDIS_DI_FLDONE   0x00000002 // Binning Mode Flush Done Interrupt Disable (Set When The INT_FLDONE Interrupt Is Set) READ/WRITE
#define V3D_INTDIS_DI_OUTOMEM  0x00000004 // Binner Out Of Memory Interrupt Disable (Set When The INT_OUTOMEM Interrupt Is Set) READ/WRITE
#define V3D_INTDIS_DI_SPILLUSE 0x00000008 // Binner Used Overspill Memory Interrupt Disable (Set When The INT_SPILLUSE Interrupt Is Set) READ/WRITE


// V3D Control List Executor Registers (Per Thread)

// V3D_CTnCS: V3D Control List Executor Thread n Control & Status Register Description
#define V3D_CTnCS_CTMODE 0x00000001 // Control Thread Mode (Binning Mode Thread Only) READ
#define V3D_CTnCS_CTERR  0x00000008 // Control Thread Error (Set When Stopped With An Error, Cleared On Restarting) READ
#define V3D_CTnCS_CTSUBS 0x00000010 // Control Thread Sub-Mode READ/WRITE
#define V3D_CTnCS_CTRUN  0x00000020 // Control Thread Run READ/WRITE
#define V3D_CTnCS_CTRTSD 0x00000300 // Return Stack Depth (Number Of Levels Of List Nesting) READ
#define V3D_CTnCS_CTSEMA 0x00007000 // Counting Semaphore (Current State Of The Counting Semaphore For This Thread) READ
#define V3D_CTnCS_CTRSTA 0x00008000 // Reset Bit (Writing 1 Stops The Control Thread & Resets All Bits In This Register) WRITE

// V3D_CTnEA: V3D Control List Executor Thread n End Address Register Description
#define V3D_CTnEA_CTLEA 0xFFFFFFFF // Control List End Address (Set To The Byte Address After The Last Record In The Control List) READ/WRITE

// V3D_CTnCA: V3D Control List Executor Thread n Current Address Register Description
#define V3D_CTnCA_CTLCA 0xFFFFFFFF // Control List Current Address (Points To The Address Of The Current Record In The Control List) READ/WRITE

// V3D_CTnRA0: V3D Control List Executor Thread n Return Address Register Description
#define V3D_CTnRA0_CTLRA 0xFFFFFFFF // Control List Return Address 0 (Address On Return Address Stack) READ

// V3D_CTnLC: V3D Control List Executor Thread n List Counter Register Description
#define V3D_CTnLC_CTLSLCS 0x0000FFFF // Sub-list Counter (Count Of Return Commands Encountered) READ/WRITE
#define V3D_CTnLC_CTLLCM  0xFFFF0000 // Major List Counter (Count Of Flush Commands Encountered) READ/WRITE

// V3D_CTnPC: V3D Control List Executor Thread n Primitive List Counter Register Description
#define V3D_CTnPC_CTLPC 0xFFFFFFFF // Primitive List Counter (Count Of Primitives Remaining Whilst Processing A Primitive List) READ


// V3D Pipeline Registers

// V3D_PCS: V3D Pipeline Control & Status Register Description
#define V3D_PCS_BMACTIVE 0x00000001 // Binning Mode Active (Set While Binning Pipeline Is In Use) READ
#define V3D_PCS_BMBUSY   0x00000002 // Binning Mode Busy (Set While Any Binning Operations Are Actually In Progress) READ
#define V3D_PCS_RMACTIVE 0x00000004 // Rendering Mode Active (Set While Rendering Pipeline Is In Use) READ
#define V3D_PCS_RMBUSY   0x00000008 // Rendering Mode Busy (Set While Any Rendering Operations Are Actually In Progress) READ
#define V3D_PCS_BMOOM    0x00000100 // Binning Mode Out Of Memory (Set When PTB Runs Out Of Binning Memory While Binning) READ

// V3D_BFC: V3D Binning Mode Flush Count Register Description
#define V3D_BFC_BMFCT 0x000000FF // Flush Count (Count Increments In Binning Mode Once PTB Has Flushed All Tile Lists To Mem & PTB Has Finished With Tile State Data Array) READ/WRITE

// V3D_RFC: V3D Rendering Mode Frame Count Register Description
#define V3D_RFC_RMFCT 0x000000FF // Frame Count (Count Increments In Rendering Mode When Last Tile Store Operation Of Frame Completes, The Tile Has Fully Written Out To Mem) READ/WRITE

// V3D_BPCA: V3D Current Address Of Binning Memory Pool Register Description
#define V3D_BPCA_BMPCA 0xFFFFFFFF // Current Pool Address (The Address Of The Current Allocation Pointer In The Binning Memory Pool) READ

// V3D_BPCS: V3D Remaining Size Of Binning Memory Pool Register Description
#define V3D_BPCS_BMPRS 0xFFFFFFFF // Size Of Pool Remaining (The Number Of Bytes Remaining In The Binning Memory Pool) READ

// V3D_BPOA: V3D Address Of Overspill Binning Memory Block Register Description
#define V3D_BPOA_BMPOA 0xFFFFFFFF // Address Of Overspill Memory Block For Binning (Address Of Additional Mem That PTB Can Use For Binning Once Initial Pool Runs Out) READ/WRITE

// V3D_BPOS: V3D Size Of Overspill Binning Memory Block Register Description
#define V3D_BPOS_BMPOS 0xFFFFFFFF // Size Of Overspill Memory Block For Binning (Number Of Bytes Of Additional Mem That PTB Can Use For Binning Once Initial Pool Runs Out) READ/WRITE


// V3D QPU Scheduler Registers

// V3D_SQRSV0: V3D Reserve QPUs 0-7 Register Description
#define V3D_SQRSV0_QPURSV0 0x0000000F // Reservation Settings For QPU 0 READ/WRITE
#define V3D_SQRSV0_QPURSV1 0x000000F0 // Reservation Settings For QPU 1 READ/WRITE
#define V3D_SQRSV0_QPURSV2 0x00000F00 // Reservation Settings For QPU 2 READ/WRITE
#define V3D_SQRSV0_QPURSV3 0x0000F000 // Reservation Settings For QPU 3 READ/WRITE
#define V3D_SQRSV0_QPURSV4 0x000F0000 // Reservation Settings For QPU 4 READ/WRITE
#define V3D_SQRSV0_QPURSV5 0x00F00000 // Reservation Settings For QPU 5 READ/WRITE
#define V3D_SQRSV0_QPURSV6 0x0F000000 // Reservation Settings For QPU 6 READ/WRITE
#define V3D_SQRSV0_QPURSV7 0xF0000000 // Reservation Settings For QPU 7 READ/WRITE

// V3D_SQRSV1: V3D Reserve QPUs 8-15 Register Description
#define V3D_SQRSV1_QPURSV8  0x0000000F // Reservation Settings For QPU 8 READ/WRITE
#define V3D_SQRSV1_QPURSV9  0x000000F0 // Reservation Settings For QPU 9 READ/WRITE
#define V3D_SQRSV1_QPURSV10 0x00000F00 // Reservation Settings For QPU 10 READ/WRITE
#define V3D_SQRSV1_QPURSV11 0x0000F000 // Reservation Settings For QPU 11 READ/WRITE
#define V3D_SQRSV1_QPURSV12 0x000F0000 // Reservation Settings For QPU 12 READ/WRITE
#define V3D_SQRSV1_QPURSV13 0x00F00000 // Reservation Settings For QPU 13 READ/WRITE
#define V3D_SQRSV1_QPURSV14 0x0F000000 // Reservation Settings For QPU 14 READ/WRITE
#define V3D_SQRSV1_QPURSV15 0xF0000000 // Reservation Settings For QPU 15 READ/WRITE

// V3D_SQCNTL: V3D QPU Scheduler Control Register Description
#define V3D_SQCNTL_VSRBL 0x00000003 // Vertex Shader Scheduling Bypass Limit READ/WRITE
#define V3D_SQCNTL_CSRBL 0x0000000C // Coordinate Shader Scheduling Bypass Limit READ/WRITE

// V3D_SRQPC: V3D QPU User Program Request Program Address Register Description
#define V3D_SRQPC_QPURQPC 0xFFFFFFFF // Program Address (Writing This Register Queues A Request To Run A Program Starting At The Given Address) WRITE

// V3D_SRQUA: V3D QPU User Program Request Uniforms Address Register Description
#define V3D_SRQUA_QPURQUA 0xFFFFFFFF // Uniforms Address (Contains The Address Of The Uniforms Stream For The Next User Program To Be Queued Via A Write To V3DRQPC) READ/WRITE

// V3D_SRQUL: V3D QPU User Program Request Uniforms Length Register Description
#define V3D_SRQUL_QPURQUL 0x00000FFF // Uniforms Length (Contains The Max Length Of The Uniforms Stream For The Next User Program To Be Queued Via A Write To V3DRQPC) READ/WRITE

// V3D_SRQCS: V3D QPU User Program Request Control & Status Register Description
#define V3D_SRQCS_QPURQL   0x0000003F // Queue Length (Contains The Number Of Program Requests Currently Queued) READ/WRITE
#define V3D_SRQCS_QPURQERR 0x00000080 // Queue Error (Set When A Request Has Been Made When The Queue Is Full) READ/WRITE
#define V3D_SRQCS_QPURQCM  0x0000FF00 // Count Of User Program Requests Made (Contains The Total Number Of User Program Requests Made, Modulo 256) READ/WRITE
#define V3D_SRQCS_QPURQCC  0x00FF0000 // Count Of User Programs Completed (Contains The Total Number Of User Programs That Have Run & Completed, Modulo 256) READ/WRITE


// V3D VPM Registers

// V3D_VPACNTL: V3D VPM Allocator Control Register Description
#define V3D_VPACNTL_VPARALIM 0x00000007 // Rendering VPM Allocation Limit (Limits The Amount Of VPM Memory Allocated To Rendering Mode) READ/WRITE
#define V3D_VPACNTL_VPABALIM 0x00000038 // Binning VPM Allocation Limit (Limits The Amount Of VPM Memory Allocated To Binning Mode) READ/WRITE
#define V3D_VPACNTL_VPARATO  0x000001C0 // Rendering VPM Allocation Timeout (Sets A Timeout For Raising The Priority Of Rendering Mode Allocation Requests) READ/WRITE
#define V3D_VPACNTL_VPABATO  0x00000E00 // Binning VPM Allocation Timeout (Sets A Timeout For Raising The Priority Of Binning Mode Allocation Requests) READ/WRITE
#define V3D_VPACNTL_VPALIMEN 0x00001000 // Enable VPM Allocation Limits (Enables VPM Memory Allocation Limiting Using VPARALIM & VPABALIM) READ/WRITE
#define V3D_VPACNTL_VPATOEN  0x00002000 // Enable VPM Allocation Timeout (Enables VPM Memory Allocation Timeout Using VPARATO & VPABATO) READ/WRITE

// V3D_VPMBASE: V3D VPM Base (User) Memory Reservation Register Description
#define V3D_VPMBASE_VPMURSV 0x0000001F // VPM Memory Reserved For User Programs (Contains Amount Of VPM Mem Reserved For All User Programs, In Multiples Of 256 Bytes) READ/WRITE


// V3D QPU Interrupt Control

// V3D_DBQITE: V3D QPU Interrupt Enables Register Description
#define V3D_DBQITE_IE_QPU0_to_IE_QPU15 0x0000FFFF // QPU Interrupt Enable bits (Set Bit To Allow QPU To Generate An Interrupt) READ/WRITE

// V3D_DBQITC: V3D QPU Interrupt Control Register Description
#define V3D_DBQITC_IC_QPU0_to_IC_QPU15 0x0000FFFF // QPU Interrupt Control Bits (Reads When Interrupt Is Latched, Write To Clear Interrupt) READ/WRITE


// V3D Performance Counters

// V3D Sources For Performance Counters
#define V3D_COUNT_ID_0  =  0 // FEP Valid Primitives That Result In No Rendered Pixels, For All Rendered Tiles
#define V3D_COUNT_ID_1  =  1 // FEP Valid Primitives For All Rendered Tiles (Primitives May Be Counted In More Than One Tile)
#define V3D_COUNT_ID_2  =  2 // FEP Early-Z/Near/Far Clipped Quads
#define V3D_COUNT_ID_3  =  3 // FEP Valid Quads
#define V3D_COUNT_ID_4  =  4 // TLB Quads With No Pixels Passing The Stencil Test
#define V3D_COUNT_ID_5  =  5 // TLB Quads With No Pixels Passing The Z & Stencil Tests
#define V3D_COUNT_ID_6  =  6 // TLB Quads With Any Pixels Passing The Z & Stencil Tests
#define V3D_COUNT_ID_7  =  7 // TLB Quads With All Pixels Having Zero Coverage
#define V3D_COUNT_ID_8  =  8 // TLB Quads With Any Pixels Having Non-Zero Coverage
#define V3D_COUNT_ID_9  =  9 // TLB Quads With Valid Pixels Written To Color Buffer
#define V3D_COUNT_ID_10 = 10 // PTB Primitives Discarded By Being Outside The Viewport
#define V3D_COUNT_ID_11 = 11 // PTB Primitives That Need Clipping
#define V3D_COUNT_ID_12 = 12 // PSE Primitives That Are Discarded Because They Are Reversed
#define V3D_COUNT_ID_13 = 13 // QPU Total Idle Clock Cycles For All QPUs
#define V3D_COUNT_ID_14 = 14 // QPU Total Clock Cycles For All QPUs Doing Vertex/Coordinate Shading
#define V3D_COUNT_ID_15 = 15 // QPU Total Clock Cycles For All QPUs Doing Fragment Shading
#define V3D_COUNT_ID_16 = 16 // QPU Total Clock Cycles For All QPUs Executing Valid Instructions
#define V3D_COUNT_ID_17 = 17 // QPU Total Clock Cycles For All QPUs Stalled Waiting For TMUs
#define V3D_COUNT_ID_18 = 18 // QPU Total Clock Cycles For All QPUs Stalled Waiting For Scoreboard
#define V3D_COUNT_ID_19 = 19 // QPU Total Clock Cycles For All QPUs Stalled Waiting For Varyings
#define V3D_COUNT_ID_20 = 20 // QPU Total Instruction Cache Hits For All Slices
#define V3D_COUNT_ID_21 = 21 // QPU Total Instruction Cache Misses For All Slices
#define V3D_COUNT_ID_22 = 22 // QPU Total Uniforms Cache Hits For All Slices
#define V3D_COUNT_ID_23 = 23 // QPU Total Uniforms Cache Misses For All Slices
#define V3D_COUNT_ID_24 = 24 // TMU Total Texture Quads Processed
#define V3D_COUNT_ID_25 = 25 // TMU Total Texture Cache Misses (Number Of Fetches From Memory/L2 Cache)
#define V3D_COUNT_ID_26 = 26 // VPM Total Clock Cycles VDW Is Stalled Waiting For VPM Access
#define V3D_COUNT_ID_27 = 27 // VPM Total Clock Cycles VCD Is Stalled Waiting For VPM Access
#define V3D_COUNT_ID_28 = 28 // L2C Total Level 2 Cache Hits
#define V3D_COUNT_ID_29 = 29 // L2C Total Level 2 Cache Misses

// V3D_PCTRC: V3D Performance Counter Clear Register Description
#define V3D_PCTRC_CTCLR0_CTCLR15 0x0000FFFF // Performance Counter Clear Bits (Write To Clear The Performance Counter) WRITE

// V3D_PCTRE: V3D Performance Counter Enables Register Description
#define V3D_PCTRE_CTEN0_CTEN15 0x0000FFFF // Performance Counter Enable Bits (0 = Counter Disabled, 1 = Performance Counter Enabled To Count) READ/WRITE

// V3D_PCTRn: V3D Performance Counter Count n Register Description
#define V3D_PCTRn_PCTR 0xFFFFFFFF // Performance Count (Count Value) READ/WRITE

// V3D_PCTRSn: V3D Performance Counter Mapping n Register Description
#define V3D_PCTRSn_PCTRS 0x0000001F // Performance Counter Device ID READ/WRITE


// V3D Error & Diagnostic Registers

// V3D_BXCF: V3D Binner Debug Register Description
#define V3D_BXCF_FWDDISA  0x00000001 // Disable Forwarding In State Cache READ/WRITE
#define V3D_BXCF_CLIPDISA 0x00000002 // Disable Clipping READ/WRITE

// V3D_DBGE: V3D PSE Error Signals Register Description
#define V3D_DBGE_VR1_A        0x00000002 // Error A Reading VPM READ
#define V3D_DBGE_VR1_B        0x00000004 // Error B Reading VPM READ
#define V3D_DBGE_MULIP0       0x00010000 // Error Mulip 0 READ
#define V3D_DBGE_MULIP1       0x00020000 // Error Mulip 1 READ
#define V3D_DBGE_MULIP2       0x00040000 // Error Mulip 2 READ
#define V3D_DBGE_IPD2_VALID   0x00080000 // Error IPD2 Valid READ
#define V3D_DBGE_IPD2_FPDUSED 0x00100000 // Error IPD2 FPD Used READ

// V3D_FDBGO: V3D FEP Overrun Error Signals Register Description
#define V3D_FDBGO_WCOEFF_FIFO_FULL 0x00000002 // Not An Error READ
#define V3D_FDBGO_XYRELZ_FIFO_FULL 0x00000004 // Not An Error READ
#define V3D_FDBGO_QBFR_FIFO_ORUN   0x00000008 // Error READ
#define V3D_FDBGO_QBSZ_FIFO_ORUN   0x00000010 // Error READ
#define V3D_FDBGO_XYFO_FIFO_ORUN   0x00000020 // Error READ
#define V3D_FDBGO_FIXZ_ORUN        0x00000040 // Error READ
#define V3D_FDBGO_XYRELO_FIFO_ORUN 0x00000080 // Error READ
#define V3D_FDBGO_XYRELW_FIFO_ORUN 0x00000400 // Error READ
#define V3D_FDBGO_ZCOEFF_FIFO_FULL 0x00000800 // Not An Error
#define V3D_FDBGO_REFXY_FIFO_ORUN  0x00001000 // Error READ
#define V3D_FDBGO_DEPTHO_FIFO_ORUN 0x00002000 // Error READ
#define V3D_FDBGO_DEPTHO_ORUN      0x00004000 // Error READ
#define V3D_FDBGO_EZVAL_FIFO_ORUN  0x00008000 // Error READ
#define V3D_FDBGO_EZREQ_FIFO_ORUN  0x00020000 // Error READ

// V3D_FDBGB: V3D FEP Interface Ready & Stall Signals, FEP Busy Signals Register Description
#define V3D_FDBGB_EDGES_STALL        0x00000001 // Stall READ
#define V3D_FDBGB_EDGES_READY        0x00000002 // Ready READ
#define V3D_FDBGB_EDGES_ISCTRL       0x00000004 // READ
#define V3D_FDBGB_EDGES_CTRLID       0x00000038 // READ
#define V3D_FDBGB_ZRWPE_STALL        0x00000040 // Stall READ
#define V3D_FDBGB_ZRWPE_READY        0x00000080 // Ready READ
#define V3D_FDBGB_EZ_DATA_READY      0x00800000 // Ready READ
#define V3D_FDBGB_EZ_XY_READY        0x02000000 // Ready READ
#define V3D_FDBGB_RAST_BUSY          0x04000000 // Busy READ
#define V3D_FDBGB_QXYF_FIFO_OP_READY 0x08000000 // Ready READ
#define V3D_FDBGB_XYFO_FIFO_OP_READY 0x10000000 // Ready READ

// V3D_FDBGR: V3D FEP Internal Ready Signals Register Description
#define V3D_FDBGR_QXYF_FIFO_READY   0x00000001 // Ready READ
#define V3D_FDBGR_EZREQ_FIFO_READY  0x00000002 // Ready READ
#define V3D_FDBGR_EZVAL_FIFO_READY  0x00000004 // Ready READ
#define V3D_FDBGR_DEPTHO_FIFO_READY 0x00000008 // Ready READ
#define V3D_FDBGR_REFXY_FIFO_READY  0x00000010 // Ready READ
#define V3D_FDBGR_ZCOEFF_FIFO_READY 0x00000020 // Ready READ
#define V3D_FDBGR_XYRELW_FIFO_READY 0x00000040 // Ready READ
#define V3D_FDBGR_WCOEFF_FIFO_READY 0x00000080 // Ready READ
#define V3D_FDBGR_XYRELO_FIFO_READY 0x00000800 // Ready READ
#define V3D_FDBGR_ZO_FIFO_READY     0x00002000 // Ready READ
#define V3D_FDBGR_XYFO_FIFO_READY   0x00004000 // Ready READ
#define V3D_FDBGR_RAST_READY        0x00010000 // Ready READ
#define V3D_FDBGR_RAST_LAST         0x00020000 // Last READ
#define V3D_FDBGR_DEPTHO_READY      0x00040000 // Ready READ
#define V3D_FDBGR_EZLIM_READY       0x00080000 // Ready READ
#define V3D_FDBGR_XYNRM_READY       0x00100000 // Ready READ
#define V3D_FDBGR_XYNRM_LAST        0x00200000 // Last READ
#define V3D_FDBGR_XYRELZ_FIFO_READY 0x00400000 // Ready READ
#define V3D_FDBGR_XYRELZ_FIFO_LAST  0x00800000 // Last READ
#define V3D_FDBGR_INTERPZ_READY     0x01000000 // Ready READ
#define V3D_FDBGR_INTERPRW_READY    0x08000000 // Ready READ
#define V3D_FDBGR_RECIPW_READY      0x10000000 // Ready READ
#define V3D_FDBGR_FIXZ_READY        0x40000000 // Ready READ

// V3D_FDBGS: V3D FEP Internal Stall Input Signals Register Description
#define V3D_FDBGS_EZTEST_IP_QSTALL     0x00000001 // Stall READ
#define V3D_FDBGS_EZTEST_IP_PRSTALL    0x00000002 // Stall READ
#define V3D_FDBGS_EZTEST_IP_VLFSTALL   0x00000004 // Stall READ
#define V3D_FDBGS_EZTEST_STALL         0x00000008 // Stall READ
#define V3D_FDBGS_EZTEST_VLF_OKNOVALID 0x00000010 // Valid READ
#define V3D_FDBGS_EZTEST_QREADY        0x00000020 // Ready READ
#define V3D_FDBGS_EZTEST_ANYQF         0x00000040 // READ
#define V3D_FDBGS_EZTEST_ANYQVALID     0x00000080 // Valid READ
#define V3D_FDBGS_QXYF_FIFO_OP1_VALID  0x00000100 // Valid READ
#define V3D_FDBGR_QXYF_FIFO_OP1_LAST   0x00000200 // Last READ
#define V3D_FDBGR_QXYF_FIFO_OP1_DUMMY  0x00000400 // Dummy READ
#define V3D_FDBGR_QXYF_FIFO_OP_LAST    0x00000800 // Last READ
#define V3D_FDBGS_QXYF_FIFO_OP_VALID   0x00001000 // Valid READ
#define V3D_FDBGS_EZREQ_FIFO_OP_VALID  0x00002000 // Valid READ
#define V3D_FDBGS_XYNRM_IP_STALL       0x00004000 // Stall READ
#define V3D_FDBGS_EZLIM_IP_STALL       0x00008000 // Stall READ
#define V3D_FDBGS_DEPTHO_FIFO_IP_STALL 0x00010000 // Stall READ
#define V3D_FDBGS_INTERPZ_IP_STALL     0x00020000 // Stall READ
#define V3D_FDBGS_XYRELZ_FIFO_IP_STALL 0x00040000 // Stall READ
#define V3D_FDBGS_INTERPW_IP_STALL     0x00400000 // Stall READ
#define V3D_FDBGS_RECIPW_IP_STALL      0x02000000 // Stall READ
#define V3D_FDBGS_ZO_FIFO_IP_STALL     0x10000000 // Stall READ

// V3D_ERRSTAT: V3D Miscellaneous Error Signals (VPM, VDW, VCD, VCM, L2C) Register Description
#define V3D_ERRSTAT_VPAEABB  0x00000001 // VPM Allocator Error - Allocating Base While Busy READ
#define V3D_ERRSTAT_VPAERGS  0x00000002 // VPM Allocator Error - Request Too Big READ
#define V3D_ERRSTAT_VPAEBRGL 0x00000004 // VPM Allocator Error - Binner Request Greater Than Limit READ
#define V3D_ERRSTAT_VPAERRGL 0x00000008 // VPM Allocator Error - Renderer Request Greater Than Limit READ
#define V3D_ERRSTAT_VPMEWR   0x00000010 // VPM Error - Write Range READ
#define V3D_ERRSTAT_VPMERR   0x00000020 // VPM Error - Read Range READ
#define V3D_ERRSTAT_VPMERNA  0x00000040 // VPM Error - Read Non-Allocated READ
#define V3D_ERRSTAT_VPMEWNA  0x00000080 // VPM Error - Write Non-Allocated READ
#define V3D_ERRSTAT_VPMEFNA  0x00000100 // VPM Error - Free Non-Allocated READ
#define V3D_ERRSTAT_VPMEAS   0x00000200 // VPM Error - Allocated Size Error READ
#define V3D_ERRSTAT_VDWE     0x00000400 // VDW Error - Address Overflows READ
#define V3D_ERRSTAT_VCDE     0x00000800 // VCD Error - FIFO Pointers Out Of Sync READ
#define V3D_ERRSTAT_VCDI     0x00001000 // VCD Idle READ
#define V3D_ERRSTAT_VCMRE    0x00002000 // VCM Error (Renderer) READ
#define V3D_ERRSTAT_VCMBE    0x00004000 // VCM Error (Binner) READ
#define V3D_ERRSTAT_L2CARE   0x00008000 // L2C AXI Receive Fifo Overrun Error READ