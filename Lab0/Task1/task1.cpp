// Lab0.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	int i;
	for (i = 100; i >= 1; --i)
	{
		
		if (i % 2 == 0)
		{
			printf("%d", i);
			if (i != 2)
			{
				printf(", ");
			}
		}
	}
	printf("\n");
	return 0;
}