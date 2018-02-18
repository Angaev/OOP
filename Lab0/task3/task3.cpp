

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

