/*  Written by: Zara Sykes
	Date: 11/24/2024
*/
#include <stdio.h>
#include <math.h>
void changeCalc(float custChange, int *numOf20, int *numOf10, int *numOf5, int *numOf1, int *numOfQrtr, int *numOfDims, int *numOfNckls, int *numOfPenns);

int main(void)
{
// local declarations
	float cost;
	float custPay;
	float custChange;
	int numOf20;
	int numOf10;
	int numOf5;
	int numOf1;
	int numOfQrtr;
	int numOfDims;
	int numOfNckls;
	int numOfPenns;

	printf("Enter the cost of the items purchased (XX.XX): $\n");
	scanf_s("%f", &cost);
	printf("Enter the amount using to pay (XX.00): \n");
	scanf_s("%f", &custPay);

	custChange = custPay - cost;
	printf("Here is the amount of change the customer must receive: %.2f\n", custChange);
	printf("The program will now determine the change breakdown in bills and coin\n");

	changeCalc(custChange, &numOf20, &numOf10, &numOf5, &numOf1, &numOfQrtr, &numOfDims, &numOfNckls, &numOfPenns);
// Printing the results of the function in main
	printf("Here is the number of $20 bills: %d\n", numOf20);
	printf("Here is the number of $10 bills: %d\n", numOf10);
	printf("Here is the number of $5 bills: %d\n", numOf5);
	printf("Here is the number of $1 bills: %d\n", numOf1);
	printf("Here is the number of quarters: %d\n", numOfQrtr);
	printf("Here is the number of dimes: %d\n", numOfDims);
	printf("Here is the number of nickels: %d\n", numOfNckls);
	printf("Here is the number of pennies: %d", numOfPenns);
}

// Here we have my function to determine change breakdown.
void changeCalc(float custChange, int* numOf20, int* numOf10, int* numOf5, int* numOf1, int* numOfQrtr, int* numOfDims, int* numOfNckls, int* numOfPenns)
{
// Hopefully rounding custChange to the proper hundredth decimal place, rather than having the more precise float
	custChange = roundf(custChange * 100.0)/100.0;
// Calculations to determine change breakdown
	*numOf20 = (int)custChange / 20;
	if (*numOf20 != 0)
		custChange -= *numOf20 * 20;
	*numOf10 = (int)custChange / 10;
	if (*numOf10 != 0)
		custChange -= *numOf10 * 10;
	*numOf5 = (int)custChange / 5;
	if (*numOf5 != 0)
		custChange -= *numOf5 * 5;
	*numOf1 = (int)custChange / 1;
	if (*numOf1 != 0)
		custChange -= *numOf1 * 1;
// Removing decimal here
	custChange = custChange * 100;
	*numOfQrtr = (int)custChange / 25;
	if (*numOfQrtr != 0)
		custChange -= *numOfQrtr * 25;
	*numOfDims = (int)custChange / 10;
	if (*numOfDims != 0)
		custChange -= *numOfDims * 10;
	*numOfNckls = (int)custChange / 5;
	if (*numOfNckls != 0)
		custChange -= *numOfNckls * 5;
	custChange = round(custChange);
	*numOfPenns = custChange;
}