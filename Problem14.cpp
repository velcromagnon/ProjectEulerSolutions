// Problem14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* Longest Collatz sequence
	Problem 14

	The following iterative sequence is defined for the set of positive integers :

	n → n / 2 (n is even)
	n → 3n + 1 (n is odd)

	Using the rule above and starting with 13, we generate the following sequence :
	13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

	It can be seen that this sequence(starting at 13 and finishing at 1) contains 10 terms.Although it has not been proved yet(Collatz Problem), it is thought that all starting numbers finish at 1.

	Which starting number, under one million, produces the longest chain ?

NOTE : Once the chain starts the terms are allowed to go above one million.
*/

int bestValue = 1;
int bestNumber = 1;
int counts[1000000];

int main()
{
	counts[1] = 1; // Start with the base case of 1.
	// Use memoization, keep track of what you've found so far and stop
	for (int i = 2; i < 1000000; i++)
	{
		int countSoFar = 0;
		long long temp = i;
		while (temp > 1000000 || counts[temp] == 0) // Above max, there is no answer.
		{
			countSoFar++;
			if (temp % 2 == 0)
				temp = temp / 2;
			else
				temp = temp * 3 + 1;
		}
		counts[i] = countSoFar + counts[temp];
		if (counts[i] > bestValue)
		{
			bestValue = counts[i];
			bestNumber = i;
			printf("Starting at %d the longest chain is %d\n", bestNumber, counts[i]);
		}
	}
    return 0;
}

