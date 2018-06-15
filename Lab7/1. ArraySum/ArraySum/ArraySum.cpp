#include "stdafx.h"
#include "ArraySum.h"
#include <algorithm>


using namespace std;

template <typename T>
T ArraySum(std::vector<T> const & arr)
{
	T sum = 0;
	for (auto i = 0; i < arr.size(); ++i)
	{
		sum += arr[i];
	}
	return sum;
}