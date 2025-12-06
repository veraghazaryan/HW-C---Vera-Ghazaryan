/* Exercise 1: Passing pointers to functions
 Create a C program that demonstrates passing pointers to
functions. Write a function that accepts an integer pointer and
doubles the value it points to. Display the result in the main function */

#include <stdio.h>

// function to double the value
void dbl(int *p) {
	*p = *p * 2;
}

int main() {
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);
	dbl(&n); // pass pointer to function
	printf("Doubled value: %d\n", n);
	return 0;
}
