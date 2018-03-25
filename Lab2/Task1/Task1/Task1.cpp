// Task1.cpp: определяет точку входа для консольного приложения.
//

/*

*/
#include "stdafx.h"
using namespace std;

int main()
{
	cout << "Enter your array: \n";
	vector<double> numbers;
	ReadArray(numbers);
	double arithmeticMean = FindArithmeticMeanPositiveElements(numbers);
	SumNumberToArrayElements(numbers, arithmeticMean);
	SortArray(numbers);
	PrintArray(numbers);
    return 0;
}

