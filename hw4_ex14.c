/*14. Sort Array Using Pointer
Write a program in C to sort an array using a pointer.*/

#include <stdio.h>

int main() {
	int n, i, j, t;
	printf("Ptr sort:\n");

	printf("n: ");
	scanf("%d", &n);

	int arr[n];      // allocate array
	int *p = arr;    // pointer to array

	printf("values:\n");
	for (i = 0; i < n; i++) {
		printf("%d: ", i+1);
		scanf("%d", p + i);
	}

	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (*(p + i) > *(p + j)) {
				t = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = t;
			}

	printf("\nsorted: \n");
	for (i = 0; i < n; i++)
		printf("%d: %d\n", i+1, *(p + i));

	return 0;
}

