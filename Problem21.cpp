// Problem21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
	Amicable numbers
	Problem 21

	Let d(n) be defined as the sum of proper divisors of n(numbers less than n which divide evenly into n).
	If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

	For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

	Evaluate the sum of all the amicable numbers under 10000.
*/

int main()
{
	int sum = 0;
	int amicable[10000];

	for (int i = 1; i < 10000; i++)
	{
		int count = 1;
		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0) // divisible
			{
				count += j;
				if (j * j != i)
					count += i / j;
			}
		}
		amicable[i] = count;
	}
	for (int i = 1; i < 10000; i++)
	{
		if (amicable[i] > i && amicable[i] < 10000 && amicable[amicable[i]] == i)
		{
			sum += i + amicable[i];
		}
	}
	printf("%d\n", sum);

    return 0;
}

