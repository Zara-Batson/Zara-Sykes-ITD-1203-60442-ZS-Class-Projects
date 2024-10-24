/* Written by: Zara Sykes
   Date: 9/29/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void)
{
// Declarations
	srand(time(NULL));
	int number;
	int upperBound = 37.0f;
	int lowerBound = 3.0f;
	float productNumber;

// Prompting, reading, and displaying entered number and the random number
	printf("Please enter a number: ");
	scanf_s("%d", &number);
	printf("The number you entered is: %d\n", number);
	
// I tried several different ways multiple different times, but for whatever reason 
// this was the only way I could get it to work.
	float randomNumber = rand() % (upperBound - lowerBound + 1)
		+ lowerBound;
	randomNumber = randomNumber + (float)rand() / RAND_MAX;
	printf("The random number is: %.4f\n", randomNumber);

// Math code, along with displaying them to the console
	productNumber = number * randomNumber;
	printf("The product of both numbers is: %.4f\n", productNumber);
	printf("The ceiling is: %.0f\n", ceil(randomNumber));
	printf("The floor is: %.0f\n", floor(productNumber));
	printf("The number raised to the power of the number is: %.4f\n", pow(number, randomNumber));
	printf("The square root of the random number is: %.4f\n", sqrt(randomNumber));
}