/* vertical_per_word.c
   Each column is a word; column height = word length.
*/
#include <stdio.h>
#include <ctype.h>

#define MAXWORDS 500

int main(void) {
    int lens[MAXWORDS];
    int c, len = 0, nw = 0, maxlen = 0;

    for (int i = 0; i < MAXWORDS; ++i) lens[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (len > 0 && nw < MAXWORDS) {
                lens[nw++] = len;
                if (len > maxlen) maxlen = len;
                len = 0;
            }
        } else {
            ++len;
        }
    }
    /* last word if input doesn't end with whitespace */
    if (len > 0 && nw < MAXWORDS) {
        lens[nw++] = len;
        if (len > maxlen) maxlen = len;
    }

    if (nw == 0) {
        printf("No words found (type words then Ctrl+D, or provide a file).\n");
        return 0;
    }

    for (int row = maxlen; row >= 1; --row) {
        for (int j = 0; j < nw; ++j) {
            if (lens[j] >= row) printf(" *");
            else                printf("  ");
        }
        putchar('\n');
    }

    /* print lengths as labels */
    for (int j = 0; j < nw; ++j) {
        if (lens[j] < 10) printf(" %d", lens[j]);
        else              printf("%d", lens[j]); /* two-digit alignment */
    }
    putchar('\n');

    return 0;
}
