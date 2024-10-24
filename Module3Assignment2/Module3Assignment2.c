/*	This code takes prices to create a customer's bill for some company
	Written by: Zara Sykes
	Date: 9/19/2024
*/

#include <stdio.h>

int main(void)
{
	// Declarations for the unit prices and variables for amount sold
	const float tvPrice = 400.00;
	const float vcrPrice = 220.00;
	const float remoteCtrlrPrice = 35.20;
	const float cdPlayerPrice = 300.00;
	const float tapeRecorderPrice = 150.00;
	const float salesTax = 0.0825;
	float tax;
	float tvTotal;
	float vcrTotal;
	float remoteCtrlrTotal;
	float cdPlayerTotal;
	float tapeRecorderTotal;
	float subtotal;
	float totalPrice;
	int tvAmount;
	int vcrAmount;
	int remoteCtrlrAmount;
	int cdPlayerAmount;
	int tapeRecorderAmount;

	// Input for the TVs sold
	printf("How many TVs were sold?: ");
	scanf_s("%d", &tvAmount);

	// Input for VCRs sold
	printf("How many VCRs were sold?: ");
	scanf_s("%d", &vcrAmount);

	// Input for Remote Controllers sold
	printf("How many Remote Controller were sold?: ");
	scanf_s("%d", &remoteCtrlrAmount);

	// Input for CD Players sold
	printf("How many CD Players were sold?: ");
	scanf_s("%d", &cdPlayerAmount);

	// Input for Tape Recorders sold
	printf("How many CD Players were sold?: ");
	scanf_s("%d", &tapeRecorderAmount);

	// Calc for the total price of the items, and the output
	tvTotal = tvPrice * tvAmount;
	printf("TV Total: $%.2f\n", tvTotal);
	vcrTotal = vcrPrice * vcrAmount;
	printf("VCR Total: $%.2f\n", vcrTotal);
	remoteCtrlrTotal = remoteCtrlrPrice * remoteCtrlrAmount;
	printf("Remote Controller Total: $%.2f\n", remoteCtrlrTotal);
	cdPlayerTotal = cdPlayerPrice * cdPlayerAmount;
	printf("CD Player Total: $%.2f\n", cdPlayerTotal);
	tapeRecorderTotal = tapeRecorderPrice * tapeRecorderAmount;
	printf("Tape Recorder Total: $%.2f\n", tapeRecorderTotal);
	subtotal = (tvTotal + vcrTotal + remoteCtrlrTotal + cdPlayerTotal + tapeRecorderTotal);
	printf("Subtotal: $%.2f\n", subtotal);
	tax = subtotal * salesTax;
	printf("Tax: $%.2f\n", tax);
	totalPrice = tax + subtotal;
	printf("Here is the total amount for the purchase: $%.2f\n", totalPrice);
}