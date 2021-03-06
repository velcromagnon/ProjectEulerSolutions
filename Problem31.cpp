// Problem31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*Coin sums
	Problem 31

	In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

		1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

	It is possible to make £2 in the following way:

		1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

	How many different ways can £2 be made using any number of coins?
*/

int values[8] = { 200, 100, 50, 20, 10, 5, 2, 1 };
int answers[8][201];

int rec(int type, int remaining);

int main()
{
	// The technique should be memoization. Remember previous answers and limit recursion when possible.
	// Set all answers to -1 unknown except for 0.
	for (int type = 0; type < 8; type++)
	{
		for (int val = 0; val <= 200; val++)
		{
			if (val == 0)
				answers[type][val] = 1;
			else
				answers[type][val] = -1;
		}
	}
	printf("%d\n", rec(0, 200));

    return 0;
}

// type represents the coin type, remaining is what's left to find.
int rec(int type, int remaining)
{
	if (type == 7) // for pennies, you have one way of any amount.
	{
		answers[type][remaining] = 1;
		return 1;
	}
	if (answers[type][remaining] != -1)
		return answers[type][remaining];
	
	int value = values[type];
	answers[type][remaining] = 0;
	for (int cents = 0; cents <= remaining; cents += value)
	{
		int score = rec(type + 1, remaining - cents);
		answers[type][remaining] += score;
	}
	return answers[type][remaining];
}
