// Problem42.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*Coded triangle numbers
	Problem 42

	The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

	1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

	By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

	Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
*/


int main()
{
	// Build triangular numbers
	vector<int> triangular;

	int sum = 0;
	int offset = 0;
	for (int i = 0; i < 100; i++)
	{
		offset++;
		sum += offset;
		triangular.push_back(sum);
	}

	string name;
	int count = 0;
	while (getline(cin, name, ','))
	{
		if (name.front() == '"') {
			name.erase(0, 1);
			name.erase(name.size() - 1);
		}
		int score = 0;
		for (char& c : name)
		{
			score += (c - 'A') + 1;
		}
		for (int i = 0; i < 1000 && triangular[i] <= score; i++)
		{
			if (triangular[i] == score)
				count++;
		}
	}
	cout << count << endl;

    return 0;
}

