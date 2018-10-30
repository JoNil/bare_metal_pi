.section ".text.boot"

.global _start
.global _reload_start

_start:
    // Save arguments from the gpu, for later hot reload
    mov     x10, x0
    mov     x11, x1
    mov     x12, x2
    mov     x13, x3

    // Read cpu id, stop slave cores
    mrs     x1, mpidr_el1
    and     x1, x1, #3
    cbz     x1, 2f

    // Cpu id > 0, stop
1:  wfe
    b       1b
2:

    // Set stack before our code
    ldr     x1, =_start

    // Set up EL1
    mrs     x0, CurrentEL
    and     x0, x0, #12 // clear reserved bits

    // Running at EL3?
    cmp     x0, #12
    bne     5f
    
    // Should never be executed, just for completeness
    mov     x2, #0x5b1
    msr     scr_el3, x2
    mov     x2, #0x3c9
    msr     spsr_el3, x2
    adr     x2, 5f
    msr     elr_el3, x2
    eret

    // Running at EL2?
5:  cmp     x0, #4
    beq     5f
    msr     sp_el1, x1
    
    // Enable CNTP for EL1
    mrs     x0, cnthctl_el2
    orr     x0, x0, #3
    msr     cnthctl_el2, x0
    msr     cntvoff_el2, xzr
    
    // Enable AArch64 in EL1
    mov     x0, #(1 << 31)      // AArch64
    orr     x0, x0, #(1 << 1)   // SWIO hardwired on Pi3
    msr     hcr_el2, x0
    mrs     x0, hcr_el2
    
    // Setup SCTLR access
    mov     x2, #0x0800
    movk    x2, #0x30d0, lsl #16
    msr     sctlr_el1, x2
    
    // Set up exception handlers
    ldr     x2, =_vectors
    msr     vbar_el1, x2
    
    // Change execution level to EL1
    mov     x2, #0x3c4
    msr     spsr_el2, x2
    adr     x2, 5f
    msr     elr_el2, x2
    eret

5: mov sp, x1

    // Start L1 Cache
    mrs     x0, SCTLR_EL1 // X0 = System Control Register
    orr     x0, x0, #0x0004 // Data Cache (Bit 2)
    orr     x0, x0, #0x0800 // Branch Prediction (Bit 11)
    orr     x0, x0, #0x1000 // Instruction Caches (Bit 12)
    msr     SCTLR_EL1, x0 // System Control Register = X0
   
    // clear bss
    ldr     x1, =__bss_start
    ldr     w2, =__bss_size
3:  cbz     w2, 4f
    str     xzr, [x1], #8
    sub     w2, w2, #1
    cbnz    w2, 3b

    // Jump to C code, should not return
4:  bl      main
    
    // For failsafe, halt this core too
    b       1b

    // important, code has to be properly aligned
    .align 11
_vectors:
    // synchronous
    .align  7
    mov     x0, #0
    mrs     x1, esr_el1
    mrs     x2, elr_el1
    mrs     x3, spsr_el1
    mrs     x4, far_el1
    b       exc_handler

    // IRQ
    .align  7
    mov     x0, #1
    mrs     x1, esr_el1
    mrs     x2, elr_el1
    mrs     x3, spsr_el1
    mrs     x4, far_el1
    b       exc_handler

    // FIQ
    .align  7
    mov     x0, #2
    mrs     x1, esr_el1
    mrs     x2, elr_el1
    mrs     x3, spsr_el1
    mrs     x4, far_el1
    b       exc_handler

    // SError
    .align  7
    mov     x0, #3
    mrs     x1, esr_el1
    mrs     x2, elr_el1
    mrs     x3, spsr_el1
    mrs     x4, far_el1
    b       exc_handler
_reload_start: