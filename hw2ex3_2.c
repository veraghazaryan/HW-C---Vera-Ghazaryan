/* Exercise 3-2. Write a function escape(s,t) that converts characters like
newline and tab into visible escape sequences like \n and \t as it copies the
string t to s. Use a switch. Write a function for the other direction as well,
converting escape sequences into the real characters. */

#include <stdio.h>

int escape(char s[], char t[]) {  // converts real into \n or \t
    	int i, j;
    	for (i = j = 0; t[i] != '\0'; i++) {
        	switch (t[i]) {
            		case '\n':
                		s[j++] = '\\';
                		s[j++] = 'n';
                		break;
            		case '\t':
                		s[j++] = '\\';
                		s[j++] = 't';
                		break;
            		case '\\':
                		s[j++] = '\\';
                		s[j++] = '\\';
                		break;
            		default:
                		s[j++] = t[i];
                		break;
        	}
	}
    	s[j] = '\0';
    	return 0;
}

int notescape(char s[], char t[]) {  // convert \n \t into real
    	int i, j;
    	for (i = j = 0; t[i] != '\0'; i++) {
        	if (t[i] == '\\') {
            		switch (t[i + 1]) {
                		case 'n':
                    			s[j++] = '\n';
                    			i++;
                    			break;
                		case 't':
                    			s[j++] = '\t';
                    			i++;
                    			break;
                		case '\\':
                    			s[j++] = '\\';
                    			i++;
                    			break;
                		default:
                    			s[j++] = '\\';
					s[j++] = t[i + 1];
                			i++;
                    			break;
            		}
        	}
        	else {
            		s[j++] = t[i];
        	}
    	}

    	s[j] = '\0';
    	return 0;
}

int main() {
    	int i = 0;
    	int c;
    	char text[150];
    	printf("Enter text:\n");
    	while ((c = getchar()) != EOF && i < 149) {
        	text[i++] = c;
    	}
    	text[i] = '\0';
    	char escaped[150];
    	char notescaped[150];
    	escape(escaped, text);
    	printf("Escaped: %s\n", escaped);
    	notescape(notescaped, escaped);
    	printf("Unescaped: %s\n", notescaped);
    	return 0;
}

