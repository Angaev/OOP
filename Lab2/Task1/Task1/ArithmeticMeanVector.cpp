#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "ArithmeticMeanVector.h"



std::vector<double> ReadArray()
{
	std::vector<double> numbers(std::istream_iterator<double>(std::cin), (std::istream_iterator<double>()));
	return numbers;
}

void SortArray(std::vector<double>& data)
{
	std::sort(data.begin(), data.end());
}

void PrintArray(const std::vector<double>& printArray)
{
	copy(printArray.begin(), printArray.end(), std::ostream_iterator<double>(std::cout, " "));
	std::cout << "\n";
}

double FindArithmeticMeanPositiveElements(const std::vector<double>& searchArray)
{
	double arithmeticMean = 0;
	size_t count = 0;
	for (double item : searchArray)
	{
		if (item >= 0)
		{
			arithmeticMean += item;
			count++;
		}
	}

	return (arithmeticMean / count);
}

void SumNumberToArrayElements(std::vector<double>& arr, double number)
{
	std::transform(arr.begin(), arr.end(), arr.begin(), [=](double element) {return element += number; });
}

void ProcessVector(std::vector<double>& inArray)
{
	double ArithmeticMean = FindArithmeticMeanPositiveElements(inArray);
	SumNumberToArrayElements(inArray, ArithmeticMean);
}