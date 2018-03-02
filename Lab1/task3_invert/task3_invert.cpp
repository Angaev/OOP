// task3_invert.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Wrong count of arguments! Use invert.exe <matrix file1>\n";
		return 1;
	}

	ifstream matrixFile;
	matrixFile.open(argv[1]);
	if (!matrixFile.is_open())
	{
		cout << "Can't open file! Check exist file!\n";
		return 1;
	}

    return 0;
}

