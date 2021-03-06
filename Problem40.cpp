// Problem40.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

/*Champernowne's constant
	Problem 40

	An irrational decimal fraction is created by concatenating the positive integers:

	0.123456789101112131415161718192021...

	It can be seen that the 12th digit of the fractional part is 1.

	If dn represents the nth digit of the fractional part, find the value of the following expression.

	d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/

int main()
{
	int mult = 1;
	int startNdx = 1;
	// Take the easy way out. Build a string
	string s;
	int ndx = 1;
	while (s.length() < 1000000)
	{
		s += to_string(ndx);
		ndx++;
	}
	mult *= s[1-1] - '0';
	mult *= s[10 - 1] - '0';
	mult *= s[100 - 1] - '0';
	mult *= s[1000 - 1] - '0';
	mult *= s[10000 - 1] - '0';
	mult *= s[100000 - 1] - '0';
	mult *= s[1000000 - 1] - '0';

	cout << mult << endl;

    return 0;
}

