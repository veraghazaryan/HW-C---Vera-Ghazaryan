/*22. Print String in Reverse Using Pointer
Write a program in C to print a string in reverse using a pointer. */

#include <stdio.h>

int main() {
	char s[50], r[50], *p = s, *q = r;
	int i = -1;
	printf("Input a string: ");
	scanf("%s", s);
	while (*p) {
		p++;
		i++;
	}
	while (i >= 0) {
		p--;
		*q++ = *p;
		i--;
	}
	*q = '\0';
	printf("Reversed string: %s\n", r);
	return 0;
}

