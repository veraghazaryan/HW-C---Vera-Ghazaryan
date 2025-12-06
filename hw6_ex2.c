/*Exercise 2: Average and sum of the array
 Write a program in C that calculates average and sum of integer array elements.
Use a function to perform the calculations and don’t use array subscript “[ ]” operator.*/

#include <stdio.h>

// function to calculate sum and average
void sum_avg(int *p, int n, int *sum, float *avg) {
	*sum = 0;
	for (int i = 0; i < n; i++)
		*sum += *(p + i);
	*avg = (float)(*sum) / n;
}

int main() {
	int n, s;
	float a;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	int arr[n], *p = arr;

	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++){
		scanf("%d", p + i);
	}
	sum_avg(p, n, &s, &a);

	printf("Sum = %d\n", s);
	printf("Average = %.2f\n", a);

	return 0;
}
