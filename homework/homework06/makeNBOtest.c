#include <stdio.h>
#include <stdlib.h>

int makeNBOC(int num);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number1> [number2 ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        int num = (int)strtol(argv[i], NULL, 0);  // Accepts decimal or 0x-prefixed hex
        int converted = makeNBOC(num);
        printf("Original: 0x%08X -> Network Byte Order: 0x%08X\n", num, converted);
    }

    return 0;
}