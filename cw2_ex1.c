/* Exercise 1: Calculate Fibonacci number
Create a C program that calculates N-th Fibonacci number for a given N user number */

#include <stdio.h>

int main() {
    	int n;
    	unsigned long long fib1 = 0, fib2 = 1, fibn;
    	printf("Enter n (non-negative integer): ");
    	if (scanf("%d", &n)!=1 || n<0) {
        	printf("Invalid input! N must be a non-negative integer.\n");
        	return 1;
    	}
    	if (n == 0) {
        	printf("Fibonacci(%d) = 0 \n", n);
        	return 0;
    	} else if (n == 1) {
        	printf("Fibonacci(%d) = 1 \n", n);
        	return 0;
    	}

    	for (int i = 2; i <= n; i++) {
        	fibn = fib1 + fib2;
        	fib1 = fib2;
        	fib2 = fibn;
    	}

    	printf("Fibonacci(%d) = %llu \n", n, fibn);
    	return 0;
}

