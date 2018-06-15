#include "stdafx.h"
#include "../../../../Catch/catch.hpp"
#include "../CMyArray/CMyArray.h"
#include "../CMyArray/CMyIterator.h"

#include <algorithm>

using namespace std;

struct ArrayItem
{
	ArrayItem(int value = 0) : value(value)
	{}
	int value;
};

TEST_CASE("You can construct empty array (size = 0)")
{
	CMyArray<string> arr0;
	CHECK(arr0.GetSize() == 0);

	CMyArray<int> arr1;
	CHECK(arr1.GetSize() == 0);

	CMyArray<double> arr2;
	CHECK(arr2.GetSize() == 0);
}

TEST_CASE("You can put data in array")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	CHECK(arr0.GetSize() == 3);

	CMyArray<int> arr1;
	arr1.PushBack(1);
	arr1.PushBack(2);
	arr1.PushBack(3);
	arr1.PushBack(3);
	CHECK(arr1.GetSize() == 4);

	CMyArray<double> arr2;
	arr2.PushBack(1.5);
	CHECK(arr2.GetSize() == 1);

}

TEST_CASE("You can clear data in array")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	CHECK(arr0.GetSize() == 3);
	arr0.Clear();
	CHECK(arr0.GetSize() == 0);

	CMyArray<int> arr1;
	arr1.PushBack(1);
	arr1.PushBack(2);
	arr1.PushBack(3);
	arr1.PushBack(3);
	CHECK(arr1.GetSize() == 4);
	arr1.Clear();
	CHECK(arr1.GetSize() == 0);

	CMyArray<double> arr2;
	arr2.PushBack(1.5);
	CHECK(arr2.GetSize() == 1);
	arr2.Clear();
	CHECK(arr2.GetSize() == 0);
}

TEST_CASE("You can resize array")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	CHECK(arr0.GetSize() == 3);
	arr0.ReSize(2);
	CHECK(arr0.GetSize() == 2);

	CMyArray<int> arr1;
	arr1.PushBack(1);
	arr1.PushBack(2);
	arr1.PushBack(3);
	arr1.PushBack(3);
	CHECK(arr1.GetSize() == 4);
	arr1.ReSize(6);
	CHECK(arr1.GetSize() == 6);

	CMyArray<double> arr2;
	arr2.PushBack(1.5);
	CHECK(arr2.GetSize() == 1);
	arr2.ReSize(1);
	CHECK(arr2.GetSize() == 1);

}

TEST_CASE("You can use iterator")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	CHECK(arr0.GetSize() == 3);

	string sum{};
	for_each(arr0.begin(), arr0.end(), [sum](auto & item) {sum += item});
	CHECK(sum == "hello World"s);
}