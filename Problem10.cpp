// Problem10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

/*Summation of primes
	Problem 10

	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

	Find the sum of all the primes below two million.
*/

vector<int> primes();

int main()
{
	std::vector<int> primes = std::vector<int>();
	primes.push_back(2);

	int start = 3;
	long long sum = 2;
	// Looping for potential primes.
	while ((long long)start <= 2000000)
	{
		unsigned int i;
		bool prime = true;
		// go through known primes, stop at number square root.
		for (i = 0; i < primes.size() && primes[i]*primes[i] <= start; i++)
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
			sum += start;
		}
		start += 2;
	}
	std::cout << sum << std::endl;
    return 0;
}

