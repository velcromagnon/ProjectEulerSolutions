// Problem38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

/*Pandigital multiples
	Problem 38

	Take the number 192 and multiply it by each of 1, 2, and 3:

		192 × 1 = 192
		192 × 2 = 384
		192 × 3 = 576

	By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

	The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

	What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
*/

void initOcc(int *occ);
int addOcc(int num, int *occ);

int occ[10];

int main()
{
	string solution;

	for (int i = 1; i < 99999; i++)
	{
		initOcc(occ);
		int num = 0;
		for (int j = 1; j <= 5; j++)
		{
	 		int mult = i * j;
			int added = addOcc(mult, occ);
			if (added == 0) // invalid
				break;
			else
			{
				num += added;
				if (num == 9) // solution
				{
					string s;
					for (int k = 1; k <= j; k++)
					{
						s += to_string(i*k);
					}
					if (s > solution)
					   solution = s;
				}
			}
		}
	}
	cout << solution << endl;
    return 0;
}

void initOcc(int *occ)
{
	for (int i = 0; i < 10; i++)
	{
		occ[i] = 0;
	}
}

int addOcc(int num, int *occ)
{
	int count = 0;

	int val = num;
	while (val > 0)
	{
		if (val % 10 == 0) // Can't have digit 0.
			return 0;
		if (occ[val % 10] == 0)
		{
			occ[val % 10]++;
			count++;
		}
		else // Repeated digits.
			return 0;
		val /= 10;
	}
	return count;
}