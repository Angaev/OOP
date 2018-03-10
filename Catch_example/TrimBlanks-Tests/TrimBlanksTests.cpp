#include "stdafx.h"
#include "../TrimBlanks/trimblanks.h"

TEST_CASE("TrimBlanks tests")
{
	CHECK(TrimBlanks("") == "");
	CHECK(TrimBlanks("Hello") == "Hello");
	CHECK(TrimBlanks("  Hello") == "Hello");
	CHECK(TrimBlanks("Hello  ") == "Hello");
	CHECK(TrimBlanks("     ") == "");
	CHECK(TrimBlanks("   Hello  ") == "Hello");
	CHECK(TrimBlanks("A") == "A");


}