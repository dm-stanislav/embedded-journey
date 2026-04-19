#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;
    int opt;
    int flag_show_lines = 0;

    while ((opt = getopt(argc, argv, "n")) != -1) {
        switch (opt) {
            case 'n': flag_show_lines = 1; break;
            default:
                fprintf(stderr, "Usage: %s [-n] files...\n", argv[0]);
                exit(EXIT_FAILURE);
                break;
        }
    }

    if (optind >= argc) {
        fprintf(stderr, "Usage: %s [-n] files...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int line_number = 1;
    int at_line_start = 1;

    for (int i = optind; i < argc; i++) {
        fp = fopen(argv[i], "r");

        if (fp == NULL) {
            fprintf(stderr, "Error: could not open %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        while ((c = fgetc(fp)) != EOF) {
            if (flag_show_lines && at_line_start) {
                printf("%6d\t", line_number++);
            }

            putchar(c);

            at_line_start = (c == '\n');
        }

        fclose(fp);
    }

    return 0;
}
