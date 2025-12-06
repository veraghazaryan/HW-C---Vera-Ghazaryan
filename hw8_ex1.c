#include <stdio.h>
#include <string.h>

#define MAX 200

int main() {
	char file1[50], file2[50];
	char line1[MAX], line2[MAX];
	FILE *f1, *f2;
	int line_no = 1;

	printf("Enter first file name: ");
	scanf("%s", file1);
	printf("Enter second file name: ");
	scanf("%s", file2);

	f1 = fopen(file1, "r");
	f2 = fopen(file2, "r");

	if (f1 == NULL || f2 == NULL) {
		printf("Error opening files.\n");
		return 1;
	}

	while (fgets(line1, MAX, f1) != NULL && fgets(line2, MAX, f2) != NULL) {
		if (strcmp(line1, line2) != 0) {
			printf("Files differ at line %d:\n", line_no);
			printf("File1: %sFile2: %s", line1, line2);
			fclose(f1);
			fclose(f2);
			return 0;
		}
		line_no++;
	}

	// Check if one file has more lines
	if (fgets(line1, MAX, f1) != NULL || fgets(line2, MAX, f2) != NULL) {
		printf("Files differ at line %d (one file has extra lines).\n", line_no);
	}

	fclose(f1);
	fclose(f2);
	return 0;
}
