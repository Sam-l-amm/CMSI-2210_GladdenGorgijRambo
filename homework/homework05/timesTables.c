    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char *argv[]) {
        if (argc != 2) {
            fprintf(stderr, "Usage: %s <number>\n", argv[0]);
            return 1;
        }

        int number = atoi(argv[1]);
        if (number < 2) {
            fprintf(stderr, "Please enter a number greater than or equal to 2.\n");
            return 1;
        }

        printf("    "); 
        for (int j = 2; j <= number; j++) {
            printf("%4d", j);
        }
        printf("\n");

        printf("----");
        for (int j = 2; j <= number; j++) {
            printf("----");
        }
        printf("\n");

        for (int i = 2; i <= number; i++) {
            printf("%4d", i);
            for (int j = 2; j <= number; j++) {
                printf("%4d", i * j);
            }
            printf("\n");
        }

        return 0;
    }