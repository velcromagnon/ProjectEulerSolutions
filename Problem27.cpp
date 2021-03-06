// Problem27.cpp : Defines the entry point for the console application.
//
/*
	Quadratic primes
	Problem 27

	Euler discovered the remarkable quadratic formula :

	n^2 + n + 41

	It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39
	.However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41^2 + 41 + 41

	is clearly divisible by 41.

	The incredible formula n^2−79n + 1601
	was discovered, which produces 80 primes for the consecutive values 0≤n≤79

	.The product of the coefficients, −79 and 1601, is −126479.

	Considering quadratics of the form :

	n^2 + an + b

	, where | a | <1000 and | b | ≤1000

	where | n |
	is the modulus / absolute value of n
	e.g. | 11 |= 11 and | −4 |= 4

	Find the product of the coefficients, a
	and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
*/

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

vector<int> primes();

int main()
{
	std::vector<int> primes = std::vector<int>();
	primes.push_back(2);

	int start = 3;
	long long sum = 2;
	// Looping for potential primes somewhere above 1 million, enough to accommodate the formula.
	while ((long long)start <= 1200000)
	{
		unsigned int i;
		bool prime = true;
		// go through known primes, stop at number square root.
		for (i = 0; i < primes.size() && primes[i] * primes[i] <= start; i++)
		{
			if (start % primes[i] == 0) // not prime
			{
				prime = false;
				break;
			}
		}
		if (prime)
			primes.push_back(start);
		start += 2;
	}

	int maxCount = 0;
	// Now build a boolean array rather than cycling through primes all of the time
	vector<bool> isPrime(1200000);
	for (int& i : primes) {
		isPrime[i] = true;
	}

	for (int a = -1000; a <= 1000; a++)
	{
		for (int b = -1000; b <= 1000; b++)
		{
			int n = 0;
			while (n*n + a*n + b > 0 && isPrime[n*n + a*n + b])
			{
				n++;
			}
			if (n > maxCount)
			{
				maxCount = n;
				cout << a << " " << b << " " << n << " " << a * b << endl;
			}
		}
	}
	return 0;
}

