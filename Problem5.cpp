// Problem5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
	Smallest multiple
	Problem 5

	2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

	What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?
*/

int main()
{
	// It would have the factors of 2, 2, 2, 2 for 16, 3, 3 for 9, then 5, 7, 11, 13, 17, 19 for other primes.
	long long answer = 2 * 2 * 2 * 2 * 3 * 3 * 5 * 7 * 11 * 13 * 17 * 19;
	printf("%I64d\n", answer);
    return 0;
}

