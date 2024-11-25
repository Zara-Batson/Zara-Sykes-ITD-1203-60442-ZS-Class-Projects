/*  Written by: Zara Sykes
	Date: 10/27/2024
*/
#include <stdio.h>
#include <math.h>

void calculateMonthlyPayment(double prncpl, double intrstRatePrYr, double numYrs, double* intrstRatePrMnth, double* numMnths, double* mnthlyPymnt, double p, double q);
void printInformation(double prncpl, double intrstRatePrYr, double intrstRatePrMnth, double numYrs, double numMnths, double mnthlyPymnt);
void printAmortizationTable(int month, double oldBlnc, double mnthlyPymnt, double intrstPaid, double prncplPaid, double prncpl);

int main(void)
{
// adding these to eliminate more weird confusion on variable names 
	double prncpl; // from the book this is PR
	double intrstRatePrYr; // This is Interest Rate, per year
	double numYrs; // Number of years for loan
	double intrstRatePrMnth; // Interest Rate per month in decimal form
	double numMnths; // Number of months for loan
	double mnthlyPymnt; // Monthly payment for loan
	double intrstPaid; // The interest paid number in the amortization chart
	double prncplPaid; // The actual principal paid to give the new principal
	double p = 0; // Whatever this is supposed to be... (1 + intrstRatePrMnth) ^numMnths
	double q = 0; // Whatever this is supposed to be too... (P / (P - 1))
	double totalPaid = 0;

	printf("Amount of the loan (Principal)? ");
	scanf_s("%lf", &prncpl);
	printf("\nInterest rate per year (percent)? ");
	scanf_s("%lf", &intrstRatePrYr);
	printf("\nNumber of years? ");
	scanf_s("%lf", &numYrs);

	calculateMonthlyPayment(prncpl, intrstRatePrYr, numYrs, &intrstRatePrMnth, &numMnths, &mnthlyPymnt, p, q);
	printInformation(prncpl, intrstRatePrYr, intrstRatePrMnth, numYrs, numMnths, mnthlyPymnt);

	int month = 1;
	while (prncpl > 0 && month <= numMnths)
	{
		double oldBlnc = prncpl; // Here to pass on to the printAmortizationTable to print the old balance each time
		intrstPaid = prncpl * intrstRatePrMnth;
		if (prncpl < mnthlyPymnt) {
			prncplPaid = mnthlyPymnt - intrstPaid;
			mnthlyPymnt = intrstPaid + prncplPaid;
		}
		else {
			prncplPaid = mnthlyPymnt - intrstPaid;
		}
		prncpl = prncpl - prncplPaid;

		totalPaid += mnthlyPymnt;
		printAmortizationTable(month, oldBlnc, mnthlyPymnt, intrstPaid, prncplPaid, prncpl);
		month++;
	}
	printf("\nTotal amount paid: %.2lf", totalPaid);
}

void calculateMonthlyPayment(double prncpl, double intrstRatePrYr, double numYrs, double* intrstRatePrMnth, double* numMnths, double* mnthlyPymnt, double p, double q)
{
	*numMnths = (numYrs * 12);
	*intrstRatePrMnth = (intrstRatePrYr / 12) / 100;
	p = pow((1 + *intrstRatePrMnth), *numMnths);
	q = (p / (p - 1));
	*mnthlyPymnt = (prncpl * *intrstRatePrMnth * q);
} // calculateMonthlyPayment

void printInformation(double prncpl, double intrstRatePrYr, double intrstRatePrMnth, double numYrs, double numMnths, double mnthlyPymnt)
{
	printf("\n\nThe amount of the loan (principal: %31.2lf\n", prncpl);
	printf("Interest rate/year (percent): %35.1lf\n", intrstRatePrYr);
	printf("Interest rate/month (decimal): %39lf\n", intrstRatePrMnth);
	printf("Number of years: %46.0lf\n", numYrs);
	printf("Number of months: %46.0lf\n", numMnths);
	printf("Monthly payment: %49.2lf\n", mnthlyPymnt);
	// In preparation for Amortization table, I decided to run the print functions for each section of the table below
	printf("\n%s %15s %18s %15s %15s %15s", "Month", "Old Balance", "Monthly Payment", "Interest Paid", "Principal Paid", "New Balance");
} // printInformation

void printAmortizationTable(int month, double oldBlnc, double mnthlyPymnt, double intrstPaid, double prncplPaid, double prncpl)
{
	printf("\n%2.0d %15.2lf %15.2lf %15.2lf %15.2lf %19.2lf", month, oldBlnc, mnthlyPymnt, intrstPaid, prncplPaid, fabs(prncpl));
}