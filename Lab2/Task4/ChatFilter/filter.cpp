#include "stdafx.h"
#include "filter.h"

using namespace std;


vector<string> GetWordsFromString(string const& line) 
{

	//isAlpha
	//for_each
	vector<string> words;
	string word;
	for_each(line.begin(), line.end(), [&word, &words](char c) { if (isalpha(c)) { word += c; } else { if (!word.empty()) { words.push_back(word); word.clear(); } } });

	return words;
}