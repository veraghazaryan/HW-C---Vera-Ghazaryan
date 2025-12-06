/* Define a structure named Time with members hours, minutes, and seconds.
Write a C program to input two times, add them, and display the result in proper time format */

#include <stdio.h>

typedef struct {
	int h, m, s;
} Time;

// function to add two times
Time add_time(Time t1, Time t2) {
	Time res;
	res.s = t1.s + t2.s;
	res.m = t1.m + t2.m + res.s / 60;
	res.s = res.s % 60;
	res.h = t1.h + t2.h + res.m / 60;
	res.m = res.m % 60;
	return res;
}

int main() {
	Time t1, t2, t3;

	printf("Enter first time (hh mm ss): ");
	scanf("%d %d %d", &t1.h, &t1.m, &t1.s);

	printf("Enter second time (hh mm ss): ");
	scanf("%d %d %d", &t2.h, &t2.m, &t2.s);

	t3 = add_time(t1, t2);

	printf("Sum of times: %02d:%02d:%02d\n", t3.h, t3.m, t3.s);

	return 0;
}
