// Problem3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <math.h>
#include <iostream>

/* Largest prime factor
   Problem 3

   The prime factors of 13195 are 5, 7, 13 and 29.

   What is the largest prime factor of the number 600851475143 ?
*/

int main()
{
	long long target = 600851475143;
	int numPrimes = 1;

	std::vector<int> primes = std::vector<int>();
	primes.push_back(2);

	int start = 3;
	while ((long long)start * start <= target)
	{
		unsigned int i;
		// go through known primes
		for (i = 0; i < primes.size(); i++)
		{
			if (start % primes[i] == 0) // not prime
				break;
		}
		// Build primes as we need them.
		if (i == primes.size())
		{
			primes.push_back(start);
			// Try to divide primes as we find them.
			while (target % start == 0)
			{
				target /= start;
			}
		}
		start += 2;
	}
	std::cout << target << std::endl;

    return 0;
}

