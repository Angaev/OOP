#include "stdafx.h"

using namespace std;

string GetLastEngWordInDictionary(const map<string, string>& dictionary)
{
	return dictionary.end().first();
}

TEST_CASE("dictionary add new word test")
{
	map<string, string> testDictionary;
	string engWord = "hello";
	string rusWord = "Привет";
	AddWord(engWord, rusWord, testDictionary);
}