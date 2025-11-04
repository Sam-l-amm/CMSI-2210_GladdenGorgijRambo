#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }

    long long decimal_num;
    if (sscanf(argv[1], "%lld", &decimal_num) != 1) {
        fprintf(stderr, "Invalid number: %s\n", argv[1]);
        return 1;
    }

    int digits = 8;
    if (argc >= 3) {
        if (sscanf(argv[2], "%d", &digits) != 1) {
            fprintf(stderr, "Invalid digit count: %s. Must be 8 or 16.\n", argv[2]);
            return 1;
        }

        if (digits !=8 && digits != 16) {
            fprintf(stderr, "Digit count must be either 8 or 16.\n");
            return 1;
        }

    }

    unsigned long long max_value;
    if (digits == 8) {
        max_value = 0xFFFFFFFFUL;
    } else {
        max_value = 0xFFFFFFFFFFFFFFFFULL;
    }

    if (decimal_num < 0) {
        fprintf(stderr, "Error: Negative numbers are not supported.\n");
        return 1;
    }

    if ((unsigned long long)decimal_num > max_value) {
        fprintf(stderr, "Error: Number exceeds maximum value for %d-digit hexadecimal.\n", decimal_num, digits);
        return 1;
    }

    printf("0x");

    if (digits == 8) {
        printf("%08llX\n", (unsigned long long)decimal_num);
    } else {
        printf("%016llX\n", (unsigned long long)decimal_num);
    }

    printf("\n");

    return 0;
}