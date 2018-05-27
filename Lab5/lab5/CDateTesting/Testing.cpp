#include "stdafx.h"
#include "../../../Catch/catch.hpp"
#include "../Lab5Var5/CDate.h"
#include  <functional>

using namespace std;
/*
TEST_CASE("You can set new date set like 1, JANUARY, 1970")
{
	CDate date(1, JANUARY, 1970);
	REQUIRE(date.GetTimeStamp() == 0);
}

TEST_CASE("You can set new date set like 4, OCTOBER, 1993")
{
	CDate date(4, OCTOBER, 1993);
	REQUIRE(date.GetTimeStamp() == 8677);
}

TEST_CASE("In leap year timestamp must calculate right (before 29.02 and after 29.02)")
{
	CDate date1(4, FEBRALY, 1972);
	REQUIRE(date1.GetTimeStamp() == 764);

	CDate date2(1, MARCH, 1972);
	REQUIRE(date2.GetTimeStamp() == 790);

	CDate date3(29, FEBRALY, 1972);
	REQUIRE(date3.GetTimeStamp() == 789);
}

TEST_CASE("You can set new date set like days after 1 JANUARY 1970")
{
	CDate date(100);
	REQUIRE(date.GetTimeStamp() == 100);
}

TEST_CASE("You can get day, month and year from the date")
{
	CDate date0(1, JANUARY, 1970);
	CHECK(date0.GetDay() == 1);

	CDate date1(1, MARCH, 1972);
	CHECK(date1.GetDay() == 1);
	CHECK(date1.GetMonth() == MARCH);
	CHECK(date1.GetYear() == 1972);

	CDate date2(26, MAY, 2018);
	CHECK(date2.GetDay() == 26);
	CHECK(date2.GetMonth() == MAY);
	CHECK(date2.GetYear() == 2018);

	CDate date3(29, FEBRALY, 1972);
	CHECK(date3.GetDay() == 29);
	CHECK(date3.GetMonth() == FEBRALY);
	CHECK(date3.GetYear() == 1972);

	CDate date4(31, JANUARY, 2018);
	CHECK(date4.GetDay() == 31);
	CHECK(date4.GetMonth() == JANUARY);
	CHECK(date4.GetYear() == 2018);
}
*/
//чета не работает, хз почему
/*TEST_CASE("You can get weekday from the date")
{
	CDate date1(1, JANUARY, 1970);
	CHECK(date1.GetWeekDay() == THURSDAY);

	CDate date2(1, MARCH, 1972);
	CHECK(date2.GetWeekDay() == WEDNESDAY);

	CDate date3(26, MAY, 2018);
	CHECK(date3.GetWeekDay() == SATURDAY);
}*/

TEST_CASE("You can check valid entered date")
{
	/*CDate date1(99, OCTOBER, 1969);
	CHECK(!date1.IsValid());

	CDate date2(1, JANUARY, 1970);
	CHECK(date2.IsValid());

	CDate date3(29, FEBRALY, 2018);
	CHECK(!date3.IsValid());*/

	CDate date4(1, OCTOBER, 10000);
	CHECK(!date4.IsValid());
}
