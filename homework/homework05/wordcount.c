/* Write a C program wordcount.c that counts the number of words in a file of text. 
 * Your program should take a file name as a command line argument. As you read the file contents, 
 * keep a count of the number of words which are separated by "whitespace". 
 * [Research what is meant by "whitespace" in the C environment.] 
 * When the file has been completely read, close the file and write out the number of words. 
 * Be sure you handle error conditions like files that don't exist or errors encountered while reading the file. 
 * You should also be able to handle files that are in different directories from where your program resides.
 * 
 * Author: Carter Gladden
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

long word_count(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) {
        perror("fopen");
        return -1; // Indicate an error
    }

    long count = 0;
    int c;
    int in_word = 0;

    while ((c = fgetc(f)) != EOF) {
        if (isspace((unsigned char)c)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }

    if (ferror(f)) {
        perror("read");
        fclose(f);
        return -1;
    }

    fclose(f);
    return count;
}

int main(int argc, char * argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long count = word_count(argv[1]);
    if (count == -1) {
        return EXIT_FAILURE;
    }

    printf("Number of words: %ld\n", count);
    return EXIT_SUCCESS;
}

