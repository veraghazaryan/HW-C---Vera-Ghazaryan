/*Exercise 4: Integer stack
 Write a program in C that implements an integer stack data
structure using pointers. Create functions for push, pop, and
display operations which have pointer to the stack as parameter.*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 50


void push(int *stack, int *top, int val) {
	if (*top >= MAX - 1) {
		printf("Stack overflow!\n");
		return;
	}
	(*top)++;
	*(stack + *top) = val;
}

int pop(int *stack, int *top) {
	if (*top < 0) {
		printf("Stack underflow!\n");
		return -1;
	}
	int val = *(stack + *top);
	(*top)--;
	return val;
}

void display(int *stack, int top) {
	if (top < 0) {
		printf("Stack is empty.\n");
		return;
	}
	printf("Stack elements:\n");
	for (int i = top; i >= 0; i--)
		printf("%d ", *(stack + i));
	printf("\n");
}

int main() {
	int stack[MAX], top = -1, choice, val;

	do {
		printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printf("Enter value to push: ");
				scanf("%d", &val);
				push(stack, &top, val);
				break;
			case 2:
				val = pop(stack, &top);
				if (val != -1) 
					printf("Popped: %d\n", val);
				break;
			case 3:
				display(stack, top);
				break;
			case 4:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice!\n");
		}
	} while(choice != 4);

	return 0;
}


