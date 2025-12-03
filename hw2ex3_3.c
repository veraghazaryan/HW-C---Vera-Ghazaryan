/* Exercise 3-3. Write a function expand(s1,s2) that expands shorthand nota-
tions like a-z in the string s1 into the equivalent complete list abc…xyz in
s2. Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is
taken literally.
*/
#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]) {
    	int i, j;
    	char start, end;

    	for (i=j=0; s1[i]!='\0'; i++) {
		if (s1[i] == '-' && i>0 && s1[i + 1]!='\0') { //to chack wheter it has all ness. components
            		start = s1[i - 1];
            		end   = s1[i + 1];

            		if ((isdigit(start) && isdigit(end) && start < end) ||
                	(islower(start) && islower(end) && start < end) ||
                	(isupper(start) && isupper(end) && start < end))
            		{
            			for (char c = start + 1; c <= end; c++){ // expand
                    			s2[j++] = c;
            				i++;
				}
            		}else {
                		s2[j++] = '-';  //if the first one is greater than second one
			}
        	}else {
            		s2[j++] = s1[i];  //if one character just copy
        	}
    	}

    	s2[j] = '\0';
}
int main() {
    	char s1[100], s2[500];

    	printf("Enter shorthand: ");
    	fgets(s1, sizeof(s1), stdin);
    	expand(s1, s2);
    	printf("Expanded: %s\n", s2);
    	return 0;
}
