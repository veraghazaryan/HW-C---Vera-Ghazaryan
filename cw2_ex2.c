/* Exercise 2: Palindrome Checker
Write a C program that checks if a given string is a palindrome. A
palindrome is a word, phrase, number, or other sequence of
characters that reads the same forward and backward, ignoring
spaces, punctuation, and capitalization. Use functions to
implement the palindrome checking logic.*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>

void cleanString(const char input[], char output[]) {
    	int j = 0;
    	for (int i = 0; input[i] != '\0'; i++) {
        	if (isalnum(input[i])) {
            	output[j++] = tolower(input[i]);
        	}
    	}
    	output[j] = '\0';
}

int isPalindrome(const char str[]) {
    	int left = 0;
    	int right = strlen(str) - 1;

    	while (left < right) {
        	if (str[left] != str[right]){
            		return 0;
        	}
		left++;
        	right--;
    	}

    	return 1;
}

int main() {
    	char input[100];
    	char cleaned[100];
    	printf("Enter a text: ");
    	fgets(input, sizeof(input), stdin);
    	size_t len = strlen(input);
    	if (len > 0 && input[len-1] == '\n'){
        	input[len-1] = '\0';
	}
    	cleanString(input, cleaned);
    	if (isPalindrome(cleaned)){
        	printf(" '%s' is a palindrome.\n", input);
    	}else{
        	printf("'%s' is not a palindrome.\n", input);
	}
    	return 0;
}

