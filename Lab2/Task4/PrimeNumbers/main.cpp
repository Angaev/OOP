// PrimeNumbers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;
using namespace boost;

constexpr int MAX_UPPER_BOUND = 100000000;

bool CheckArgumentCount(int argc)
{
	if (argc != 2)
	{
		return false;
	}
	return true;
}

void PrintIntSet(set<int> const& set)
{
	for (auto i : set)
		cout << i << " ";
}

int main(int argc, char * argv[])
{
	if (!CheckArgumentCount(argc))
	{
		cout << "Wrong arguments count! Example: PrimeNumbers.exe 100 \n";
		return 1;
	}
	int upperBound;
	try
	{
		upperBound = stoi(argv[1]);
	}
	catch (exception& e)
	{
		cout << e.what() << "\n";
		return 1;
	}

	if (upperBound > MAX_UPPER_BOUND)
	{
		cout << "Upper bound must be <= 100000000\n";
		return 1;
	}

	timer time;
	time.restart();
	set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);
	double usedTime = time.elapsed();
	if (upperBound <= 1000)
	{
		PrintIntSet(primeNumbers);
		cout << "\n";
	}
	cout << "Used time: " << usedTime << "\n";
    return 0;
}

