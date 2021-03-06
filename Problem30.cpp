// Problem30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*Digit fifth powers
	Problem 30

	Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

		1634 = 14 + 64 + 34 + 44
		8208 = 84 + 24 + 04 + 84
		9474 = 94 + 44 + 74 + 44

	As 1 = 14 is not a sum it is not included.

	The sum of these numbers is 1634 + 8208 + 9474 = 19316.

	Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

int main()
{
	// 9^5 is 59049, so we should be safe to go under 1 million
	int total = 0;
	for (int i = 10; i < 1000000; i++)
	{
		int count = 0;
		int val = i;
		while (val > 0)
		{
			int digit = val % 10;
			count += digit * digit * digit * digit * digit;
			val /= 10;
		}
		if (i == count)
			total += i;
	}
	printf("%d\n", total);

    return 0;
}

