#include "stdafx.h"
#include "../frequency/frequency.h"

using namespace std;

void CountWordToStatistics(string const& word, map<string, size_t>& statisctic)
{
	map<string, size_t>::iterator pos = statisctic.find(word);
	if (pos != statisctic.end())
	{
		pos -> second++;
	}
	else
	{
		statisctic.insert(pair<string, size_t>(word, 1));
	}
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