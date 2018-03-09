// task3_invert.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;
constexpr int MATRIX_SIZE = 3;

using matrix3x3 = float[MATRIX_SIZE][MATRIX_SIZE];

bool CheckExistFile(const string & fileName)
{
	ifstream matrixFile;
	matrixFile.open(fileName);
	if (!matrixFile.is_open())
	{
		cout << "Can't open file! Check exist file!\n";
		return false;
	}
	return true;
}

void ResetMatrix(matrix3x3& matrix)
{
	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < MATRIX_SIZE; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}

bool LoadMatrixFromFile(matrix3x3& matrix, const string & fileName)
{
	ifstream matrixFile;
	matrixFile.open(fileName);
	string row;
	if (!matrixFile.is_open())
	{
		return false;
	}
	for (int i=0; i < MATRIX_SIZE; i++)
	{
		if (!getline(matrixFile, row))
		{
			return false;
		}

	}

	return true;
}
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Wrong count of arguments! Use invert.exe <matrix file1>\n";
		return 1;
	}

	if (!CheckExistFile(argv[1]))
	{
		return 1;
	}

	matrix3x3 matrix;
	ResetMatrix(matrix);

	
    return 0;
}

