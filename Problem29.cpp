// Problem29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

using namespace std;

/*
	Distinct powers
	Problem 29

	Consider all integer combinations of ab for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5:

	2^2 = 4, 2^3 = 8, 2^4 = 16, 2^5 = 32
	3^2 = 9, 3^3 = 27, 3^4 = 81, 3^5 = 243
	4^2 = 16, 4^3 = 64, 4^4 = 256, 4^5 = 1024
	5^2 = 25, 5^3 = 125, 5^4 = 625, 5^5 = 3125

	If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms :

	4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

	How many distinct terms are in the sequence generated by ab for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100 ?
*/

int main()
{
	// Need to worry about sequences 2,4,8,16,32,64... 3,9,27,81... 5,25...6,36...7,49..10,100. Bases are 2, 3, 5, 6, 7, 10

	int result = 99 * 99;
	int duplicate;

	// powers of 2
	vector<int> v;
	duplicate = 0;
	for (int i = 2; i <= 100; i++)
	{
		if (find(v.begin(), v.end(), i) != v.end()) // 2
			duplicate++;
		else
			v.push_back(i);

		if (find(v.begin(), v.end(), i * 2) != v.end()) // 4
			duplicate++;
		else
			v.push_back(i*2);
		if (find(v.begin(), v.end(), i * 3) != v.end()) // 8
			duplicate++;
		else
			v.push_back(i*3);
		if (find(v.begin(), v.end(), i * 4) != v.end()) // 16
			duplicate++;
		else
			v.push_back(i*4);
		if (find(v.begin(), v.end(), i * 5) != v.end()) // 32
			duplicate++;
		else
			v.push_back(i*5);
		if (find(v.begin(), v.end(), i * 6) != v.end()) // 64
			duplicate++;
		else
			v.push_back(i*6);
	}
	result -= duplicate;
	// 3
	duplicate = 0;
	v.clear();
	for (int i = 2; i <= 100; i++)
	{
		if (find(v.begin(), v.end(), i) != v.end()) // 3
			duplicate++;
		else
			v.push_back(i);
		if (find(v.begin(), v.end(), i * 2) != v.end()) // 9
			duplicate++;
		else
			v.push_back(i*2);
		if (find(v.begin(), v.end(), i * 3) != v.end()) // 27
			duplicate++;
		else
			v.push_back(i*3);
		if (find(v.begin(), v.end(), i * 4) != v.end()) // 81
			duplicate++;
		else
			v.push_back(i*4);
	}
	result -= duplicate;

	duplicate = 0;
	v.clear(); // 5
	for (int i = 2; i <= 100; i++)
	{
		if (find(v.begin(), v.end(), i) != v.end()) // 5
			duplicate++;
		else
			v.push_back(i);
		if (find(v.begin(), v.end(), i * 2) != v.end()) // 25
			duplicate++;
		else
			v.push_back(i*2);
	}
	result -= duplicate;

	duplicate = 0;
	v.clear(); // 6
	for (int i = 2; i <= 100; i++)
	{
		if (find(v.begin(), v.end(), i) != v.end()) // 6
			duplicate++;
		else
			v.push_back(i);
		if (find(v.begin(), v.end(), i * 2) != v.end()) // 36
			duplicate++;
		else
			v.push_back(i*2);
	}
	result -= duplicate;

	duplicate = 0;
	v.clear(); // 7
	for (int i = 2; i <= 100; i++)
	{
		if (find(v.begin(), v.end(), i) != v.end()) // 7
			duplicate++;
		else
			v.push_back(i);
		if (find(v.begin(), v.end(), i * 2) != v.end()) // 49
			duplicate++;
		else
			v.push_back(i*2);
	}
	result -= duplicate;

	duplicate = 0;
	v.clear(); // 10
	for (int i = 2; i <= 100; i++)
	{
		if (find(v.begin(), v.end(), i) != v.end()) // 10
			duplicate++;
		else
			v.push_back(i);
		if (find(v.begin(), v.end(), i * 2) != v.end()) // 100
			duplicate++;
		else
			v.push_back(i*2);
	}
	result -= duplicate;

	printf("%d\n", result);
    return 0;
}

