#include <stdio.h>

int main(void) {
    int c;

    /*
     * If the last characted is EOF (Alt + D), we stop the loop.
     * Until then we output character by character.
     *
     * getchar() reads one character at a time, extra characters
     * are stored in stdin buffer.
     *
     * Subsequent calls of getchar won't ask for new input, but will
     * read next characters from stdin buffer (including final \n).
     */
    while ((c = getchar()) != EOF) {
        // Outputs a single character
        putchar(c);
    }

    return 0;
}
