#include "stdafx.h"
using namespace std;

int main()
{
	string word;
	map <string, size_t> statisctic;
	while (cin >> word)
	{
		StringToLowerCase(word);
		CountWordToStatistics(word, statisctic);
	}

	PrintFrequency(statisctic);
    return 0;
}

