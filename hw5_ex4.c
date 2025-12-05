/*Write a C program that sorts array of strings based on the provided callback function.*/

#include <stdio.h>
#include <string.h>

#define MAXSTR 50
#define MAXLEN 50

// Function to sort strings using a callback comparator
void sortStrings(char arr[][MAXLEN], int n, int (*cmp)(const char*, const char*)) {
	int i, j;
	char tmp[MAXLEN];

	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (cmp(arr[i], arr[j]) > 0) { // use callback
				strcpy(tmp, arr[i]);
				strcpy(arr[i], arr[j]);
				strcpy(arr[j], tmp);
			}
		}
	}
}

// Example comparator: alphabetical order
int alphaCmp(const char *a, const char *b) {
	return strcmp(a, b);
}

int main() {
	int n, i;
	char arr[MAXSTR][MAXLEN];

	printf("Enter number of strings: ");
	scanf("%d", &n);

	printf("Enter %d strings:\n", n);
	for (i = 0; i < n; i++)
		scanf("%s", arr[i]);

	// Sort using callback
	sortStrings(arr, n, alphaCmp);

	printf("\nSorted strings:\n");
	for (i = 0; i < n; i++)
		printf("%s\n", arr[i]);

	return 0;
}

