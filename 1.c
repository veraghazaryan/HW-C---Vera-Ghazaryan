/* vertical_by_length.c
   Columns: word lengths 1..MAXWL-1, last column = >=MAXWL (overflow).
   Compile: gcc -std=c11 -O2 vertical_by_length.c -o vertical_by_length
   Run: ./vertical_by_length < input.txt
*/
#include <stdio.h>
#include <ctype.h>

#define MAXWL 15   /* track lengths 1..MAXWL-1; MAXWL = overflow (>=MAXWL) */

int main(void) {
    int counts[MAXWL+1] = {0}; /* counts[1]..counts[MAXWL] */
    int c, len = 0;
    int i, row, maxcount = 0;

    while ((c = getchar()) != EOF) {
        if (isspace(c)) {
            if (len > 0) {
                if (len >= MAXWL) counts[MAXWL]++; else counts[len]++;
                len = 0;
            }
        } else {
            len++;
        }
    }
    if (len > 0) { /* last word if no trailing space */
        if (len >= MAXWL) counts[MAXWL]++; else counts[len]++;
    }

    for (i = 1; i <= MAXWL; ++i)
        if (counts[i] > maxcount) maxcount = counts[i];

    if (maxcount == 0) {
        printf("No words found.\n");
        return 0;
    }

    /* print rows from top down */
    for (row = maxcount; row >= 1; --row) {
        for (i = 1; i <= MAXWL; ++i) {
            if (counts[i] >= row) printf("  * ");
            else                 printf("    ");
        }
        putchar('\n');
    }

    /* separator line */
    for (i = 1; i <= MAXWL; ++i) printf("----");
    putchar('\n');

    /* labels */
    for (i = 1; i < MAXWL; ++i) printf("%3d ", i);
    printf("%3s ", "15+"); /* change 15 to MAXWL to match definition */
    putchar('\n');

    return 0;
}
