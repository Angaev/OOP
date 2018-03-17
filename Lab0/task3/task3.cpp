#include "stdafx.h"

bool PrintFibonacciNumbers(int upperBound)
{
	const int numbersInLine = 5;
	size_t lastNumber = 0;
	size_t currentNumber = 1;
	size_t numbersCount = 1;

	while (lastNumber <= upperBound)
	{
		std::cout << lastNumber;

		if (numbersCount % numbersInLine == 0)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << " ";
		}

		if ((currentNumber + lastNumber) > std::numeric_limits<int>::max())
		{
			return false;
		}
		currentNumber += lastNumber;
		lastNumber = currentNumber - lastNumber;

		++numbersCount;
	}

	return true;
}

int main(int argc, char* argv[])
{
	int upperBound = 0;
	if (argc > 1)
	{
		try
		{
			upperBound = std::stoi(argv[1]);
			std::cout << "Entered number: " << upperBound <<"\n";
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << "\n";
			return 1;
		}
		if (upperBound <= 0)
		{
			std::cout << "Error! Upper bound must be >= 1 \n";
			return 1;
		}
	}
	else
	{
		std::cout << "Not found parameters! Example: 'task3.exe 12' \n";
		return 1;
	}

	if (!PrintFibonacciNumbers(upperBound))
	{
		return 1;
	}
	std::cout << "\n" << std::endl;
    return 0;
}

