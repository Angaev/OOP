// task3_invert.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;
constexpr int matrixSize = 3;

using matrix3x3 = double[matrixSize][matrixSize];
using matrix2x2 = double[matrixSize - 1][matrixSize - 1];

void ResetMatrix(matrix3x3& matrix)
{
	for (int i = 0; i < matrixSize; ++i)
	{
		for (int j = 0; j < matrixSize; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}

bool LoadMatrixFromFile(matrix3x3& matrix, const string& fileName)
{
	ifstream matrixFile;
	matrixFile.open(fileName);
	string line;
	if (!matrixFile.is_open())
	{
		return false;
	}

	getline(matrixFile, line);
	matrixSize = stoi(line);

	for (int i = 0; i < matrixSize; i++)
	{
		if (!getline(matrixFile, line))
		{
			return false;
		}
		istringstream row (line);
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
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			cout << fixed << setprecision(3) << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

double GetDeterminantMatrix3x3(const matrix3x3& matrix)
{
	double line1 = matrix[0][0] * matrix[1][1] * matrix[2][2]; 
	double line2 = matrix[0][1] * matrix[1][2] * matrix[2][0];
	double line3 = matrix[0][2] * matrix[1][0] * matrix[2][1];
	double line4 = matrix[0][2] * matrix[1][1] * matrix[2][0];
	double line5 = matrix[0][0] * matrix[1][2] * matrix[2][1];
	double line6 = matrix[0][1] * matrix[1][0] * matrix[2][2];

	return line1 + line2 + line3 - line4 - line5 - line6; 
}

double GetMinorMatrix3x3(const matrix3x3& matrix, int line, int column)
{
	matrix2x2 matrix2x2;
	int iDst = 0, jDst = 0;
	for (int i = 0; i < matrixSize; i++)
	{
		jDst = 0;
		if (i != line)
		{
			for (int j = 0; j < 3; j++)
				if (j != column)
					matrix2x2[iDst][jDst++] = matrix[i][j];
			iDst++;
		}
	}
	return matrix2x2[0][0] * matrix2x2[1][1] - matrix2x2[0][1] * matrix2x2[1][0];
}

void TransposeMatrix3x3(const matrix3x3& sourseMatrix, matrix3x3& transponseMatrix)
{
	for (int i = 0; i < matrixSize; ++i)
	{
		for (int j = 0; j < matrixSize; ++j)
		{
			transponseMatrix[i][j] = sourseMatrix[j][i];
		}
	}
}

void GetAdjugateMatrix3x3(const matrix3x3& sourseMatrix, matrix3x3& adjugateMatrix) //матрица составленная из алгеброических дополнений
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			adjugateMatrix[i][j] = GetMinorMatrix3x3(sourseMatrix, i, j);
		}
	}
}

void MultiplyMatrixByNumber(matrix3x3& matrix, double number)
{
	for (int i = 0; i < matrixSize; i++)
		for (int j = 0; j < matrixSize; j++)
			matrix[i][j] *= number;
}

void GetCofactorMatrix3x3(const matrix3x3& sourseMatrix, matrix3x3& cofactorMatrix)
{	
	int cofactor = 1;
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			cofactorMatrix[i][j] = sourseMatrix[i][j] * cofactor;
			cofactor *= -1;
		}
	}

}

void CopyMatrix3x3(const matrix3x3& sourseMatrix, matrix3x3& copyMatrix)
{
	for (int i = 0; i < matrixSize; i++)
		for (int j = 0; j < matrixSize; j++)
		{
			copyMatrix[i][j] = sourseMatrix[i][j];
		}
}

bool InvertMatrix3x3(matrix3x3& matrix)
{
	if (fabs(GetDeterminantMatrix3x3(matrix)) < 0.1E-10)
		return false;
	
	matrix3x3 transposeMatrix;
	matrix3x3 adjugateMatrix;
	matrix3x3 cofactorMatrix;

	TransposeMatrix3x3(matrix, transposeMatrix);

	GetAdjugateMatrix3x3(transposeMatrix, adjugateMatrix);

	GetCofactorMatrix3x3(adjugateMatrix, cofactorMatrix);

	MultiplyMatrixByNumber(cofactorMatrix, (1 / GetDeterminantMatrix3x3(matrix)));

	CopyMatrix3x3(cofactorMatrix, matrix);
	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Wrong count of arguments! Use invert.exe <matrix file1>\n";
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
	if (!InvertMatrix3x3(matrix))
	{
		cout << "Can't invert matrix!";
		return 1;
	}

	PrintMatrix(matrix);

    return 0;
}

