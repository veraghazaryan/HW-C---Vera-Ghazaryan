/* Homework 1: Sum of Prime numbers
 Create a C program that checks whether user provided number
can be expressed as a sum of two Prime numbers, if yes then
show all possible combinations. Use functions in the
implementation*/

#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    	if (n < 2) return 0;
    	for (int i = 2; i <= sqrt(n); i++) {
        	if (n % i == 0) return 0;
    	}
    	return 1;
}

void sumOfPrimes(int n) {
    	int found = 0;
    	for (int i = 2; i <= n / 2; i++) {
        	int j = n - i;
        	if (isPrime(i) && isPrime(j)) {
            		printf("%d + %d = %d\n", i, j, n);
            		found = 1;
        	}
    	}
    	if (!found) {
        	printf("No combination to %d.\n", n);
    	}
}

int main() {
    	int number;

    	printf("Enter a positive integer: ");
    	if (scanf("%d", &number) != 1 || number <= 0) {
        	printf("Error: enter a positive integer.\n");
        	return 1;
    	}

    	printf("Checking sums of two prime numbers for %d:\n", number);
    	sumOfPrimes(number);
    	return 0;
}
