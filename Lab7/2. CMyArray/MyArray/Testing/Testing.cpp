#include "stdafx.h"
#include "../../../../Catch/catch.hpp"
#include "../CMyArray/CMyArray.h"

#include <algorithm>

using namespace std;

TEST_CASE("You can construct empty array (size = 0)")
{
	CMyArray<string> arr0;
	CHECK(arr0.GetSize() == 0);

	CMyArray<int> arr1;
	CHECK(arr1.GetSize() == 0);

	CMyArray<double> arr2;
	CHECK(arr2.GetSize() == 0);
}

TEST_CASE("You can put data in end of the array")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	CHECK(arr0.GetSize() == 3);
	CHECK(arr0.GetSize() != 1);

	CMyArray<int> arr1;
	arr1.PushBack(1);
	arr1.PushBack(2);
	arr1.PushBack(3);
	arr1.PushBack(3);
	CHECK(arr1.GetSize() == 4);
	CHECK(arr1.GetSize() != 5);

	CMyArray<double> arr2;
	arr2.PushBack(1.5);
	CHECK(arr2.GetSize() == 1);
	CHECK(arr2.GetSize() != 0);
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

TEST_CASE("You can get access using [] operator")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	CHECK(arr0[0] == "hello"s);
	CHECK(arr0[1] == " "s);
	CHECK(arr0[2] == "World"s);
	CHECK_THROWS(arr0[3]);


	CMyArray<int> arr1;
	arr1.PushBack(1);
	arr1.PushBack(2);
	arr1.PushBack(3);
	arr1.PushBack(3);
	CHECK(arr1[0] == 1);
	CHECK(arr1[1] == 2);
	CHECK(arr1[2] == 3);
	CHECK(arr1[3] == 3);
	CHECK_THROWS(arr1[4]);

	CMyArray<double> arr2;
	arr2.PushBack(1.5);
	CHECK(arr2[0] == 1.5);
	CHECK_THROWS(arr2[1]);

}

/*testing begin, end, rbegin, rend*/
TEST_CASE("You can get begin interator")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	CHECK(*(arr0.begin()) == "hello"s);

	CMyArray<int> arr1;
	arr1.PushBack(1);
	CHECK(*(arr1.begin()) == 1);

	CMyArray<double> arr2;
	arr2.PushBack(1.5);
	CHECK(*(arr2.begin()) == 1.5);
}

TEST_CASE("You can get end interator")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	CHECK(*(--(arr0.end())) == "World"s);

	CMyArray<int> arr1;
	arr1.PushBack(1);
	arr1.PushBack(2);
	CHECK(*(--(arr1.end())) == 2);

	CMyArray<double> arr2;
	arr2.PushBack(1.5);
	arr2.PushBack(2.5);
	CHECK(*(--(arr2.end())) == 2.5);
}

TEST_CASE("You can get rbegin interator")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	CHECK(*(arr0.rbegin()) == "World"s);

	CMyArray<int> arr1;
	arr1.PushBack(1);
	arr1.PushBack(2);
	CHECK(*(arr1.rbegin()) == 2);

	CMyArray<double> arr2;
	arr2.PushBack(1.5);
	arr2.PushBack(2.5);
	CHECK(*(arr2.rbegin()) == 2.5);
}

TEST_CASE("You can get rend interator")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	CHECK(*(--(arr0.rend())) == "hello"s);

	CMyArray<int> arr1;
	arr1.PushBack(1);
	CHECK(*(--(arr1.rend())) == 1);

	CMyArray<double> arr2;
	arr2.PushBack(1.5);
	CHECK(*(--(arr2.rend())) == 1.5);
}

/*копирование опер и констр*/
TEST_CASE("You can constuct copy arr")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);

	auto copy(arr0);
	CHECK(copy.GetSize() == arr0.GetSize());
	for (size_t i = 0; i < arr0.GetSize(); ++i) 
	{
		CHECK(copy[i] == arr0[i]);
	}

	CMyArray<int> arr1;
	arr1.PushBack(1);

	auto copy1(arr1);
	CHECK(copy1.GetSize() == arr1.GetSize());
	for (size_t i = 0; i < arr1.GetSize(); ++i)
	{
		CHECK(copy1[i] == arr1[i]);
	}
}

TEST_CASE("You can copy arr")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);

	CMyArray<string> arrNew = arr0;
	CHECK(arrNew.GetSize() == arr0.GetSize());
	for (size_t i = 0; i < arr0.GetSize(); ++i)
	{
		CHECK(arrNew[i] == arr0[i]);
	}
}

/*перемещение опер и констр*/
TEST_CASE("You can constuct move arr")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);

	auto copy(arr0);
	CMyArray<string> arrNew(move(arr0));


	CHECK(arrNew.GetSize() == copy.GetSize());
	for (size_t i = 0; i < copy.GetSize(); ++i)
	{
		CHECK(arrNew[i] == copy[i]);
	}
}

TEST_CASE("You can move arr")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	auto copy(arr0);

	CMyArray<string> arrNew = move(arr0);
	CHECK(arrNew.GetSize() == copy.GetSize());
	for (size_t i = 0; i < copy.GetSize(); ++i)
	{
		CHECK(arrNew[i] == copy[i]);
	}
}

/*
	для итератора нужно простировать только операторы
*/

TEST_CASE("You can use -> in iterator")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	
	CHECK((arr0.begin())->size() == 5);
}

TEST_CASE("You can use prefix increment in iterator")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);

	CHECK(*(++(arr0.begin())) == " "s);
}

TEST_CASE("You can use postfix increment in iterator")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	auto it = arr0.begin();
	it++;
	CHECK(*(it++) == " "s);
	CHECK(*it == "World"s);
}

TEST_CASE("You can use prefix decrement in iterator")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);

	CHECK(*(--(arr0.end())) == "World"s);
}

TEST_CASE("You can use postfix decrement in iterator")
{
	CMyArray<string> arr0;
	arr0.PushBack("hello"s);
	arr0.PushBack(" "s);
	arr0.PushBack("World"s);
	auto it = arr0.end();
	it--;
	CHECK(*(it--) == "World"s);
	CHECK(*it == " "s);
}