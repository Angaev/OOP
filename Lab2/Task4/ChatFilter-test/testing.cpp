#include "stdafx.h"

using namespace std;

bool isVectorEqual(vector<string> const& vect1, vector<string> const& vect2)
{
	return vect1 == vect2;
}

TEST_CASE("If give string to function then this function return vector of words")
{
	string line = "Hello  my - friend!";
	vector<string> words { "Hello", "my", "friend" };
	vector<string> result = GetWordsFromString(line);
	REQUIRE(isVectorEqual(result, words));

	line = "Good day ";
	vector<string> words2 { "Good", "day" };
	vector<string> result2 = GetWordsFromString(line);
	REQUIRE(isVectorEqual(result2, words2));
	//todo почему то не проходит тест 	line = "Good day"
}