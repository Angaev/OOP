#include "stdafx.h"
#include "../frequency/frequency.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

void CountWordToStatistics(string const& word, map<string, size_t>& statistic)
{
	++statistic[word];
}

void PrintFrequency(map<string, size_t> const& statisctic)
{
	for (auto item = statisctic.begin(); item != statisctic.end(); item++)
	{
		cout << item->first << " -> " << item->second <<"\n";
	}
}

void StringToLowerCase(string & line)
{
	transform(line.begin(), line.end(), line.begin(), tolower);
}