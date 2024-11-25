/*  This program adds, subtracts, multiplies, and divides
	two integers.
	Written by: Zara Sykes
	Date: 10/27/2024
*/
#include <stdio.h>
#include <stdlib.h>

// Function Declaration
/* There were two functions that were unused, and they were never called in main, so they
 were removed from the code. Those two functions were getData, and calc. Just following the KISS Principle here. */
int getOption(void);

float add(float num1, float num2);
float sub(float num1, float num2);
float mul(float num1, float num2);
float divn(float num1, float num2);

void printResult(float num1, float num2,
	float result, int option);

int main(void)
{
// Local Declarations
	int done = 0;
	int option;
	float num1;
	float num2;
	float result;

// Statments
	while (!done)
	{
		option = getOption();
		if (option == 5)
			done = 1;
		else
		{
			do
			{
				printf("\n\nEnter two numbers: ");
				scanf_s("%f %f", &num1, &num2);
				if (option == 4 && num2 == 0)
				{
					printf("\a\n *** Error *** ");
					printf("Second number cannot be 0\n");
				} // if
			} while (option == 4 && num2 == 0);
			switch (option)
			{
			case 1: result = add(num1, num2);
				break;
			case 2: result = sub(num1, num2);
				break;
			case 3: result = mul(num1, num2);
				break;
			case 4: result = divn(num1, num2);
				break;
			} // switch

			printResult(num1, num2, result, option);
		} // else option != 5
	} // while
	printResult(num1, num2, result, option);
	printf("\nThank you using Calculator.\n");
	return 0;
} // main

/*  ============== getOption ===============
   This function shows a menu and reads the user option.
   Pre nothing
   Post returns a valid option
*/
int getOption(void)
{
// Local Declarations
	int option;

// Statements
	do
	{
		printf("\n****************************");
		printf("\n*  MENU                    *");
		printf("\n*                          *");
		printf("\n* 1. ADD                   *");
		printf("\n* 2. SUBTRACT              *");
		printf("\n* 3. MULTIPLY              *");
		printf("\n* 4. DIVIDE                *");
		printf("\n* 5. QUIT                  *");
		printf("\n*                          *");
		printf("\n****************************");

		printf("\n\n\nPlease type your choice ");
		printf("and press the return key: ");
		scanf_s("%d", &option);

		if (option < 1 || option > 5)
			printf("Invalid option. Please re-enter.\n");

	} while (option < 1 || option > 5);
	return option;
} // getOption

float add(float num1, float num2)
{
	return num1 + num2;
}

float sub(float num1, float num2)
{
	return num1 - num2;
}

float mul(float num1, float num2)
{
	return num1 * num2;
}

float divn(float num1, float num2)
{
	return num1 / num2;
}

void printResult(float num1, float num2, float result, int option)
{
	printf("\n* Option chosen: %d", option);
	printf("\n* First number: %.2f", num1);
	printf("\n* Second number: %.2f", num2);
	printf("\n* result number: %.2f\n\n\n", result);
}

