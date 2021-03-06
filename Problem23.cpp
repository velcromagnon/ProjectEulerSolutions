// Problem23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
	Non - abundant sums
	Problem 23

	A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

	A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

	As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
	However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

	Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

int main()
{
	int numAbundant = 0;
	int abundant[30001];
	bool found[30001];
	long long total = 0;

	// Initialize found array
	for (int i = 0; i <= 30000; i++)
		found[i] = false;

	for (int i = 1; i <= 30000; i++)
	{
		int sum = 1;
		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				sum += j;
				if (i != j * j)
					sum += i / j;
			}
		}
		if (sum > i) // abundant
		{
			abundant[numAbundant++] = i;
		}
		for (int j = 0; j < numAbundant; j++)
		{
			if (abundant[j] + abundant[numAbundant - 1] <= 30000)
				found[abundant[j] + abundant[numAbundant - 1]] = true;
			else
				break;
		}
	}
	for (int i = 1; i <= 28123; i++)
	{
		if (!found[i])
			total += i;
	}
	printf("%I64i\n", total);
    return 0;
}

