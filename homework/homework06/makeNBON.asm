/*
 * File:        makeNBON.asm
 * Description: ARM64 Assembly program that calls makeNBOC 5 times.
 *
 * Assemble:    clang -o makeNBON makeNBON.asm makeNBOC.c
 */

.data
.align 4
    test_values: .word 0x12345678, 0xAABBCCDD, 0xFEEDBEEF, 0x00000001, 0xFFFFFFFF
    fmt_str:     .asciz "Original: 0x%08X -> Network: 0x%08X\n"

.text
.align 4
    .global _main
    .global _printf
    .global _makeNBOC

_main:
    /* PROLOGUE */
    stp x29, x30, [sp, -48]!    /* Stack frame */
    mov x29, sp
    stp x19, x20, [sp, 16]      /* Save x19, x20 */
    str x21, [sp, 32]           /* Save x21 */

    /* Load base address of array ONCE */
    adrp x20, test_values@PAGE
    add x20, x20, test_values@PAGEOFF
    
    /* Initialize loop counter */
    mov x19, 0

loop_start:
    cmp x19, 5
    b.ge loop_end

    /* Load value using indexed addressing */
    ldr w21, [x20, x19, lsl #2]  /* w21 = test_values[i] */
    
    /* Call makeNBOC */
    mov w0, w21
    bl _makeNBOC
    
    /* Print result */
    mov w2, w0                    /* Network byte order result */
    mov w1, w21                   /* Original value */
    adrp x0, fmt_str@PAGE
    add x0, x0, fmt_str@PAGEOFF
    bl _printf

    /* Increment counter */
    add x19, x19, 1
    b loop_start

loop_end:
    /* EPILOGUE */
    ldp x19, x20, [sp, 16]
    ldr x21, [sp, 32]
    ldp x29, x30, [sp], 48
    
    mov w0, 0
    ret