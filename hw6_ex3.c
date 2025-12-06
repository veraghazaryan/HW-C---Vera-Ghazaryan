/*Exercise 3: Copy arrays
 Write a C program that copies the contents of one integer array
into another using pointers. Pass both arrays and their sizes as function arguments*/

#include <stdio.h>

// function to copy array
void copy_arr(int *src, int *rslt, int n) {
	for (int i = 0; i < n; i++)
		*(rslt + i) = *(src + i);
}

int main() {
	int n;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	int a[n], b[n], *p = a, *q = b;

	printf("Enter %d elements for array A:\n", n);
	for (int i = 0; i < n; i++)
		scanf("%d", p + i);

	copy_arr(p, q, n);

	printf("Array B after copying:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", *(q + i));
	printf("\n");

	return 0;
}
