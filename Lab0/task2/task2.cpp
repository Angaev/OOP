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
	for (int i = 0; i <= 9; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			for (int k = 1; k <= 9; ++k)
			{
				int x = i * 100 + j * 10 + k;
				int sum = SumDigits(x);
				if ((x % sum) == 0)
				{
					std::cout << x << " ";
				}
			}
		}
	}
	getchar();
	return 0;
}

