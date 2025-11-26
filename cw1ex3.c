/* Exercise 3: Guess the number
 Write a C program that plays a simple "Guess the
Number" game with the user. The program should
generate a random number between 1 and 100
(inclusive) and ask the user to guess that number. The
program should provide feedback to the user after
each guess, indicating whether the guess was too
high, too low, or correct. The user should continue
guessing until they guess the correct number.
 Note: The program should use the rand() function to
generate a random number. You should include
#include <stdlib.h> for this. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    	int num, rand_num;

    	srand(time(NULL));            // for not repeating same numb
    	rand_num = rand() % 100 + 1;    // Random number from 1 to 100

    	printf("Guess the number (1-100): ");

    	while(1){
        	scanf("%d", &num);
        	if(num<rand_num){
            	printf("Too low! Try again: ");
        	}
        	else if (num > rand_num){
            		printf("Too high! Try again: ");
        	}
        	else {
            	printf("You guessed the number.\n");
            		break;
        	}
    	}

    	return 0;
}

