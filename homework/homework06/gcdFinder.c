/*
 * File:  gcdFinder.c
 * Author:  Carter Gladden
 * Description:  This program computes the greatest common divisor (GCD)
 * To compile:  clang -o gcdFinder gcdFinder.c findGCDfunc.asm
 */

#include <stdio.h>
#include <assert.h>

extern int findGCD(int a, int b);

int main() {
    printf("Running GCD tests...\n");

    /* Test 1: Standard case */
    /* GCD of 12 and 18 is 6 */
    assert(findGCD(12, 18) == 6);
    printf("[PASS] GCD(12, 18) == 6\n");

    /* Test 2: Prime numbers */
    /* GCD of 13 and 7 (coprime) is 1 */
    assert(findGCD(13, 7) == 1);
    printf("[PASS] GCD(13, 7) == 1\n");

    /* Test 3: One number is a multiple of the other */
    /* GCD of 10 and 5 is 5 */
    assert(findGCD(10, 5) == 5);
    printf("[PASS] GCD(10, 5) == 5\n");

    /* Test 4: Larger number second */
    /* GCD of 15 and 45 is 15 */
    assert(findGCD(15, 45) == 15);
    printf("[PASS] GCD(15, 45) == 15\n");
    
    /* Test 5: Handling Zero (Definition: gcd(a, 0) = a) */
    assert(findGCD(10, 0) == 10);
    printf("[PASS] GCD(10, 0) == 10\n");

    printf("\nAll tests passed successfully!\n");

    return 0;
}