// Problem28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
	Number spiral diagonals
	Problem 28

	Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

	21 22 23 24 25
	20  7  8  9 10
	19  6  1  2 11
	18  5  4  3 12
	17 16 15 14 13

	It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

int main()
{
	long long score = 1;
	int base = 6;
	for (int size = 3; size <= 1001; size += 2)
	{
		score += 4 * base;
		base += 4 * size + 1;
	}
	printf("%I64i\n", score);
    return 0;
}

