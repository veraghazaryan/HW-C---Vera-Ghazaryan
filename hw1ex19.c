#include <stdio.h>
#define max 100
void reverse(char s[]){
	char temp;
	int i,j;
	for(i=0; s[i]!='\0'; ++i);
	for(j=0, i=i-1; j<i; ++j,--i){ //for not repeating(vor chkrknvi noric hin dzev darna)
                temp=s[j]; //reverse characters
		s[j]=s[i];
		s[i]=temp;
	}
}
int main(){
	char s[max];
	int c, i=0;
	printf("Enter a text: \n");
	while(i < max-1 && (c=getchar())!= EOF && c!='\n') {  
        	s[i++] = c; //take words letters
    	}
	s[i]='\0';//for finishing
	reverse(s);
	printf("Reversed: %s \n", s);
	return 0;
}
