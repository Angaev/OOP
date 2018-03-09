#include "stdafx.h"

void PrintFibonacciNumbers(int upperBound)
{
	const int numbersInLine = 5;
	int prevNumber = 0;
	int currentNumber = 1;
	int orderNumberInCurrentLine = 1;
	while (prevNumber < upperBound)
	{
		std::cout << prevNumber;
		if (orderNumberInCurrentLine < numbersInLine) 
		{
			if (currentNumber < upperBound)
			{
				std::cout << ", ";
				orderNumberInCurrentLine++;
			}
		} 
		else
		{
			std::cout << "\n";
			orderNumberInCurrentLine = 1;
		}

		currentNumber += prevNumber;
		prevNumber = currentNumber - prevNumber;
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

	PrintFibonacciNumbers(upperBound);
	std::cout << "\n" << std::endl;
    return 0;
}

