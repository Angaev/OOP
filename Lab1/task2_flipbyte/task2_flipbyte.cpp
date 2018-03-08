// task2_flipbyte.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int FlipByte(const int &number)
{
	const int bitCapacity = 8;

	int leftNumber = number;
	leftNumber = leftNumber >> (bitCapacity / 2);
	int rightNumber = number;
	rightNumber = rightNumber << (bitCapacity / 2);

	return (rightNumber | leftNumber);
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Not enough paramets. Example: task2_flipbyte.exe 6 \n";
		return 1;
	}
	int number;

	try
	{
		number = std::stoi(argv[1]);
	}
	catch (const std::exception& err)
	{
		std::cout << err.what() << "\n";
		return 1;
	}
	if ((number < 0) || (number > 255))
	{
		std::cout << "Need number from 0 to 255 \n";
		return 1;
	}

	std::cout << FlipByte(number) << "\n";
	return 0;
}

