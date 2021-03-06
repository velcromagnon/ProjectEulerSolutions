// Problem22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

/*Names scores
	Problem 22

	Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

	For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

	What is the total of all the name scores in the file?
*/

int main()
{
	string line;
	vector<string> names;
	int total = 0;
	string nameList, name;

	while (getline(cin, name, ','))
	{
		if (name.front() == '"') {
			name.erase(0, 1);
			name.erase(name.size() - 1);
		}
		names.push_back(name);
	}
	sort(names.begin(), names.end());

	int count = 0;
	for (vector<string>::iterator it = names.begin(); it != names.end(); ++it) {
		count++; // starting at one?
		int sum = 0;
		for (char& c : *it)
		{
			sum += (int)(c - 'A' + 1);
		}
		total += count * sum;
	}
	cout << total << endl;

	return 0;
}

