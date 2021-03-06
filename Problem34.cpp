// Problem34.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*Digit factorials
	Problem 34

	145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

	Find the sum of all numbers which are equal to the sum of the factorial of their digits.

	Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/

int main()
{
	int factorials[10];
	int total = 0;

	int fact = 1;
	factorials[0] = 1;
	for (int i = 1; i <= 9; i++)
	{
		fact *= i;
		factorials[i] = fact;
	}
	for (int i = 10; i < 9 * factorials[9]; i++)
	{
		int sum = 0;
		int val = i;
		while (val > 0)
		{
			sum += factorials[val % 10];
			val /= 10;
		}
		if (i == sum)
		{
			printf("%d\n", i);
			total += i;
		}
	}
	printf("Total is %d\n", total);
    return 0;
}

