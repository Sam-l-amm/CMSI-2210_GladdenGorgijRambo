#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N;
    printf("What value of N would you like to asign?:\n");
    scanf("%d", &N);
    printf("You chose %d\n", N);

    if(N <= 0) {
        printf("Please enter a positive integer greater than zero.\n");
        return 1;
    }

    for(int i = 1; i <= N; i++) {
        if( i % 3 == 0 && i % 5 == 0) {
            printf("FizzBuzz\n");
        } else if (i % 3 == 0) {
            printf("Fizz\n");
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("%d\n", i);
        }
    }

}
