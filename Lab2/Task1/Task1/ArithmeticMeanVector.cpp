#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "ArithmeticMeanVector.h"

bool PrintHello()
{
	std::cout << "Hello\n";
	return true;
}

void ReadArray(std::vector<double>& inputArray)
{
	double input;
	while (std::cin >> input)
	{
		inputArray.push_back(input);
	}
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
	int count = 0;
	for (size_t i = 0; i < searchArray.size(); i++)
	{
		if (searchArray[i] >= 0)
		{
			arithmeticMean += searchArray[i];
			count++;
		}
	}

	return (arithmeticMean / count);
}

void SumNumberToArrayElements(std::vector<double>& arr, double number)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		arr[i] += number;
	}
}