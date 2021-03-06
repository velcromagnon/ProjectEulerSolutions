// Problem24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*Lexicographic permutations
	Problem 24

	A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

	012   021   102   120   201   210

	What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

int main()
{
	int target = 1000000 - 1; // 0 is the 1st one
	// For each digit there should be n! possibilities.
	int factorials[10];
	factorials[0] = 1;
	int soFar = 1;
	for (int i = 1; i < 10; i++)
	{
		soFar *= i;
		factorials[i] = soFar;
	}

	bool digitsChosen[10];
	for (int i = 0; i < 10; i++)
		digitsChosen[i] = false;

	for (int ndx = 9; ndx >= 0; ndx--)
	{
		int digitOffset = target / factorials[ndx] + 1;
		// Don't reuse digits
		int selectedDigit;
		for (int i = 0; i < 10; i++)
		{
			if (!digitsChosen[i]) // Skip and go to next.
			{
				digitOffset--;
				if (digitOffset == 0)
				{
					selectedDigit = i;
					break;
				}
			}
		}
		digitsChosen[selectedDigit] = true;
		printf("%d", selectedDigit);
		target = target % factorials[ndx];
	}
	printf("\n");

    return 0;
}

