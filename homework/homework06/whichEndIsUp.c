#include <stdio.h>
#include <stdlib.h>

int whichEndIsUp() {
    int test = 1;
    char *ptr = (char *)&test;
    if (*ptr == 1)
        return 1;
    else
        return 0;
}

int main() {
    if (whichEndIsUp()) {
        printf("\n\n%*s%s%*s\n\n", 10, "", 
               "You are running on a little endian machine", 10, "");
    } else {
        printf("\n\n%*s%s%*s\n\n", 10, "", 
               "You are running on a big endian machine", 10, "");
    }

    return 0;
}