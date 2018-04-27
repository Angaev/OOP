#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include "../../../../Catch/catch.hpp"
#include "../frequency/frequency.h"

using namespace std;

bool isVectorsEqual(vector<string> const& v1, vector<string> const& v2)
{
	return v1 == v2;
}

TEST_CASE("Function GetWordsFromString(`hello world`) return words `hello` and `world`")
{
	vector<string> etalon = { "hello", "world" };
	string line = "hello    world";
	vector<string> result = GetWordsFromString(line);
	REQUIRE(isVectorsEqual(result, etalon));
}

TEST_CASE("GetWordsFromString(`hello world `) return words `hello` and `world`")
{
	vector<string> etalon = { "hello", "world" };
	string line = "hello world ";
	vector<string> result = GetWordsFromString(line);
	REQUIRE(isVectorsEqual(result, etalon));
}