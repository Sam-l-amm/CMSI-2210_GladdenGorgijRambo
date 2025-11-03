#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void dec2bin (int num) {
    unsigned int mask = 1 << 31;

    printf("Binary: ");

    for (int i = 0; i < 32; i++) {
        printf("%d", (num & mask) ? 1 : 0);
        mask >>= 1;

        if ((i + 1) % 4 == 0 && i != 31) {
            printf(" ");
        }
    }

    printf("\n");

}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("Decimal: %d\n", number);
    dec2bin(number);
    return 0;

}