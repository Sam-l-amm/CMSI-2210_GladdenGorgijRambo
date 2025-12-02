/*
 * Program:     GCD Calculator
 * Author:      Carter Gladden
 * Description: Reads two numbers from stdin, computes GCD, prints to stdout.
 * To assemble:  as -o findGCD.o findGCD.asm
 * To link:      ld -o findGCD findGCD.o -lSystem -syslibroot $(xcrun -sdk macosx --show-sdk-path) -e _main -arch arm64
 * To run:       ./findGCD
 */

.data
.align 4
    prompt1:    .ascii  "Enter first number: "
    len1 = . - prompt1
    prompt2:    .ascii  "Enter second number: "
    len2 = . - prompt2
    msg_out:    .ascii  "Greatest Common Divisor: "
    len_out = . - msg_out
    newline:    .ascii  "\n"

.bss
.align 4
    in_buf:     .skip   32
    out_buf:    .skip   32

.text
.align 4
    .global _main

_main:
    /* --- GET FIRST NUMBER --- */
    mov x0, 1
    adrp x1, prompt1@PAGE
    add  x1, x1, prompt1@PAGEOFF
    mov x2, #len1               /* Added # for immediate value */
    mov x16, 4
    svc 0

    bl _read_input
    
    adrp x0, in_buf@PAGE
    add  x0, x0, in_buf@PAGEOFF
    
    bl _atoi
    mov x19, x0

    mov x0, 1
    adrp x1, prompt2@PAGE
    add  x1, x1, prompt2@PAGEOFF
    mov x2, #len2
    mov x16, 4
    svc 0

    bl _read_input
    
    adrp x0, in_buf@PAGE
    add  x0, x0, in_buf@PAGEOFF
    
    bl _atoi
    mov x20, x0

    mov x0, x19
    mov x1, x20
    bl _gcd
    mov x19, x0

    mov x0, 1
    adrp x1, msg_out@PAGE
    add  x1, x1, msg_out@PAGEOFF
    mov x2, #len_out
    mov x16, 4
    svc 0

    /* --- CONVERT RESULT TO STRING --- */
    mov x0, x19
    adrp x1, out_buf@PAGE
    add  x1, x1, out_buf@PAGEOFF
    bl _itoa

    /* --- PRINT NUMBER --- */
    mov x2, x0                  /* Length */
    mov x0, 1
    adrp x1, out_buf@PAGE
    add  x1, x1, out_buf@PAGEOFF
    mov x16, 4
    svc 0

    /* --- PRINT NEWLINE --- */
    mov x0, 1
    adrp x1, newline@PAGE
    add  x1, x1, newline@PAGEOFF
    mov x2, 1
    mov x16, 4
    svc 0

    /* Exit */
    mov x0, 0
    mov x16, 1
    svc 0

/* ================================================================== */
/* SUBROUTINES                                                        */
/* ================================================================== */

_read_input:
    mov x0, 0
    adrp x1, in_buf@PAGE
    add  x1, x1, in_buf@PAGEOFF
    mov x2, 32
    mov x16, 3
    svc 0
    ret

_atoi:
    mov x1, x0
    mov x0, 0
    mov x2, 0
    mov x3, 10
convert_loop:
    ldrb w2, [x1], #1
    cmp w2, #10
    b.eq end_atoi
    cmp w2, #0
    b.eq end_atoi
    sub w2, w2, #48
    cmp w2, #9
    b.hi end_atoi
    mul x0, x0, x3
    add x0, x0, x2
    b convert_loop
end_atoi:
    ret

_itoa:
    cmp x0, 0
    b.ne start_itoa
    mov w2, #48
    strb w2, [x1]
    mov x0, 1
    ret
start_itoa:
    mov x2, x0
    mov x3, 0
    mov x4, 10
count_digits:
    cbz x2, conversion_done
    udiv x2, x2, x4
    add x3, x3, 1
    b count_digits
conversion_done:
    mov x5, x3
    add x6, x1, x3
    sub x6, x6, 1
    mov x4, 10
convert_digits_loop:
    cbz x0, end_itoa
    udiv x2, x0, x4
    msub x7, x2, x4, x0
    add w7, w7, #48
    strb w7, [x6]
    sub x6, x6, 1
    mov x0, x2
    b convert_digits_loop
end_itoa:
    mov x0, x5
    ret

_gcd:
    cmp x1, 0
    b.eq gcd_done
    udiv x2, x0, x1
    msub x3, x2, x1, x0
    mov x0, x1
    mov x1, x3
    b _gcd
gcd_done:
    ret