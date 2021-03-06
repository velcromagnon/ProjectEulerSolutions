// Problem6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
	Sum square difference
	Problem 6

	The sum of the squares of the first ten natural numbers is,
	1^2 + 2^2 + ... + 10^2 = 385

	The square of the sum of the first ten natural numbers is,
	(1 + 2 + ... + 10)^2 = 55^2 = 3025

	Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

	Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*/

int main()
{
	// Formula for sum of squares is (n^3)/3 + (n^2)/2 + n / 6
	// Formula for sum of numbers is n * (n + 1) / 2
	int squareSum = (2 * (100 * 100 * 100) + 3 * (100 * 100) + 100) / 6;
	int sum = 100 * (100 + 1) / 2;
	printf("%d\n", sum * sum - squareSum);

    return 0;
}

