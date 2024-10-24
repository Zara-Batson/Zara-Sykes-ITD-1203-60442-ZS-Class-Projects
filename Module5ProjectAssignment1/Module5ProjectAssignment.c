/* This program adds, subtracts, multiplies, and divides two integers read
   from the keyboard and prints the results.
   Written by: Zara Sykes
   Date: 10/6/2024
*/
#include <stdio.h>


// Function Declarations
void getData(int* a, int* b);
int add(int a, int b);
int diff(int a, int b);
int product(int a, int b);
void quomod(int a, int b, int* quotient, int* remainder);
void printRes(int a, int b, int sum, int difference, int multiply, int quotient, int remainder);

int main(void)
{
// Local Declarations
	int a;
	int b;
	int sum = 0;
	int difference = 0;
	int multiply = 0;
	int quotient = 0;
	int remainder = 0;
// Statements
	getData(&a, &b);

	sum = add(a, b);
	difference = diff(a, b);
	multiply = product(a, b);
	quomod(a, b, &quotient, &remainder);

	printRes(a, b, sum, difference, multiply, quotient, remainder);
	return 0;
} // main

/*============getData==============
   This function reads two integers from the keyboard.
   Pre Parameters a and b
   Post Returns a + b
*/
void getData(int* a, int* b)
{
	printf("Please enter two integer numbers: ");
	scanf_s("%d %d", a, b);
} // getData

/*============= add ===============
   This function adds two integers and returns the sum.
   Pre Parameters a and b
   Post Returns a + b
*/
int add(int a, int b)
{
// Local Declarations
	int sum;

// Statements
	sum = a + b;
	return sum;
} // add

int diff(int a, int b)
{
	int difference;

	difference = a - b;
	return difference;
}

int product(int a, int b)
{
	int multiply;

	multiply = a * b;
	return multiply;
}

void quomod(int a, int b, int* quotient, int* remainder)
{
	*quotient = a / b;
	*remainder = a % b;
}


/*==============printRes=================
   Prints the calculated results.
   Pre a and b contain input; sum the results
   Post Data printed
*/
void printRes(int a, int b, int sum, int difference, int multiply, int quotient, int remainder)
{
	printf("%4d + %4d = %4d\n", a, b, sum);
	printf("%4d - %4d = %4d\n", a, b, difference);
	printf("%4d * %4d = %4d\n", a, b, multiply);
	printf("%4d / %4d = %4d\n", a, b, quotient);
	printf("%4d %% %4d = %4d\n", a, b, remainder);
	return;
} // printRes