/* Exercise 2: Simple Calculator
 Create a C program for a simple calculator that can perform basic arithmetic operations: 
addition, subtraction, multiplication, and division. The program should display a menu to the 
user, allowing them to choose the operation they want to perform and then input two numbers to 
perform the chosen operation. After performing the operation, the program should display the 
result.
 Here are the requirements for the program:
 1) Display a menu with the following options:
 1. Addition, 2. Subtraction, 3. Multiplication, 4. Division, 5. Quit (to exit the program)
 2) Allow the user to choose an option by entering a corresponding number (e.g., 1 for addition, 2 
for subtraction, etc.).
 3) If the user selects an operation (1-4), prompt them to enter two numbers (operands) on which to 
perform the chosen operation.
 4) Perform the selected operation and display the result.
 5) After displaying the result, return to the menu to allow the user to perform another operation or 
quit the program. */

#include <stdio.h>

int main() {
    	int n;
    	float a, b, result;

    	while (1) {
        	printf("\n Simple Calculator \n");
        	printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n 5. Quit\n");
        	printf(" Choose an option: ");
        	scanf("%d", &n);

        if (n == 5) {
            printf("Exiting...\n");
            break;
        }

        if (n < 1 || n > 5) {
            printf("ERROR: No such option.\n");
            continue;
        }

        printf("Enter first number: ");
        scanf("%f", &a);
        printf("Enter second number: ");
        scanf("%f", &b);

        switch (n) {
            	case 1:
                	result = a + b;
                	printf("Result: %.3f\n", result);
                	break;

            	case 2:
                	result = a - b;
                	printf("Result: %.3f\n", result);
                	break;

            	case 3:
                	result = a * b;
                	printf("Result: %.3f\n", result);
                	break;

            	case 4:
                	if (b == 0) {
                    	printf("ERROR: Division by zero is not allowed.\n");
                	} else {
                    	result = a / b;
                    	printf("Result: %.3f\n", result);
                	}
                	break;
        	}
    	}

    	return 0;
}

