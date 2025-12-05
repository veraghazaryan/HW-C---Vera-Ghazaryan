/* 7. Print Array Using Pointer
Write a program in C to store n elements in an array and print the elements using a pointer. */


#include <stdio.h>

int main() {
	int arr[50], i, n;
 	printf("Input the number of elements:");
    	scanf("%d", &n); // read the numbers

    	for (i = 0; i < n; i++) {
        	printf(" element - %d : ", i);
        	scanf("%d", arr + i); // read and store elements
    	}

    	printf(" you entered : \n");
    	for (i = 0; i < n; i++) {
        	printf(" element - %d : %d \n", i, *(arr + i));
    	}
    	return 0;
}
