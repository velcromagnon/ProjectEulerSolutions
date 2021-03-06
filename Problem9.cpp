// Problem9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* Special Pythagorean triplet
Problem 9

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
	a^2 + b^2 = c^2

	For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.
*/

int main()
{
	int c;
	for (int a = 3; a < 1000; a++)
	{
		for (int b = a + 1; b < 1000; b++)
		{
			if (a + 2 * b > 1000)
				break;
			c = 1000 - (a + b);
			if (a * a + b * b == c * c)
				printf("%d %d %d %d\n", a, b, c, a*b*c);
		}
	}
    return 0;
}

