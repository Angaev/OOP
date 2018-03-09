// task1_findText.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

bool CheckCountArgument(int argc)
{
	if (argc != 3)
	{
		std::cout << "Not enough (or too many) input parameters. Example: task1_findText.exe input.txt hello \n";
		return false;
	}
	return true;
}

bool CheckExistFile(const std::string & fileName)
{
	std::ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		std::cout << "Can't open file! Check the existence of the file!\n";
		return false;
	}
	return true;
}

bool FindText(const std::string & fileName, std::string searchWord)
{
	bool wasFound = false;
	std::ifstream file;
	file.open(fileName);
	std::string line;
	size_t lineNumber = 1;
	while (std::getline(file, line))
	{
		size_t position = line.find(searchWord);

		if (position != std::string::npos)
		{
			std::cout << lineNumber <<"\n";
			wasFound = true;
		}
		lineNumber++;
	}

	return wasFound;
}

int main(int argc, char* argv[])
{
	if (!CheckCountArgument(argc))
	{
		return 1;
	}

	std::string fileName = argv[1];
	std::string searchWord = argv[2];

	if (!CheckExistFile(fileName))
	{
		return 1;
	}

	if (!FindText(fileName, searchWord))
	{
		std::cout << "Text not found\n";
	}

    return 0;
}

