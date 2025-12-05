/* Write a C program that reads two dimensional array of integers and 
prints the transpose of the matrix. */
#include <stdio.h>
int main() {
	int r, c, i, j;
	int mat[50][50], trans[50][50];

	printf("Enter number of rows and columns: ");
	scanf("%d %d", &r, &c);

	printf("Enter elements of the matrix:\n");
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &mat[i][j]);

	// Compute transpose
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			trans[j][i] = mat[i][j];

	// Print transpose
	printf("\nTranspose of the matrix:\n");
	for (i = 0; i < c; i++) {
		for (j = 0; j < r; j++)
			printf("%d ", trans[i][j]);
		printf("\n");
	}

	return 0;
}
