// Problem37.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*Truncatable primes
	Problem 37

	The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

	Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

	NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

vector<int> getTruncations(int i);

int main()
{
	vector<int> primes;
	primes.push_back(2);

	bool primes_lookup[1000000];
	for (int i = 0; i < 1000000; i++)
	{
		primes_lookup[i] = false;
	}
	primes_lookup[2] = true;

	int start = 3;
	// Looping for potential primes.
	while ((long long)start <= 1000000)
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
			primes_lookup[start] = 1;
			primes.push_back(start);
		}
		start += 2;
	}

	int sum = 0;
	for (unsigned int i = 0; i < primes.size(); i++)
	{
		if (primes[i] < 10)
			continue;
		if (primes_lookup[primes[i]] == true) // mark ones already seen
		{
			// Get a numeric list of all digit rotations.
			vector<int> truncationList = getTruncations(primes[i]);
			bool isPrime = true;
			for (unsigned int j = 0; j < truncationList.size(); j++)
			{
				if (primes_lookup[truncationList[j]] == false)
					isPrime = false;
			}
			if (isPrime)
			{
				sum += primes[i];
			}
		}
	}
	cout << sum << endl;

	return 0;
}

vector<int> getTruncations(int i)
{
	vector<int> v;
	string s = to_string(i);
	for (unsigned int i = 1; i < s.length(); i++)
	{
		string truncation = s.substr(i, s.length() - i);
		int val = atoi(truncation.c_str());
		v.push_back(val);
		truncation = s.substr(0, s.length() - i);
		val = atoi(truncation.c_str());
		v.push_back(val);
	}

	return v;
}