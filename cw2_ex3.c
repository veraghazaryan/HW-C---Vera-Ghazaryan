/*Exercise 3: Postfix (reverse Polish) calculator
 Create a C calculator program that provides the operators ‘+’, ‘-’, ‘*’, ‘/’, ‘%’ and reads the expressions in the postfix (reverse Polish)
notation. After calculating the expression result it should print result
and allow another expression to be entered by the user. The
program should exit when EOF is read*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTACK 100
#define MAXLINE 1000

double stack[MAXSTACK];
int top = 0;
void push(double val) { stack[top++] = val; }
double pop() { return stack[--top]; }

int main() {
    	char line[MAXLINE];

    	printf("Postfix Calculator (+ - * / %%).\n");
    	printf("Enter expressions in postfix.\n");

    	while (printf("> "), fgets(line, sizeof(line), stdin) != NULL) {
        	char *token = strtok(line, " \t\n");
        	top = 0;
        	while (token != NULL) {
            		if (isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))) {
                		push(atof(token));
            		}else {
                		double b = pop();
                		double a = pop();

                		switch (token[0]) {
                    			case '+': push(a + b); break;
                    			case '-': push(a - b); break;
                    			case '*': push(a * b); break;
                    			case '/': push(a / b); break;
                    			case '%': push((int)a % (int)b); break;
                		}
            		}
            		token = strtok(NULL, " \t\n");
        	}
        	if (top == 1) {
            		printf("Result: %.2f\n", pop());
        	} else if (top > 1) {
            		printf("Error: too many operands left on stack\n");
        	}
    	}

    	printf("\nExiting calculator.\n");
    	return 0;
}

