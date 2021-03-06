// Problem36.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <iostream>

using namespace std;

/*
	Double - base palindromes
	Problem 36

	The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

	Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

	(Please note that the palindromic number, in either base, may not include leading zeros.)
*/

string createBinaryString(int i);
bool isPalindrome(string s);

int main()
{
	int sum = 0;
	for (int i = 1; i <= 1000000; i++)
	{
		string sDecimal = to_string(i);
		if (isPalindrome(sDecimal))
		{
			// Now create binary string
			string sBinary = createBinaryString(i);
			if (isPalindrome(sBinary))
			{
				cout << sDecimal << " " << sBinary << endl;
				sum += i;
			}
		}
	}
	cout << sum << endl;
    return 0;
}

string createBinaryString(int i)
{
	string s = "";
	int val = i;
	while (val > 0)
	{
		if (val % 2 == 0)
			s += '0';
		else
			s += '1';
		val /= 2;
	}
	return s;
}

bool isPalindrome(string s)
{
	for (unsigned i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - 1 - i])
			return false;
	}
	return true;
}