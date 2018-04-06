#include "stdafx.h"
#include "../Task1/ArithmeticMeanVector.h"
#include <vector>
#include <algorithm>

bool IsArrayEqual(const std::vector<double>& array1, const std::vector<double>& array2)
{
	return array1 == array2;
}

TEST_CASE("Arithmetic Mean tests")
{
	std::vector<double> testArray = { 1, 1, 1, 1, 1 };
	REQUIRE(FindArithmeticMeanPositiveElements(testArray) == 1);
	testArray = {0};
	REQUIRE(FindArithmeticMeanPositiveElements(testArray) == 0);

}

TEST_CASE("Sum arithmetic mean to array - tests")
{
	std::vector<double> testArray = { 1, 1, 1, 1, 1 };
	double ArithmeticMean = 2.5;
	std::vector<double> etalonArray = { 3.5, 3.5, 3.5, 3.5, 3.5 };
	SumNumberToArrayElements(testArray, ArithmeticMean);
	REQUIRE(IsArrayEqual(testArray, etalonArray) == true);
}

TEST_CASE("ProcessVector - tests")
{
	std::vector<double> testArray = { 1, 1, 1, 1, 1 };
	ProcessVector(testArray);
	std::vector<double> etalonArray = { 2, 2, 2, 2, 2 };
	REQUIRE(IsArrayEqual(testArray, etalonArray) == true);
}

TEST_CASE("ProcessVector - empty vector- tests")
{
	std::vector<double> testArray = {};
	ProcessVector(testArray);
	std::vector<double> etalonArray = {};
	REQUIRE(IsArrayEqual(testArray, etalonArray) == true);
}
