/* Homework 3: Number pyramid
 Write a C program that generates and prints a pyramid pattern of ‘*’ 
characters based on user input number of rows. The program should 
take an integer as input (n) from the user and then generate a 
pyramid pattern of n rows. Use functions to implement the pattern 
generation. */


#include <stdio.h>

void printPyramid(int rows) {
    	int i, j, space;
    	for (i = 1; i <= rows; i++) {
        // print spaces
        	for (space = 1; space <= rows - i; space++) {
            		printf(" ");
        	}
        // print stars with space between
        	for (j = 1; j <= i; j++) {
            		printf("* ");
        	}
        	printf("\n");
    	}
}
int main() {
    	int n;
    	printf("Input number of rows: ");
    	scanf("%d", &n);
    	printPyramid(n);
	return 0;
}
