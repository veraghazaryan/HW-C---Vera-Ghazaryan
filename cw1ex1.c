/* Write a C program that reads integer value from user, 
converts it to string and prints. Use a separate function 
to perform the conversion (void to_str(int n, char s[])).*/

#include <stdio.h>
void to_str(int n, char s[]) {
    	int i = 0, p = 0;
    	int k = n;
	int negative = 0;

    	if (n < 0) {
        	negative = 1;
        	k = -k;
    	}

    	int dignum = k;  //count digits number
    	do{
        	dignum /= 10;
        	p++;
    	}while(dignum!= 0);

    	int len = p + negative; //if number is negative +1 place

    	s[len] = '\0'; //null

    	i = len - 1;
    	while (p--) {
        	s[i--] = (k % 10) + '0';  //fill int digits into array and making string
        	k /= 10;
    	}

    	if (negative){
        	s[0] = '-';
    	}
}

int main() {
    	int num;
    	char s[50];

    	printf("Enter number: ");
    	scanf("%d", &num);

    	to_str(num, s);
    	printf("String: %s\n", s);

    	return 0;
}
