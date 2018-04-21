#include "stdafx.h"
#include "../PrimeNumbers/PrimeNumbersGenerator.h"
#include "../../../Catch/catch.hpp"
#include <algorithm>

using namespace std;

bool isVectorEqual(std::vector<bool> const& vect1, std::vector<bool> const& vect2)
{
	
	return vect1 == vect2;
}

bool isCountTrueElementsEqual(std::vector<bool> const& vect, size_t size)
{
	size_t count = 0;
	for_each(vect.begin(), vect.end(), [&count](bool element) {if (element) { count++; }});
	return count == size;
}

bool isSetEqual(set<int> const& set1, set<int> const& set2)
{
	return set1 == set2;
}

TEST_CASE("if function GetSieve give parametr negaive number then function return vector<bool> {false}")
{
	vector<bool> etalon {false};
	vector<bool> result = GetSieve(-1);
	REQUIRE(isVectorEqual(etalon, result));
}


TEST_CASE("if function GetSieve give parametr 2 then function return vector<bool> {false, false, true}")
{
	vector<bool> etalon {false, false, true};
	vector<bool> result = GetSieve(2);
	REQUIRE(isVectorEqual(etalon, result));
}

TEST_CASE("if function GetSieve give parametr 30 then function return 10 true elements")
{
	vector<bool> etalon { false, false, true };
	vector<bool> result = GetSieve(30);
	REQUIRE(isCountTrueElementsEqual(result, 10));
}

TEST_CASE("if function GeneratePrimeNumbersSet give parametr 13 then function return 2, 3, 5, 7, 11, 13")
{
	set<int> etalon { 2, 3, 5, 7, 11, 13 };
	set<int> result = GeneratePrimeNumbersSet(13);
	REQUIRE(isSetEqual(etalon, result));
}

TEST_CASE("if function GeneratePrimeNumbersSet give parametr 0 then function return empty set")
{
	set<int> etalon {};
	set<int> result = GeneratePrimeNumbersSet(0);
	REQUIRE(isSetEqual(etalon, result));
}

TEST_CASE("if function GeneratePrimeNumbersSet give negative number then function return empty set")
{
	set<int> etalon{};
	set<int> result = GeneratePrimeNumbersSet(-1);
	REQUIRE(isSetEqual(etalon, result));
}

TEST_CASE("if function GeneratePrimeNumbersSet give 100000000 then function return set with size 5761455")
{
	set<int> result = GeneratePrimeNumbersSet(100000000);
	REQUIRE(result.size() == 5761455);
}

