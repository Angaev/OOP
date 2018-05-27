#include "stdafx.h"
#include "../../../Catch/catch.hpp"
#include "../Time/Time.h"

using namespace std;

constexpr unsigned LAST_SECOND_OF_DAY = 86399;

TEST_CASE("You can set time in format hour-mins-sec")
{
	CTime time(18, 31, 25);
	REQUIRE(time.GetTimeStamp() == 66685);
}

TEST_CASE("You can set time in format seconds after 00:00:00")
{
	CTime time(66685);
	REQUIRE(time.GetTimeStamp() == 66685);
}

TEST_CASE("You can get saved time")
{
	CTime time(18, 31, 25);
	CHECK(time.GetHours() == 18);
	CHECK(time.GetMinutes() == 31);
	CHECK(time.GetSeconds() == 25);
}

TEST_CASE("You can increment (prefix) the saved time")
{
	CTime time1(66685);
	++time1;
	CHECK(time1.GetTimeStamp() == 66686);

	CTime time2(LAST_SECOND_OF_DAY);
	++time2;
	CHECK(time2.GetTimeStamp() == 0);
}

TEST_CASE("You can increment (postfix) the saved time")
{
	CTime time1(66685);
	time1++;
	CHECK(time1.GetTimeStamp() == 66686);

	CTime time2(LAST_SECOND_OF_DAY);
	time2++;
	CHECK(time2.GetTimeStamp() == 0);
}


TEST_CASE("You can decrement (prefix) the saved time")
{
	CTime time1(66685);
	--time1;
	CHECK(time1.GetTimeStamp() == 66684);

	CTime time2(0);
	--time2;
	CHECK(time2.GetTimeStamp() == LAST_SECOND_OF_DAY);
}


TEST_CASE("You can decrement (postfix) the saved time")
{
	CTime time1(66685);
	time1--;
	CHECK(time1.GetTimeStamp() == 66684);

	CTime time2(0);
	time2--;
	CHECK(time2.GetTimeStamp() == LAST_SECOND_OF_DAY);
}

TEST_CASE("You can sum time")
{
	CTime time1(14, 30, 25);
	CTime time2(03, 18, 44);

	CTime totalTime = time1 + time2;

	CHECK(totalTime.GetTimeStamp() == 64149);

	CTime time3(LAST_SECOND_OF_DAY);
	CTime time4(1);

	totalTime = time3 + time4;

	CHECK(totalTime.GetTimeStamp() == 0);
	
}

TEST_CASE("You can deduct time")
{
	CTime time1(14, 30, 25);
	CTime time2(03, 18, 44);

	CTime totalTime = time1 - time2;

	CHECK(totalTime.GetTimeStamp() == 40301);

	CTime time3(1);
	CTime time4(20);

	totalTime = time3 - time4;

	CHECK(totalTime.GetTimeStamp() == 86381);
}