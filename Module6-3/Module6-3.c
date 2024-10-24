/* Project 53 on page 244/245
   Written by: Zara Sykes
   Date: 10/10/2024
   Due Date: 10/13/2024
*/
#include <stdio.h>
// Function Declarations
void getScores(int* score1, int* score2, int* score3);
char gradeCalc(int score1, int score2, int score3, int* avrgScore, int scndthrdAvrg);
void printRes(char gradeLetter, int avrgScore);

int main(void)
{
// Local Declarations
	int score1 = 0, score2 = 0, score3 = 0, avrgScore = 0, scndthrdAvrg = 0;
	char gradeLetter = 'F';
	getScores(&score1, &score2, &score3);
	gradeLetter = gradeCalc(score1, score2, score3, &avrgScore, scndthrdAvrg);
	printRes(gradeLetter, avrgScore);
	return;
} // Main

void getScores(int* score1, int* score2, int* score3)
{
	printf("Please enter the first test score grade: ");
	scanf_s("%d", score1);

	printf("\nPlease enter the second test score grade: ");
	scanf_s("%d", score2);

	printf("\nPlease enter the third test score grade: ");
	scanf_s("%d", score3);
	printf("\n");
}

char gradeCalc(int score1, int score2, int score3, int* avrgScore, int scndthrdAvrg)
{
	// Statements
	*avrgScore = (score1 + score2 + score3) / 3;
	scndthrdAvrg = (score2 + score3) / 2;
	char temp = 'F';
	if (*avrgScore >= 90)
		temp = 'A';
	else if (*avrgScore >= 70 && *avrgScore < 90)
		if (score3 > 90)
			temp = 'A';
		else
			temp = 'B';
	else if (*avrgScore >= 50 && *avrgScore < 70)
		if (scndthrdAvrg > 70)
			temp = 'C';
		else
			temp = 'D';
// avrgScore < 50 at this point, remains preset char value

	return temp;
}
/* I'm not certain if I was only supposed to print the letter grade, since the
   assignment said "print results in the book, so I added the average score to
   be printed as well in the print function.
*/
void printRes(char gradeLetter, int avrgScore)
{
	printf("The average score is: %d", avrgScore);
	printf("\nThe grade letter is: %c", gradeLetter);
	return;
}