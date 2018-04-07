#include "stdafx.h"


TEST_CASE("FindAndReplace function tests")
{
	REQUIRE(FindAndReplace("", "", "") == "");

	std::string subject = "Hello World";
	std::string search = "Hello";
	std::string replace = "Goodbye";
	std::string result = "Goodbye World";
	REQUIRE(FindAndReplace(subject, search, replace) == result);

	subject = "HelloWorld";
	result = "GoodbyeWorld";
	REQUIRE(FindAndReplace(subject, search, replace) == result);

	subject = "Hello World, Hello Matrix, Hello everyone";
	result = "Goodbye World, Goodbye Matrix, Goodbye everyone";
	REQUIRE(FindAndReplace(subject, search, replace) == result);
}