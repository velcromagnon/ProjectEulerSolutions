// Problem15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
	Lattice paths
	Problem 15

	Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

	How many such routes are there through a 20×20 grid ?
*/

int main()
{
	long long paths[21][21];
	long long fromX, fromY;
	paths[0][0] = 1;
	for (int y = 0; y < 21; y++)
	{
		for (int x = 0; x < 21; x++)
		{
			if (x == 0 && y == 0) // Leave this as 1.
				continue;
			if (y == 0)
				fromY = 0;
			else
				fromY = paths[y - 1][x];
			if (x == 0)
				fromX = 0;
			else
				fromX = paths[y][x - 1];
			paths[y][x] = fromY + fromX;
		}
	}
	printf("%I64i\n", paths[20][20]);
    return 0;
}

