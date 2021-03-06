// Problem33.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*Digit cancelling fractions
	Problem 33

	The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

	We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

	There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

	If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

bool common(int *fact1, int *digFact1, int *fact2, int *digFact2);
void getFactors(int num, int* factors);
void simplifyFactors(int *fact1, int *fact2);

int main()
{
	int numerator = 1;
	int denominator = 1;
	int fact1[100], fact2[100], digFact1[100], digFact2[100];

	for (int i = 10; i <= 99; i++)
	{
		for (int j = i + 1; j <= 99; j++)
		{
			getFactors(j, fact2);
			if (j % 10 == 0)
				continue; // No zero
			if (i % 10 != j / 10 || i % 10 == j % 10)
				continue; // Must follow pattern
			getFactors(j % 10, digFact2);
			getFactors(i, fact1);
			getFactors(i / 10, digFact1);
			simplifyFactors(fact1, fact2);
			simplifyFactors(digFact1, digFact2);
			if (common(fact1, digFact1, fact2, digFact2))
			{
				numerator *= i / 10;
				denominator *= j % 10;
			}
		}
	}
	for (int i = 2; i <= 99; i++)
	{
		while (numerator % i == 0 &&
			   denominator % i == 0)
		{
			numerator /= i;
			denominator /= i;
		}
	}
	printf("%d\n", denominator);
    return 0;
}

bool common(int *fact1, int *digFact1, int *fact2, int *digFact2)
{
	// Fact1 should equal digFact1 and fact2 should equal digFact2
	for (int i = 2; i <= 99; i++)
	{
		if (fact1[i] != digFact1[i])
			return false;
		if (fact2[i] != digFact2[i])
			return false;
	}
	return true;
}

void getFactors(int num, int* factors)
{
	for (int i = 2; i <= 99; i++)
	{
		factors[i] = 0;
		while (num % i == 0)
		{
			factors[i]++;
			num /= i;
		}
	}
}

void simplifyFactors(int *fact1, int *fact2)
{
	for (int i = 2; i <= 99; i++)
	{
		while (fact1[i] > 0 && fact2[i] > 0)
		{
			fact1[i]--;
			fact2[i]--;
		}
	}
}

bool common(int first, int second)
{
	for (int i = 2; i <= 99; i++)
	{
		if (first * i == second &&
			first / 10 * i == second % 10)
			return true;
	}
	return false;
}