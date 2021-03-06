// Problem4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

/*
	Largest palindrome product
	Problem 4

	A palindromic number reads the same both ways.The largest palindrome made from the product of two 2 - digit numbers is 9009 = 91 × 99.

	Find the largest palindrome made from the product of two 3 - digit numbers.
*/

bool isPalindromic(int n);

int main()
{
	// Nested loop from 999-1. This allows you to short-circuit solutions.
	int bestSoFar = 0;
	for (int i = 999; i >= 1; i--)
	{
		if (i * 999 < bestSoFar)
			break;
		for (int j = i; j >= 1; j--)
		{
			if (i*j < bestSoFar)
				break;
			if (isPalindromic(i*j))
			{
				bestSoFar = i * j;
			}
		}
	}
	printf("%d\n", bestSoFar);
    return 0;
}

bool isPalindromic(int n)
{
	char pal[7];
	_itoa_s(n, pal, 7, 10);

	for (int start = 0, end = strlen(pal) - 1; start < end; start++, end--)
	{
		if (pal[start] != pal[end])
			return false;
	}

	return true;
}