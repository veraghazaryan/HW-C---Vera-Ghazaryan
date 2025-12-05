/* Write a C program (tail) that prints the last n lines of its input. By
default n is 10, but it can be changed by an optional argument, so
that "tail -25" prints last 25 lines.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 1000   // maximum number of lines
#define MAXLEN 200      // maximum length of each line

int main(int argc, char *argv[]) {
	int n = 10;  // default number of lines
	if (argc == 2 && strncmp(argv[1], "-", 1) == 0){
		n = atoi(argv[1] + 1); // parse number from "-n"
	}
	char lines[MAXLINES][MAXLEN];
	int count = 0;

	printf("Enter text:\n");

	while (count < MAXLINES && fgets(lines[count], MAXLEN, stdin) != NULL){
		count++;
	}
	printf("\nLast %d lines:\n", n);

	int start = (count - n) > 0 ? count - n : 0;
	for (int i = start; i < count; i++){
		printf("%s", lines[i]);
	}
	return 0;
}
