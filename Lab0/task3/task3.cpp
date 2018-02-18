

#include "stdafx.h"

void printFibonacciNumber(const int & upperBound)
{
	const int numbersInLine = 5;
	int prevPrevNumber = 0;
	int prevNumber = 1;
	int positionOfPrint = 1;
	while (prevNumber < (upperBound - prevPrevNumber))
	{

		int fibonacciNumber = prevNumber + prevPrevNumber;
		std::cout << fibonacciNumber;

		if (fibonacciNumber + prevNumber < upperBound)
		{
			std::cout << ", ";
		}

		prevPrevNumber = prevNumber;
		prevNumber = fibonacciNumber;

		positionOfPrint++;
		if (positionOfPrint > numbersInLine)
		{
			std::cout << "\n";
			positionOfPrint = 1;
		}

	}

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

	printFibonacciNumber(upperBound);
	std::cout << "\n" << std::endl;
    return 0;
}

