// task2_flipbyte.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

uint8_t FlipByte(uint8_t number)
{
	uint8_t outputByte;
	outputByte = ((number & 0b11110000) >> 4) | ((number & 0b00001111) << 4);
	outputByte = ((outputByte & 0b11001100) >> 2) | ((outputByte & 0b00110011) << 2);
	outputByte = ((outputByte & 0b10101010) >> 1) | ((outputByte & 0b01010101) << 1);

	return outputByte;
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

	std::cout << static_cast <int>(FlipByte(static_cast<uint8_t>(number))) << "\n";
	return 0;
}

