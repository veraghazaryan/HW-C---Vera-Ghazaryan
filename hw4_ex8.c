/*8. Permutations of a String Using Pointers
Write a program in C to print all permutations of a given string using pointers.*/

#include <stdio.h>
#include <string.h>

// swap two characters
void sw(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

// generate permutations
void perm(char *w, int s, int e)
{
	int i;
	if (s == e) {
		printf("%s  ", w);
	} else {
		for (i = s; i <= e; i++) {
			sw(&w[s], &w[i]);
			perm(w, s + 1, e);
			sw(&w[s], &w[i]);
		}
	}
}

int main()
{
	char w[50];

	printf("Enter a word: ");
	scanf("%49s", w);

	int len = strlen(w);

	printf("\nPermutations:\n");
	perm(w, 0, len - 1);

	printf("\n\n");
	return 0;
}

