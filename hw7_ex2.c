/*Create a structure named Complex to represent a complex number with real
and imaginary parts. Write a C program to add and multiply two complex numbers. */

#include <stdio.h>

typedef struct {
	float r, i;
} Complex;

// add two complex numbers
Complex add(Complex a, Complex b) {
	Complex res;
	res.r = a.r + b.r;
	res.i = a.i + b.i;
	return res;
}

// multiply two complex numbers
Complex mul(Complex a, Complex b) {
	Complex res;
	res.r = a.r * b.r - a.i * b.i;
	res.i = a.r * b.i + a.i * b.r;
	return res;
}

int main() {
	Complex c1, c2, sum, product;

	printf("Enter first complex number (real imag): ");
	scanf("%f %f", &c1.r, &c1.i);

	printf("Enter second complex number (real imag): ");
	scanf("%f %f", &c2.r, &c2.i);

	sum = add(c1, c2);
	product = mul(c1, c2);

	printf("Sum: %.2f + %.2fi\n", sum.r, sum.i);
	printf("Product: %.2f + %.2fi\n", product.r, product.i);

	return 0;
}
