#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    time_t start, end;
    printf("This program will time how long you can hold your breath. Take a deep breath, then press the 'Enter' key. When you absolutely have to exhale, press the enter key again. The duration will be displayed in minutes and seconds.");
    
    getchar();
    start = time(NULL);

    printf("Press 'Enter' to stop timing...");

    getchar();
    end = time(NULL);

    double duration = difftime(end, start);
    int totalSeconds = (int)duration;

    if (totalSeconds >= 60) {
        printf("You held your breath for %d minutes and %d seconds.\n",
               totalSeconds / 60, totalSeconds % 60);
    } else {
        printf("You held your breath for %d seconds.\n", totalSeconds);
    }

    return 0;
}