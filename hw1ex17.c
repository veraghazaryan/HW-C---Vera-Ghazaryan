#include <stdio.h>
#define max_length_of_line 1000
#define max_num_of_lines 100


int my_getline(char s[], int lim) {
    	int c, i = 0;
    	for (; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        	s[i] = c;
    	}
    	s[i] = '\0';
    	return i; //return line's length
}

int main() {
    	char lines[max_num_of_lines][max_length_of_line];  // get lines together
    	int lengths[max_num_of_lines];          //  lengths of all lines together
    	int nlines = 0; // number of a line
    	int len;

    	printf("Enter text:\n");

    	while (nlines < max_num_of_lines && (len = my_getline(lines[nlines], max_length_of_line)) > 0) {
        	lengths[nlines] = len;
        	++nlines;
    	}

    	printf("\nLines longer than 80 characters:\n");

    	for (int i = 0; i < nlines; ++i) {
        	if (lengths[i] > 80) { //print lines with length more than 80
            	printf("Line %d: %s \n", i + 1, lines[i]);
        	}
    	}
    	return 0;
}

