// Problem19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
	Counting Sundays
	Problem 19

	You are given the following information, but you may prefer to do some research for yourself.

		1 Jan 1900 was a Monday.
		Thirty days has September,
		April, June and November.
		All the rest have thirty-one,
		Saving February alone,
		Which has twenty-eight, rain or shine.
		And on leap years, twenty-nine.
		A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

	How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int isLeap(int year);

int main()
{
	// Sunday = 0, saturday = 6
	int dayOfWeek = 1; // starts on a monday.
	int currentYear = 1900;
	int currentMonth = 0;
	int daysToAdvance;
	int sundays = 0;
	while (currentYear <= 2000)
	{
		daysToAdvance = daysInMonth[currentMonth];
		if (currentMonth == 1) // check leap year
		{
			if (isLeap(currentYear))
				daysToAdvance++;
		}
		dayOfWeek = (dayOfWeek + daysToAdvance) % 7;
		if (dayOfWeek == 0 && currentYear > 1900) // Skip first year from problem definition.
			sundays++;
		currentMonth++;
		if (currentMonth == 12)
		{
			currentMonth = 0;
			currentYear++;
		}
	}
	printf("%d\n", sundays);
	
    return 0;
}

int isLeap(int year)
{
	if (year % 400 == 0)
		return true;
	else if (year % 100 == 0)
		return false;
	else
		return (year % 4 == 0);
}
