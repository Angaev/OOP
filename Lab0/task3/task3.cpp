

#include "stdafx.h"

void printFibonacciNumbers(const int & upperBound)
{
	const int numbersInLine = 5;
	int prevNumver = 0;
	int fibonacciNumber = 1;
	int positionOfWriter = 1;
	while (prevNumver < upperBound)
	{
		std::cout << prevNumver;
		if (positionOfWriter < numbersInLine) 
		{
			if (fibonacciNumber < upperBound)
			{
				std::cout << ", ";
				positionOfWriter++;
			}
		} 
		else
		{
			std::cout << "\n";
			positionOfWriter = 1;
		}

		fibonacciNumber += prevNumver;
		prevNumver = fibonacciNumber - prevNumver;
	}

}

bool PrintFibonacci(const size_t max, const int numbersCountInLine = 5)
{
	size_t lastNumber = 0;
	size_t currentNumber = 1;
	size_t numbersCount = 1;

	while (lastNumber < max)
	{
		std::cout << lastNumber;

		if (numbersCount % numbersCountInLine == 0)
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << " ";
		}

		if ((currentNumber + lastNumber) > std::numeric_limits<int>::max())
		{
			std::cout << "Next Number overflow. Program has to stop.";
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

	printFibonacciNumbers(upperBound);
	//PrintFibonacci(upperBound);
	std::cout << "\n" << std::endl;
    return 0;
}

