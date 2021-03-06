// task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int SumDigits(int i)
{
	int sum = 0;
	// цикл продолжается до тех пор, пока число не станет равным 0
	while (i != 0)
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int main(int argc, char* argv[])
{
	int upperBound = 1000;
	if (argc > 1)
	{
		try
		{
			upperBound = std::stoi(argv[1]);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << "\n";
			return 1;
		}
		if (upperBound <= 0)
		{
			std::cout << "Error! upper bound must be >= 1 \n";
			return 1;
		}
	}

	for (int x = 1; x <= upperBound; ++x)
	{
		int sum = SumDigits(x);
		if ((x % sum) == 0)
		{
			std::cout << x << " ";
		}
	}
	std::cout << "\n";
	return 0;
}

