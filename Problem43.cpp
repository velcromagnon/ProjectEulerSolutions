// Problem43.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/*Sub-string divisibility
	Problem 43

	The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

	Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

		d2d3d4=406 is divisible by 2
		d3d4d5=063 is divisible by 3
		d4d5d6=635 is divisible by 5
		d5d6d7=357 is divisible by 7
		d6d7d8=572 is divisible by 11
		d7d8d9=728 is divisible by 13
		d8d9d10=289 is divisible by 17

	Find the sum of all 0 to 9 pandigital numbers with this property.
*/

int occ[10];
int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
long long total = 0;

void panDigital(int digits, int remaining);

int main()
{
	memset(occ, 0, sizeof(occ));
	panDigital(10, 10);

	cout << total << endl;

	return 0;
}

int selected[10];

void panDigital(int digits, int remaining)
{
	if (remaining == 0)
	{
		long long value = 0;
		for (int i = 0; i < digits; i++)
		{
			value = value * 10 + selected[i];
		}
		total += value;
		return;
	}
	for (int i = 0; i < digits; i++)
	{
		if (occ[i] != 0)
			continue;
		else
		{
			// First check divisibility
			bool valid = true;
			selected[digits - remaining] = i;
			if (remaining <= 7)
			{
				int index = digits - remaining;
				int value = selected[index - 2] * 100 + selected[index - 1] * 10 + selected[index];
				if (value % primes[index - 3] != 0)
					valid = false;
			}
			if (valid) {
				occ[i] = 1;
				panDigital(digits, remaining - 1);
				occ[i] = 0; // reset
			}
		}
	}
}
