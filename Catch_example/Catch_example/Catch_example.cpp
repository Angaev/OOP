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
	return 1;
}

TEST_CASE("Fibonacci numbers are computed", "[fibonacci]")
{
	REQUIRE(Fibonacci(0) == 1);
}

TEST_CASE("Factorials are computed", "[factorial]") 
{
	REQUIRE(Factorial(0) == 1);
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
}
