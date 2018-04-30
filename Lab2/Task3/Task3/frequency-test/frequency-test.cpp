#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include "../../../../Catch/catch.hpp"
#include "../frequency/frequency.h"

using namespace std;

bool IsMapEqual(map<string, size_t> map1, map<string, size_t> map2)
{
	return map1 == map2;
}

TEST_CASE("If start CountWordToStatistics(`hello`, testMap)  then testMap will be equal etalonMap")
{
	map<string, size_t> etalonMap = {{ "hello", 1 }};
	string word = "hello";
	map<string, size_t> testMap;
	CountWordToStatistics(word, testMap);
	REQUIRE(IsMapEqual(testMap, etalonMap));
}

TEST_CASE("If add word `hello` again into the testMap then testMap will be like (`hello`, 2) (equal etalonMap)")
{
	map<string, size_t> etalonMap = { { "hello", 2 } };
	string word = "hello";
	map<string, size_t> testMap;
	CountWordToStatistics(word, testMap);
	CountWordToStatistics(word, testMap); 
	REQUIRE(IsMapEqual(testMap, etalonMap));
}

TEST_CASE("Words with different case are equal")
{
	string wordUpperCase = "HeLLo";
	string wordLowCase = "hello";
	REQUIRE(wordLowCase == StringToLowerCase(wordUpperCase));
}

TEST_CASE("Russian words with different case are equal too")
{
	setlocale(LC_ALL, "Russian");
	string wordUpperCase = "ПрИВЕТ";
	string wordLowCase = "привет";
	REQUIRE(wordLowCase == StringToLowerCase(wordUpperCase));
}