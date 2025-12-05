/* 21. Print Alphabets Using Pointer
Write a program in C to print all the alphabets using a pointer.*/

#include <stdio.h>

int main() {
	char a[26], *p;
	int i;
	p = a;
	for (i = 0; i < 26; i++)
		*p++ = 'A' + i;
	p = a;
	for (i = 0; i < 26; i++)
		printf("%c ", *p++);
	printf("\n");
	return 0;
}
