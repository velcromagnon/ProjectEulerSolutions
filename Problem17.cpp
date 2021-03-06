// Problem17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
using namespace std;

/*
	If the numbers 1 to 5 are written out in words : one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

	If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used ?

	NOTE : Do not count spaces or hyphens.For example, 342 (three hundred and forty - two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.The use of "and" when writing out numbers is in compliance with British usage.
*/

string singleDigits[20] = { "zero", "one", "two", "three", "four",
"five", "six", "seven", "eight", "nine",
"ten", "eleven", "twelve", "thirteen", "fourteen",
"fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string tens[10] = { "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

int getLength(int i);

int main()
{
	int length = 0;
	for (int i = 1; i <= 1000; i++)
	{
		int numLen = getLength(i);
//		printf("For number %d, length without spaces or hyphens is %d\n", i, numLen);
		length += numLen;
	}
	printf("%d\n", length);

    return 0;
}

int getLength(int i)
{
	int length = 0;

	if (i >= 100 && i % 100 != 0)
		length += 3; // and
	if (i >= 1000)
	{
		length += singleDigits[i / 1000].length();
		length += 8; // thousand
		i = i % 1000;
	}
	if (i >= 100)
	{
		length += singleDigits[i / 100].length();
		length += 7; // hundred
		i = i % 100;
	}
	if (i >= 20)
	{
		length += tens[i / 10].length();
		i = i % 10;
	}
	if (i > 0 && i < 20)
	{
		length += singleDigits[i].length();
	}
	return length;
}
