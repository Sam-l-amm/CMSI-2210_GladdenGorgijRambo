/*
 * File:        findGCDfunc.arm
 * Description: ARM64 Assembly function to compute GCD.
 * Callable from C.
 *
 * C Prototype: int findGCD(int a, int b);
 * Input:       x0 (a), x1 (b)
 * Output:      x0 (result)
 */

.text
.align 4
.global _findGCD        /* Make the function visible to the Linker */

_findGCD:
    /* * Algorithm: Euclidean (Modulo version)
     * while (b != 0) {
     *   remainder = a % b;
     *   a = b;
     *   b = remainder;
     * }
     * return a;
     */

loop:
    cmp x1, 0           /* Check if b (x1) is 0 */
    b.eq done           /* If b is 0, we are done. Result is in x0 (a) */

    /* Calculate Remainder: a % b */
    udiv x2, x0, x1     /* x2 = a / b */
    msub x3, x2, x1, x0 /* x3 = a - (x2 * b)  -> This is the remainder */

    mov x0, x1          /* a = b */
    mov x1, x3          /* b = remainder */
    b loop              /* Repeat */

done:
    ret                 /* Return to C program. Result is in x0. */
