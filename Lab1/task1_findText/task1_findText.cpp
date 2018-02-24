// task1_findText.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Not enough (or too many) input parameters. Example: task1_findText.exe input.txt hello \n";
		return 1;
	}

	std::string searchWord = argv[2];

	std::ifstream inputFile;
	inputFile.open(argv[1]);
	if (!inputFile.is_open())
	{
		std::cout << "File not found! Check exist of file\n";
		return 1;
	}

	std::string line;
	size_t lineNumber = 1;
	while (std::getline(inputFile, line))
	{
		int i = 0;
		while (i != std::string::npos)
		{
			size_t position = line.find(searchWord);
			if (position != std::string::npos)
			{
				std::cout << lineNumber << "\n";
			}
			lineNumber++;
		}
	}


    return 0;
}

