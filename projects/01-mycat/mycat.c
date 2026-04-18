#include <stdlib.h>
#include <stdio.h>

// argc - argument count (how many arguments)
// argv - argument vector (points to the first letters of one or more strings in memory, 0 is the program name)
int main(int argc, char *argv[]) {
    FILE *fp;
    int c;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "error: could not open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    fclose(fp);

    return 0;
}
