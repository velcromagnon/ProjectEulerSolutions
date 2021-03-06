// Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* Problem Statement:

   If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
   Find the sum of all the multiples of 3 or 5 below 1000.
   */

int calcTriangle(int n);

int main()
{
	// Trivial way, loop through from 1 to 1000 and check for divisibility by either 3 or 5 and add the value.
	// Better way, figure out many 3's there are, how many 5's, how many 15's and compute from there.
	int numberOf3s = 999 / 3;
	int value3 = 3 * calcTriangle(numberOf3s);
	int numberOf5s = 999 / 5;
	int value5 = 5 * calcTriangle(numberOf5s);
	int numberOf15s = 999 / 15;
	int value15 = 15 * calcTriangle(numberOf15s);

	printf("%d\n", value3 + value5 - value15);
    return 0;
}

int calcTriangle(int n)
{
	return n * (n + 1) / 2;
}

