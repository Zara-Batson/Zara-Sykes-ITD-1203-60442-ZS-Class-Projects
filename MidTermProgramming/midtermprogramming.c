/*
   Written by: Zara Sykes
   Date: 10/8/2024
*/
#include <stdio.h>

// Tax Rate and Cost per Square Foot Declarations
#define taxRate 0.085
#define costLbrSqrFt 0.35
// Function Declarations
void getData(int* length, int* width, float* crptPrice, int* cstmrDscnt);
void calc(int length, int width, float crptPriceSqrFt, int cstmrDscnt, int* area, float* crptPrice, float* lbrCost, float* installPrice, float* subtotal, float* discountPrcnt, float* dscntTotal, float* taxTotal, float* total);
void installCalc(int length, int width, float crptPriceSqrFt, int* area, float* crptPrice, float* lbrCost, float* installPrice);
void subttlCalc(int cstmrDscnt, float installPrice, float* subtotal, float* discountPrcnt, float* dscntTotal);
void ttlCalc(float subtotal, float dscntTotal, float* taxTotal, float* total);
void printRes(int length, int width, int area, float crptPriceSqrFt, int cstmrDscnt, float crptPrice, float lbrCost, float installPrice, float dscntTotal, float subtotal, float taxTotal, float total);
void measurePrint(int length, int width, int area);
void chargePrint(float crptPriceSqrFt, int cstmrDscnt, float crptPrice, float lbrCost, float installPrice, float dscntTotal, float subtotal, float taxTotal, float total);

int main(void)
{
	// Local Declarations
	int length = 0, width = 0, cstmrDscnt = 0, area = 0;
	float lbrCost = 0;
	float crptPrice = 0;
	float installPrice = 0;
	float subtotal = 0;
	float taxTotal = 0;
	float discountPrcnt = 0;
	float dscntTotal = 0;
	float total = 0;
	float crptPriceSqrFt = 0;

	getData(&length, &width, &crptPriceSqrFt, &cstmrDscnt);
	calc(length, width, crptPriceSqrFt, cstmrDscnt, &area, &crptPrice, &lbrCost, &installPrice,
		&subtotal, &discountPrcnt, &dscntTotal, &taxTotal, &total);
	printRes(length, width, area, crptPriceSqrFt, cstmrDscnt, crptPrice, lbrCost, installPrice, dscntTotal, subtotal, taxTotal, total);
	return 0;
}

void getData(int* length, int* width, float* crptPriceSqrFt, int* cstmrDscnt)
{
	printf("Length of room (feet)? ");
	scanf_s("%d", length);
	printf("\nWidth of room (feet)? ");
	scanf_s("%d", width);
	printf("\nCustomer discount (percent)? ");
	scanf_s("%d", cstmrDscnt);
	printf("\nCost per square foot (xxx.xx)? ");
	scanf_s("%f", crptPriceSqrFt);
	printf("\n");
}

void installCalc(int length, int width, float crptPriceSqrFt, int* area, float* crptPrice, float* lbrCost, float* installPrice)
{
	*area = length * width;
	*crptPrice = (length * width) * crptPriceSqrFt;
	*lbrCost = costLbrSqrFt * (length * width);
	*installPrice = ((length * width) * crptPriceSqrFt) + (costLbrSqrFt * (length * width));
}

void subttlCalc(int cstmrDscnt, float installPrice, float* subtotal, float* discountPrcnt, float* dscntTotal)
{
	*discountPrcnt = cstmrDscnt / 100.0;
	*dscntTotal = installPrice * (cstmrDscnt / 100.0);
	*subtotal = installPrice;
}

void ttlCalc(float subtotal, float dscntTotal, float* taxTotal, float* total)
{
	*taxTotal = subtotal * taxRate;
	*total = (subtotal + (subtotal * taxRate)) - dscntTotal;
}

void calc(int length, int width, float crptPriceSqrFt, int cstmrDscnt, int* area, float* crptPrice, float* lbrCost, float* installPrice, float* subtotal, float* discountPrcnt, float* dscntTotal, float* taxTotal, float* total) 
{
	installCalc(length, width, crptPriceSqrFt, area, crptPrice, lbrCost, installPrice);
	subttlCalc(cstmrDscnt, *installPrice, subtotal, discountPrcnt, dscntTotal);
	ttlCalc(*subtotal, *dscntTotal, taxTotal, total);
}

void measurePrint(int length, int width, int area)
{
	printf("%25s\n", "MEASUREMENT");
	printf("Length %23d ft\n", length);
	printf("Width %24d ft\n", width);
	printf("Area %26d square ft\n", area);
}

void chargePrint(float crptPriceSqrFt, int cstmrDscnt, float crptPrice, float lbrCost, float installPrice, float dscntTotal, float subtotal, float taxTotal, float total)
{
	printf("%23s\n", "CHARGES");
	printf("%0s %13s %9s", "DESCRIPTION", "COST/SQ.FT", "CHARGE\n");
	printf("--------------------------------------\n");
	printf("%0s %12.2f %9s%.2f\n", "Carpet", crptPriceSqrFt, "$", crptPrice);
	printf("%0s %13.2f %16.2f\n", "Labor", costLbrSqrFt, lbrCost);
	printf("                          ------------\n");
	printf("%0s %13s%.2f\n", "INSTALLED PRICE", "$", installPrice);
	printf("%0s %7d %1s %17.2f\n", "Discount", cstmrDscnt, "%", dscntTotal);
	printf("%0s %20s%.2f\n", "SUBTOTAL", "$", subtotal);
	printf("                          ------------\n");
	printf("%0s %32.2f\n", "Tax", taxTotal);
	printf("%0s %23s%.2f\n", "TOTAL", "$", total);
}

void printRes(int length, int width, int area, float crptPriceSqrFt, int cstmrDscnt, float crptPrice, float lbrCost, float installPrice, float dscntTotal, float subtotal, float taxTotal, float total)
{
	measurePrint(length, width, area);
	chargePrint(crptPriceSqrFt, cstmrDscnt, crptPrice, lbrCost, installPrice, dscntTotal, subtotal, taxTotal, total);
}