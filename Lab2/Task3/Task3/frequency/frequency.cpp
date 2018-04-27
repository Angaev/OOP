#include "stdafx.h"
#include "../frequency/frequency.h"
#include <algorithm>

using namespace std;

void Fucntion(char c)
{

}

vector<string>GetWordsFromString(string const& line)
{
	vector<string> result = {};
	string word;
	for_each(line.begin(), line.end(), [&result, &word](char c) { if (isalpha(c)) { word += c; } else { result.push_back(word); word.clear(); }; });
	return result;
}
