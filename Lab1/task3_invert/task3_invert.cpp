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

void PrintMatrix(const matrix3x3& matrix)
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

double GetDeterminantMatrix3x3(const matrix3x3& matrix)
{

	double line1 = matrix[1][1] * matrix[2][2] * matrix[3][3]; 
	double line2 = matrix[1][2] * matrix[2][3] * matrix[3][1]; 
	double line3 = matrix[1][3] * matrix[2][1] * matrix[3][2]; 
	double line4 = matrix[1][3] * matrix[2][2] * matrix[3][1]; 
	double line5 = matrix[1][1] * matrix[2][3] * matrix[3][2]; 
	double line6 = matrix[1][2] * matrix[2][1] * matrix[3][3]; 

	return line1 + line2 + line3 - line4 - line5 - line6; 
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
	
	cout << GetDeterminantMatrix3x3(matrix) << "\n";
    return 0;
}

