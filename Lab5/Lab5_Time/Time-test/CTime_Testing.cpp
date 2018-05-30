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
/*
TEST_CASE("You can't create time like 25.61.61")
{
	CHECK_THROWS(CTime time(25, 61, 61));
}*/

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


TEST_CASE("You can do time1 += time2")
{
	CTime time1(14, 30, 25);
	CTime time2(03, 18, 44); 

	time1 += time2;

	CHECK(time1.GetTimeStamp() == 64149);

	CTime time3(200);
	time3 += time3;

	CHECK(time3.GetTimeStamp() == 400);

	CTime time4(LAST_SECOND_OF_DAY);
	time4 += 5;
	CHECK(time4.GetTimeStamp() == 4);
}

TEST_CASE("You can do time1 -= time2")
{
	CTime time1(14, 30, 25);
	CTime time2(03, 18, 44);

	time1 -= time2;

	CHECK(time1.GetTimeStamp() == 40301);

	CTime time3(200);
	time3 -= time3;

	CHECK(time3.GetTimeStamp() == 0);

	CTime time4(0);
	time4 -= 5;
	CHECK(time4.GetTimeStamp() == 86395);
}

TEST_CASE("You can multiply time on time")
{
	CTime time1(10);
	CTime time2(10);

	CTime time3 = time1 * time2;

	CHECK(time3.GetTimeStamp() == 100);

	CTime time4(10000);
	CTime time5 = time3 * time4;
	CHECK(time5.GetTimeStamp() == 49600);
}

TEST_CASE("You can multiply time on int numb")
{
	CTime time1(10);
	CTime time3 = time1 * 10;
	CHECK(time3.GetTimeStamp() == 100);

	CTime time4(10000);
	CTime time5 = time3 * time4;
	CHECK(time5.GetTimeStamp() == 49600);

	CTime time6 = 10 * time1;
	CHECK(time6.GetTimeStamp() == 100);
}

TEST_CASE("You can division time on int numb")
{
	CTime time1(9, 15, 40);
	CTime time2 = time1 / 3;
	CHECK(time2.GetTimeStamp() == 11113);

	CHECK_THROWS(time1 / 0);

}

TEST_CASE("You can division time on time (return number)")
{
	CTime time1(9, 15, 40);
	CTime time2(3, 10, 20);
	CTime time0(0, 0, 0);

	unsigned divisionResult = time1 / time2;

	CHECK(divisionResult == 2);

	CHECK_THROWS(time1 / time0);

}

TEST_CASE("You can do time1 *= time2")
{
	CTime time1(14, 30, 25);
	CTime time2(03, 18, 44);

	time1 *= time2;

	CHECK(time1.GetTimeStamp() == 46100);

	CTime time3(20);
	time3 *= time3;

	CHECK(time3.GetTimeStamp() == 400);

	CTime time4(LAST_SECOND_OF_DAY);
	time4 *= 5;
	CHECK(time4.GetTimeStamp() == 86395);
}

TEST_CASE("You can do time1 /= number")
{
	CTime time1(9, 15, 40);

	time1 /= 3;

	CHECK(time1.GetTimeStamp() == 11113);

	CHECK_THROWS(time1 /= 0);

}

TEST_CASE("You can compare two time value (use operator == or !=)")
{
	CTime time1(100);
	CTime time2(100);
	CTime time3(99);
	CTime time4(101);

	CHECK(time1 == time2);
	CHECK(time1 != time3);
	CHECK(time1 != time4);
	CHECK(time1 == time1);
}

TEST_CASE("You can compare two time value (use operator < or >)")
{
	CTime time1(100);
	CTime time2(100);
	CTime time3(99);
	CTime time4(101);

	CHECK(!(time1 > time2));
	CHECK(time1 > time3);
	CHECK(time1 < time4);
	CHECK(!(time1 > time1));
}

TEST_CASE("You can compare two time value (use operator <= or >=)")
{
	CTime time1(100);
	CTime time2(100);
	CTime time3(99);
	CTime time4(101);

	CHECK(time1 >= time2);
	CHECK(time1 >= time3);
	CHECK(time1 <= time4);
	CHECK(time1 >= time1);
}