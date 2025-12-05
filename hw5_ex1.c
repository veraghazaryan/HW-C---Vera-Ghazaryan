/*Write a C program that reads names into the array of strings and 
prints duplicate names */

#include <stdio.h>
#include <string.h>

int main() {
	int n, i, j, found;
	char names[50][50]; // max 50 names, each max 49 chars

	printf("Enter number of names: ");
	scanf("%d", &n);

	printf("Enter %d names:\n", n);
	for (i = 0; i < n; i++) {
		scanf("%s", names[i]);
	}

	printf("\nDuplicate names:\n");
	for (i = 0; i < n; i++) {
		found = 0;
		for (j = i + 1; j < n; j++) {
			if (strcmp(names[i], names[j]) == 0) {
				found = 1;
				break;
			}
		}
		if (found){
			printf("%s\n", names[i]);
		}
	}

	return 0;
}

