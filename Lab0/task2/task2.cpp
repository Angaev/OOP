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
	int highBorder = 1000;
	if (argc > 1)
	{
		highBorder = std::stoi(argv[1]);
		if (highBorder <= 0)
		{
			std::cout << "Error! High border must be >= 1 \n";
			return 1;
		}
	}

	for (int x = 1; x <= highBorder; ++x)
	{
		int sum = SumDigits(x);
		if ((x % sum) == 0)
		{
			std::cout << x << " ";
		}
	}

	getchar();
	return 0;
}

