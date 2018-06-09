#pragma once
#include "stdafx.h"
#include <vector>
#include <algorithm>

template <typename T>
T ArraySum(std::vector<T> const & arr)
{
	T sum{};
	for (auto i = 0; i < arr.size(); ++i)
	{
		sum += arr[i];
	}

	return sum;
}