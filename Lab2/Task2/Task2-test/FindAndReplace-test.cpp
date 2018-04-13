#include "stdafx.h"

TEST_CASE("Function FindAndReplace must find and replace (must work)")
{
	std::string subject = "Hello World";
	std::string search = "Hello";
	std::string replace = "Goodbye";
	std::string result = "Goodbye World";
	REQUIRE(FindAndReplace(subject, search, replace) == result);
}

TEST_CASE("If search in string then function must replace")
{
	std::string subject = "HelloWorld";
	std::string result = "GoodbyeWorld";
	std::string search = "Hello";
	std::string replace = "Goodbye";
	REQUIRE(FindAndReplace(subject, search, replace) == result);
}

TEST_CASE("If search occurs several times, it will replace all")
{
	std::string subject = "Hello World, Hello Matrix, Hello everyone";
	std::string result = "Goodbye World, Goodbye Matrix, Goodbye everyone";
	std::string search = "Hello";
	std::string replace = "Goodbye";
	REQUIRE(FindAndReplace(subject, search, replace) == result);
}

TEST_CASE("If search empty then return subject")
{
	std::string subject = "Hello World";
	std::string search = "";
	std::string replace = "Goodbye";
	std::string result = "Hello World";
	REQUIRE(FindAndReplace(subject, search, replace) == result);
}

TEST_CASE("If replace empty then return subject without search")
{
	std::string subject = "Hello World";
	std::string search = "Hello";
	std::string replace = "";
	std::string result = " World";
	REQUIRE(FindAndReplace(subject, search, replace) == result);
}

TEST_CASE("if subject empty then return empty string")
{
	std::string subject = "";
	std::string search = "Hello";
	std::string replace = "abba";
	std::string result = "";
	REQUIRE(FindAndReplace(subject, search, replace) == result);
}


