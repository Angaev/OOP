#include "stdafx.h"
#include "ArraySum.h"
#include "../../../../Catch/catch.hpp"

using namespace std;

TEST_CASE("You can get sum vector<int>")
{
	vector<int> intVector{-1, 0, 1, 2, 3};
	int sum = ArraySum(vector<int>{ -1, 0, 1, 2, 3 });
	CHECK(sum == 5);
}

