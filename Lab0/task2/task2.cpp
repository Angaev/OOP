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


int main()
{
    return 0;
}

