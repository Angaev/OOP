#define CATCH_CONFIG_MAIN  
#include "../../../Catch/catch.hpp"
#include "ArraySum.h"

using namespace std;

TEST_CASE("You can get sum vector<int>")
{
	vector<int> intVector{ -1, 0, 1, 2, 3 };
	int sum = ArraySum(intVector);
	CHECK(sum == 5);
}

// string

TEST_CASE("You can get sum vector<double>")
{
	vector<double> doubleVector{ -1.5, 0, 1.5, 2.3, 3.5 };
	auto sum = ArraySum(doubleVector);
	CHECK(sum == 5.8);
}

TEST_CASE("You can get sum vector<float>")
{
	vector<float> floatVector{ -1.5, 0, 1.5, 2.5, 3.5 };
	auto sum = ArraySum(floatVector);
	CHECK(sum == 6.0);
}

TEST_CASE("You can get sum vector<string>")
{
	vector<string> stringVector{ "Hello"s, ", "s, "World"s};
	auto sum = ArraySum(stringVector);
	CHECK(sum == "Hello, World"s);
}

TEST_CASE("Empty vector<int> have sum = 0")
{
	vector<int> intVector{};
	int sum = ArraySum(intVector);
	CHECK(sum == 0);
}

TEST_CASE("Empty vector<string> have sum equal empty string")
{
	vector<string> stringVector{ ""s };
	auto sum = ArraySum(stringVector);
	CHECK(sum == ""s);
}
