#include <stdio.h>
int main(void){
	int max=0, wnum,wl,i,j,c,row;
	int wn[100];
	wnum=wl=i=j=0;
	for(i=0; i<100; ++i){
		wn[i]=0;
	}
	while((c=getchar())!=EOF){
		if(c!='\t' && c!='\n' && c!=' '){
			++wl; //to find world length 
		}else if(wl>0){
			wn[wnum++]=wl;  // to know words quantity, and the lengths of each word
			wl=0;
		}
	}
	printf("The length of each word: \n");
	for(i=0; i<wnum; ++i){
                printf("%d - %d \n", i+1, wn[i]); // write the  length of each word
	}
	printf("\n");
	for(i=0; i<wnum; ++i){
                if(wn[i]>max){
                        max=wn[i]; // to find max length of words
                }
	}
	printf("Vertical histogram: \n");
	for(row=max; row>0; row--){  //to print vertical histogram
		for(i=0; i<wnum; i++){
			if(wn[i]<row){ 
				printf("  "); // to print more beautiful, sorry for bad english...
			}else{
				printf("* ");
			}
		}
		printf("\n");
	}
	for(i=1; i<=wnum; ++i){
                printf("%d ", i);
	}
	printf("\n");
	printf("\n");
	//to print horizontal 
	printf("Horizontal histogram: \n");
	for(i=0; i<wnum; ++i){
                printf("%d ", i+1);
		for(j=1; j<=wn[i]; ++j){
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
 
