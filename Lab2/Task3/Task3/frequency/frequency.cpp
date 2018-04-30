#include "stdafx.h"
#include "../frequency/frequency.h"

using namespace std;
using namespace boost;

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
		cout << item->first << " -> " << (static_cast<double>(item->second) / static_cast<double>(statisctic.size())) * 100 <<"\n";
	}
}

void StringToLowerCase(string & line)
{
	//return to_lower_copy(line);
	//for_each(line.begin(), line.end(), [](char ch) {tolower(ch); });
	transform(line.begin(), line.end(), line.begin(), tolower);
}