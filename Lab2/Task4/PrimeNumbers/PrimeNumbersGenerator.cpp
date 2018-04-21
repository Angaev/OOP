#include "stdafx.h"
#include "PrimeNumbersGenerator.h"

using namespace std;

vector<bool>GetSieve(int upperBound)
{
	if (upperBound < 0)
	{
		upperBound = 0;
	}
	vector<bool> sieve(upperBound + 1, true);
	sieve[0] = false;
	if (upperBound > 0)
	{
		sieve[1] = false;
	}
	for (int i = 2; i * i <= upperBound; i++)
	{
		if (sieve[i])
		{
			for (int j = i * i; j <= upperBound;  j += i)
			{
				sieve[j] = false;
			}
		}
	}
	return sieve;
}

set<int>GeneratePrimeNumbersSet(int upperBound)
{
	set<int> primeNumbersSet;
	vector<bool> sieve = GetSieve(upperBound);
	for (int i = 2; i <= upperBound; i++)
	{
		if (sieve[i])
		{
			primeNumbersSet.insert(i);
		}
	}
	return primeNumbersSet;
}