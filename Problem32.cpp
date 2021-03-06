// Problem32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*Pandigital products
	Problem 32

	We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

	The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

	Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
	HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

int get_occ(int value, int *occ);
bool common(int *occ1, int *occ2);
bool ok_occ(int *occ);

// Occurrences of each digit in number.
int first_occ[10];
int second_occ[10];
int product_occ[10];

int numProducts = 0;
int products[1000];
int sum = 0;

int main()
{
	for (int i = 1; i <= 99; i++)
	{
		int countFirst = get_occ(i, first_occ);
		if (ok_occ(first_occ))
		{
			for (int j = 100; j <= 9999; j++)
			{
				int countSecond = get_occ(j, second_occ);
				if (ok_occ(second_occ) && !common(first_occ, second_occ))
				{
					int product = i * j;
					int countProduct = get_occ(product, product_occ);
					if (ok_occ(product_occ) && 
						countFirst + countSecond + countProduct == 9 &&
						!common(first_occ, product_occ) &&
						!common(second_occ, product_occ))
					{
						int solutionNdx;
						printf("%d times %d is %d\n", i, j, product);
						for (solutionNdx = 0; solutionNdx < numProducts; solutionNdx++)
						{
							if (product == products[solutionNdx])
								break;
						}
						if (solutionNdx == numProducts)
						{
							sum += product;
							products[numProducts++] = product;
						}
					}
				}
			}
		}
	}
	printf("%d\n", sum);
    return 0;
}

int get_occ(int value, int *occ)
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		occ[i] = 0;
	}
	int digit;
	while (value > 0)
	{
		count++;
		digit = value % 10;
		occ[digit]++;
		value /= 10;
	}
	return count;
}

bool ok_occ(int *occ)
{
	if (occ[0] > 0)
		return false;
	for (int i = 1; i < 10; i++)
	{
		if (occ[i] > 1)
			return false;
	}
	return true;
}

bool common(int *occ1, int *occ2)
{
	for (int i = 1; i < 10; i++)
	{
		if (occ1[i] > 0 && occ2[i] > 0)
			return true;
	}
	return false;
}