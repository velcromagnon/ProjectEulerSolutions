// Problem46.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <math.h>

using namespace std;

/*
	Goldbach's other conjecture
	Problem 46

	It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

	9 = 7 + 2×12
	15 = 7 + 2×22
	21 = 3 + 2×32
	25 = 7 + 2×32
	27 = 19 + 2×22
	33 = 31 + 2×12

	It turns out that the conjecture was false.

	What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/
int prime_lookup[100000];

int main()
{
	vector<int> primes;
	primes.push_back(2);

	for (int i = 0; i < 100000; i++)
		prime_lookup[i] = 0;

	int start = 3;
	while (start < 100000)
	{
		bool prime = true;
		for (int i = 0; i < primes.size() && i * i <= start; i++)
		{
			if (start % primes[i] == 0)
				prime = false;
		}
		if (prime)
		{
			primes.push_back(start);
			prime_lookup[start] = 1;
		}
		start += 2;
	}
	// primes to 100K
	for (int i = 3; i < 100000; i += 2)
	{
		if (prime_lookup[i])
			continue;
		for (unsigned int j = 0; j < primes.size(); j++)
		{
			if (primes[j] > i)
			{
				printf("%d\n", i);
				break;
			}
			double diff = (i - primes[j]) / 2.0;
			int sq = (int) round(sqrt(diff));
			if (i - primes[j] - 2 * sq * sq == 0)
			{
				// Found a match
				break;
			}
		}
	}
    return 0;
}

