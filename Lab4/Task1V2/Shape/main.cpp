// Shape.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Point.h"

using namespace std;

int main()
{
	CPoint point {0, 0.5};
	
	cout << "Coordinates: " << point.GetCoordinates().first << "  " << point.GetCoordinates().second << "\n";

    return 0;
}

