// Catch_example.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "../../Catch/catch.hpp"

unsigned int Factorial(unsigned int number) {
	return number <= 1 ? 1: Factorial(number - 1)*number;
}

//фибоначи по ее порядковому номеру
unsigned int Fibonacci(unsigned int index)
{
	return (index <= 1) ? 1 : Fibonacci(index - 1) + Fibonacci(index - 2);
}

int CalcArithmeticSeries(int a0, int commonDifference, int size)
{
	int sumArithmeticSeries = ((2 * a0 + commonDifference * (size - 1)) / 2) * size;
	return sumArithmeticSeries;
}
//граничные: 0, 
TEST_CASE("Arithmetic series are computed", "[ArithmeticSeries]")
{
	REQUIRE(CalcArithmeticSeries(1, 2, 0) == 0);
	REQUIRE(CalcArithmeticSeries(1, 2, 1) == 1);
	REQUIRE(CalcArithmeticSeries(58, 23, 23) == 7153);
	REQUIRE(CalcArithmeticSeries(258, 78, 187) == 1404744);
}

TEST_CASE("Fibonacci numbers are computed", "[fibonacci]")
{
	REQUIRE(Fibonacci(0) == 1);
	REQUIRE(Fibonacci(1) == 1);
	REQUIRE(Fibonacci(2) == 2);
	REQUIRE(Fibonacci(10) == 89);

}

TEST_CASE("Factorials are computed", "[factorial]") 
{
	REQUIRE(Factorial(0) == 1);
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
}
