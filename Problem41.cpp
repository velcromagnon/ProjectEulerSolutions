// Problem41.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

/*Pandigital prime
	Problem 41

	We shall say that an n - digit number is pandigital if it makes use of all the digits 1 to n exactly once.For example, 2143 is a 4 - digit pandigital and is also prime.

	What is the largest n - digit pandigital prime that exists ?
*/

vector<int> primes;
int occ[10];

void panDigital(int digits, int remaining);

int main()
{
	// all 9's is ~10^9, so sqrt(10^9) is the maximum prime we need to check for. 31621
	
	primes.push_back(2);

	int start = 3;
	// Looping for potential primes.
	while ((long long)start <= 31621)
	{
		unsigned int i;
		bool prime = true;
		// go through known primes, stop at number square root.
		for (i = 0; i < primes.size() && primes[i] * primes[i] <= start; i++)
		{
			if (start % primes[i] == 0) // not prime
			{
				prime = false;
			}
		}
		// Build primes as we need them.
		if (prime)
		{
			primes.push_back(start);
		}
		start += 2;
	}
	// List of primes up to sqrt of maximum number
	for (int i = 1; i <= 9; i++)
	{
		memset(occ, 0, sizeof(occ));
		panDigital(i, i);
	}
    return 0;
}

int selected[10];

int isPrime(int number)
{
	for (unsigned int i = 0; i < primes.size(); i++)
	{
		if (number == primes[i])
			return 1;
		else if (number % primes[i] == 0)
			return 0;
	}
	return 1;
}

void panDigital(int digits, int remaining)
{
	if (remaining == 0)
	{
		int value = 0;
		for (int i = 0; i < digits; i++)
		{
			value = value * 10 + selected[i];
		}
		if (isPrime(value))
			cout << value << endl;
		return;
	}
	for (int i = 1; i <= digits; i++)
	{
		if (occ[i] != 0)
			continue;
		else
		{
			occ[i] = 1;
			selected[digits - remaining] = i;
			panDigital(digits, remaining - 1);
			occ[i] = 0; // reset
		}
	}
}
