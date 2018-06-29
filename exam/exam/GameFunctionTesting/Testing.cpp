#include "stdafx.h"
#include "..\WordGame/GameFunction.h"
#include "../../../Catch/catch.hpp"
#include <algorithm>

using namespace std;

TEST_CASE("From word telegram can make word gram or tele")
{
	string word = "telegram";
	CHECK(CanMakeSubword(word, "gram"s) == true);
	CHECK(CanMakeSubword(word, "tele"s) == true);
}

TEST_CASE("From word telegram can't make word telepuzik or gramm")
{
	string word = "telegram";
	CHECK(CanMakeSubword(word, "telepuzik"s) == false);
	CHECK(CanMakeSubword(word, "gramm"s) == false);
}

TEST_CASE("Can know word has benn used already")
{
	set<string> wordList = { "hello"s, "world"s, "and"s, "vasya"s };
	CHECK(IsWordUsedBefore(wordList, "hello"s));
	CHECK(IsWordUsedBefore(wordList, "world"s));
	CHECK(IsWordUsedBefore(wordList, "and"s));
	CHECK(IsWordUsedBefore(wordList, "vasya"s));

	CHECK(!IsWordUsedBefore(wordList, "goodbye"s));
	CHECK(!IsWordUsedBefore(wordList, "word"s));
	CHECK(!IsWordUsedBefore(wordList, "or"s));
	CHECK(!IsWordUsedBefore(wordList, "petya"s));
}