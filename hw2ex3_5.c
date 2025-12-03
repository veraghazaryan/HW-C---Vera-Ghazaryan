/*Exercise 3-5. Write the function itob(n,s,b) that converts the integer n
into a base b character representation in the string s. In particular,
itob(n, s, 16) formats nas a hexadecimal integer in s. */

#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    	int i, j;
    	char temp;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        	temp = s[i]; s[i] = s[j]; s[j] = temp;
    	}
}

void itob(int n, char s[], int b) {
    	if (b < 2 || b > 36) { s[0]='\0'; return; }
    	unsigned int num = (n < 0) ? -n : n;
    	int i = 0;
    	do {
        	int digit = num % b;
        	s[i++] = (digit < 10) ? '0' + digit : 'A' + (digit - 10);
        	num /= b;
    	} while (num > 0);
    	if (n < 0 && b == 10){
		s[i++] = '-';
	}
	s[i] = '\0';
    	reverse(s);
}

int main() {
    	int n, base;
    	char s[100];
    	printf("Enter an integer: ");
    	if (scanf("%d", &n) != 1) {
        	printf("Invalid input.\n");
        	return 1;
    	}
    	printf("Enter base (2-36): ");
    	if (scanf("%d", &base) != 1 || base < 2 || base > 36) {
        	printf("Invalid base.\n");
        	return 1;
    	}
    	itob(n, s, base);
    	printf("Number %d in base %d is: %s\n", n, base, s);
    	return 0;
}
