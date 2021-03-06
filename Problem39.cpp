// Problem39.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>

/*Integer right triangles
	Problem 39

	If p is the perimeter of a right angle triangle with integral length sides, { a,b,c }, there are exactly three solutions for p = 120.

	{20, 48, 52}, { 24,45,51 }, { 30,40,50 }

	For which value of p ≤ 1000, is the number of solutions maximised ?
*/

int main()
{
	int solutionCount[1001] = { 0 };

	for (int i = 1; i <= 333; i++)
	{
		for (int j = i + 1; j <= 500; j++)
		{
			int k = (int) round(sqrt(i*i + j * j));
			if (i * i + j * j == k * k)
			{
				int perimeter = i + j + (int)k;
				if (perimeter <= 1000)
				{
					solutionCount[perimeter]++;
				}
			}
		}
	}
	int bestCount = 0;
	int bestNdx = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (solutionCount[i] > bestCount)
		{
			bestCount = solutionCount[i];
			bestNdx = i;
		}
	}
	printf("%d\n", bestNdx);

    return 0;
}

