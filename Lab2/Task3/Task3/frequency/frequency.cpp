#include "stdafx.h"
#include "../frequency/frequency.h"
#include <algorithm>

using namespace std;

void CollectCharToWords(char c, string &word, vector<string> & result)
{
	if (isalpha(c)) 
	{
		word += c;
	}
	else 
	{ 
		result.push_back(word); 
		word.clear(); 
	}
}

vector<string>GetWordsFromString(string const& line)
{
	vector<string> result = {};
	string word;
	for_each(line.begin(), line.end(), [&result, &word](char c) {CollectCharToWords(c, word, result); });
	return result;
}
