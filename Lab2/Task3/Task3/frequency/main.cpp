#include "stdafx.h"
using namespace std;

int main()
{
	string word;
	map <string, size_t> statisctic;
	while (cin >> word)
	{
		CountWordToStatistics(StringToLowerCase(word), statisctic);
	}

	PrintFrequency(statisctic);
    return 0;
}

