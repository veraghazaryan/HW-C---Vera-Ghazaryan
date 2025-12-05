/*Homework 2: Infix calculator
 Create a C calculator program that provides the operators ‘+’, ‘-’, 
‘*’, ‘/’, ‘%’ and reads the expressions in the infix notation. After 
calculating the expression result it should print result and allow 
another expression to be entered by the user. The program should 
exit when EOF is read. */

#include <stdio.h>
#include <stdlib.h>

int main() {
	char expr[256];
    	int a, b;
    	char op;
    	printf("Enter expressions. \n");

    	while (fgets(expr, sizeof(expr), stdin) != NULL) {
        	if (sscanf(expr, "%d %c %d", &a, &op, &b) == 3) {
            		switch (op) {
                		case '+':
                    			printf("= %d\n", a + b);
                    			break;
                		case '-':
                    			printf("= %d\n", a - b);
                    			break;
                		case '*':
                    			printf("= %d\n", a * b);
                    			break;
                		case '/':
                    			if (b != 0){
                        			printf("= %d\n", a / b);
                    			}else{
                        			printf("Error: Division by zero\n");
                    				break;}
                		case '%':
                    			if (b != 0){
                        			printf("= %d\n", a % b);
                    			}else{
                        			printf("Error: Modulo by zero\n");
                    				break;}
                		default:
                    			printf("Error: Unsupported operator '%c'\n", op);
            		}
        	} else {
            		printf("Error:\n");
        	}
    	}

    	printf("Exiting calculator.\n");
    	return 0;
}
