// Problem3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <math.h>
#include <iostream>

/* 10001st prime
	Problem 7

	By listing the first six prime numbers : 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

	What is the 10,001st prime number ?
*/

int main()
{
	int numPrimes = 1;

	std::vector<int> primes = std::vector<int>();
	primes.push_back(2);

	int start = 3;
	while (primes.size() < 10001)
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
		}
		start += 2;
	}
	std::cout << primes.back() << std::endl;

	return 0;
}
