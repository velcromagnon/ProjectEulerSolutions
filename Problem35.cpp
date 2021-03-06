// Problem35.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*Circular primes
	Problem 35

	The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

	There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

	How many circular primes are there below one million?
*/

vector<int> getRotations(int i);

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
	long long sum = 2;
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
			sum += start;
		}
		start += 2;
	}

	int count = 0;
	for (unsigned int i = 0; i < primes.size(); i++)
	{
		if (primes_lookup[primes[i]] == true) // mark ones already seen
		{
			// Get a numeric list of all digit rotations.
			vector<int> rotationList = getRotations(primes[i]);
			bool isPrime = true;
			for (unsigned int j = 0; j < rotationList.size(); j++)
			{
				if (primes_lookup[rotationList[j]] == false)
					isPrime = false;
			}
			if (isPrime)
			{
				for (unsigned int j = 0; j < rotationList.size(); j++)
				{
					if (primes_lookup[rotationList[j]] == true)
					{
						primes_lookup[rotationList[j]] = false;
						count++;
					}
				}
			}
		}
	}
	cout << count << endl;
	
	return 0;
}

vector<int> getRotations(int i)
{
	vector<int> v;
	string s = to_string(i);
	for (unsigned int i = 0; i < s.length(); i++)
	{
		string rotation = s.substr(i, s.length() - i) + s.substr(0, i);
		int val = atoi(rotation.c_str());
		v.push_back(val);
	}

	return v;
}