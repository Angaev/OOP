// task3.cpp: ��।���� ��� �室� ��� ���᮫쭮�� �ਫ������.
//

#include "stdafx.h"

void printFibonacciNumber(const int & upperBound)
{
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
		if (positionOfPrint > 5)
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
			std::cout << "�� 㪠���� ������ �࠭��� ���: " << upperBound <<"\n";
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << "\n";
			return 1;
		}
		if (upperBound <= 0)
		{
			std::cout << "�訡��! ������ �࠭�� ������ ���� >= 1 \n";
			return 1;
		}
	}
	else
	{
		std::cout << "�� 㪠���� �室�� ��ࠬ����. ���ਬ�� 'task3.exe 12' \n";
		return 1;
	}

	printFibonacciNumber(upperBound);
	/*
	How it do work:
	1. �஢���� ���-�� ��ࠬ��஢ 
	2. ����� �� ��ࠬ��஢ �᫮ - ������ �࠭��� (�᫨ ����� ��������)
	3. ��� �� ��९�������? 
	4. �뢮���� �᫠ 䨡���� 5 ��� � ����� �१ 横�

	*/
	std::cout << "\n" << std::endl;
    return 0;
}

