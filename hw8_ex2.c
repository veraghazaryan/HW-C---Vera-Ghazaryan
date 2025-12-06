/*  Write a program similiar to Unix “grep” utility.*/

#include <stdio.h>
#include <string.h>

#define MAX 200

int main() {
	char fname[50], word[50], line[MAX];
	FILE *f;

	printf("Enter file name: ");
	scanf("%s", fname);

	printf("Enter word to search: ");
	scanf("%s", word);

	f = fopen(fname, "r");
	if (f == NULL) {
		printf("Cannot open file.\n");
		return 1;
	}

	printf("\nLines containing '%s':\n", word);
	while (fgets(line, MAX, f) != NULL) {
		if (strstr(line, word) != NULL) // check if word exists in line
			printf("%s", line);
	}

	fclose(f);
	return 0;
}
