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
	string line;
	if (!matrixFile.is_open())
	{
		return false;
	}
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		if (!getline(matrixFile, line))
		{
			return false;
		}
		istringstream row;
		row.str(line);
		for (int j = 0; j < 3; j++)
		{
			row >> matrix[i][j];
			if (row.fail())
				return false;
		}
	}

	return true;
}

void PrintMatrix(matrix3x3 matrix)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
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
	string fileName = argv[1];


	matrix3x3 matrix;
	ResetMatrix(matrix);
	if (!LoadMatrixFromFile(matrix, fileName))
	{
		cout << "Can't read matrix from file. \n";
		return 1;
	}
	PrintMatrix(matrix);
    return 0;
}

