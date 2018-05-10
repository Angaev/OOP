#include "stdafx.h"
#include "../../../Catch/catch.hpp"
#include "../Car/CCar.h"

bool IsEnumEqual(Direction const enum1, Direction const enum2)
{
	return enum1 == enum2;
}

//engine testing
TEST_CASE("The new car is turn off engine")
{
	CCar car;
	REQUIRE(!car.IsEngineOn());
}

TEST_CASE("If start stopped engine then engine start")
{
	CCar car;
	REQUIRE(car.TurnOnEngine());
	REQUIRE(car.IsEngineOn());
}

TEST_CASE("If start engine when it is started then engine will remain turn on")
{
	CCar car;
	car.TurnOnEngine();
	REQUIRE(!car.TurnOnEngine());
	REQUIRE(car.IsEngineOn());
}

TEST_CASE("If turn off engine when it is start then engine is turn off")
{
	CCar car;
	car.TurnOnEngine();
	CHECK(car.TurnOffEngine());
	REQUIRE(!car.IsEngineOn());
}

TEST_CASE("If turn off engine when he is stopped then engine will remain turn off")
{
	CCar car;
	car.TurnOnEngine();
	car.TurnOffEngine();
	REQUIRE(!car.TurnOffEngine());
	REQUIRE(!car.IsEngineOn());
}


TEST_CASE("If gear != 0 and turn off engine then engine is not turn off")
{
	CCar car;
	car.TurnOnEngine();
	car.SetGear(1);
	REQUIRE(!car.TurnOffEngine());
	REQUIRE(car.IsEngineOn());
}

TEST_CASE("If gear == 0, speed > 0 and turn off engine then engine will remain turn on. After speed = 0  can trun off engine")
{
	CCar car;
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(10);
	car.SetGear(0);
	REQUIRE(!car.TurnOffEngine());
	REQUIRE(car.IsEngineOn());
	car.SetSpeed(0);
	REQUIRE(car.TurnOffEngine());
	REQUIRE(!car.IsEngineOn());
}

//gears testing
TEST_CASE("You can't set gear (!=0) when engine is turn off")
{
	CCar car;
	REQUIRE(!car.SetGear(-1));
	REQUIRE(!car.SetGear(1));
	REQUIRE(!car.SetGear(2));
	REQUIRE(!car.SetGear(3));
	REQUIRE(!car.SetGear(4));
	REQUIRE(!car.SetGear(5));
	REQUIRE(car.SetGear(0));
	REQUIRE(car.GetTurnGear() == 0);
}

TEST_CASE("You can start drive car (start engine, gear 0 -> 1) ")
{
	CCar car;
	car.TurnOnEngine();
	CHECK(car.SetGear(1));
	REQUIRE(1 == car.GetTurnGear());
}

TEST_CASE("Can't set an existing gear")
{
	CCar car;
	car.TurnOnEngine();
	CHECK(!car.SetGear(-2));
	CHECK(!car.SetGear(6));
	REQUIRE(car.GetTurnGear() == 0);
}

TEST_CASE("Can set gear if current speed allow")
{
	CCar car;
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(30);
	CHECK(car.SetGear(2));
	CHECK(car.SetGear(3));
	CHECK(!car.SetGear(4));
	CHECK(!car.SetGear(5));
	CHECK(car.SetGear(0));
	CHECK(car.SetGear(2));
	car.SetSpeed(50);
	CHECK(car.SetGear(4));
	CHECK(car.SetGear(5));
	CHECK(!car.SetGear(1));
	CHECK(!car.SetGear(-1));
	CHECK(car.SetGear(0));
}

TEST_CASE("revers gear can turn on olny always full stop (speed = 0, gear = 0)")
{
	CCar car;
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(15);
	car.SetSpeed(0);
	//can't set gear (need 0 gear)
	CHECK(!car.SetGear(-1));
	CHECK(car.GetTurnGear() == 1);
	car.SetGear(0);
	//can set gear (need 0 gear)
	CHECK(car.SetGear(-1));
	CHECK(car.GetTurnGear() == -1);
}

//direction testing

TEST_CASE("If speed = 0 then direction == stop ")
{
	CCar car;
	car.TurnOnEngine();
	CHECK(0 == car.GetSpeed());
	REQUIRE(IsEnumEqual(Direction::STOP, car.GetDirection()));
}

TEST_CASE("If speed < 0 then direction == reverse ")
{
	CCar car;
	car.TurnOnEngine();
	CHECK(car.SetGear(-1));
	car.SetSpeed(10);
	REQUIRE(IsEnumEqual(Direction::REVERSE, car.GetDirection()));
}

TEST_CASE("If speed > 0 then direction == forward ")
{
	CCar car;
	car.TurnOnEngine();
	CHECK(car.SetGear(1));
	car.SetSpeed(10);
	REQUIRE(IsEnumEqual(Direction::FORWARD, car.GetDirection()));
}

//speed testing
TEST_CASE("Can't set speed if engine - Off")
{
	CCar car;
	int lastSpeed = car.GetSpeed();
	REQUIRE(!car.SetSpeed(10));
	REQUIRE(lastSpeed == car.GetSpeed());
}

TEST_CASE("If move reverse, set speed 5, turn 0 gear and set speed 4 then direction will still be reverse")
{
	CCar car;
	car.TurnOnEngine();
	car.SetGear(-1);
	car.SetSpeed(5);
	car.SetGear(0);
	car.SetSpeed(4);
	REQUIRE(IsEnumEqual(Direction::REVERSE, car.GetDirection()));
}

	//reverse gear
TEST_CASE("Can set speed = 10 if engine - ON, speed = 0")
{
	CCar car;
	car.TurnOnEngine();
	CHECK(car.SetGear(-1));
	CHECK(-1 == car.GetTurnGear());
	REQUIRE(car.SetSpeed(10));
}

TEST_CASE("Can't set speed = 21 if engine - ON, speed = -10 (Incorrect speed)")
{
	CCar car;
	car.TurnOnEngine();
	car.SetGear(-1);
	CHECK(car.SetSpeed(10));
	REQUIRE(!car.SetSpeed(21));
}
	//1 gear
TEST_CASE("test speed range  for 1 gear")
{
	CCar car;
	car.TurnOnEngine();
	car.SetGear(1);

	REQUIRE(car.SetSpeed(30));
	REQUIRE(car.SetSpeed(0));
	REQUIRE(!car.SetSpeed(31));
	REQUIRE(!car.SetSpeed(-1));
}
	//2 gear
TEST_CASE("test speed range for 2 gear")
{
	CCar car;
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(30);
	car.SetGear(2);
	REQUIRE(car.SetSpeed(50));
	REQUIRE(car.SetSpeed(20));
	REQUIRE(!car.SetSpeed(51));
	REQUIRE(!car.SetSpeed(19));
}
	//3 gear
TEST_CASE("test speed range  for 3 gear")
{
	CCar car;
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(30);
	car.SetGear(2);
	car.SetSpeed(50);
	car.SetGear(3);
	REQUIRE(car.SetSpeed(60));
	REQUIRE(car.SetSpeed(30));
	REQUIRE(!car.SetSpeed(61));
	REQUIRE(!car.SetSpeed(29));
}


	//4 gear
TEST_CASE("test speed range  for 4 gear")
{
	CCar car;
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(30);
	car.SetGear(2);
	car.SetSpeed(50);
	car.SetGear(4);
	REQUIRE(car.SetSpeed(90));
	REQUIRE(car.SetSpeed(40));
	REQUIRE(!car.SetSpeed(91));
	REQUIRE(!car.SetSpeed(39));
}

	//5 gear
TEST_CASE("test speed range for 5 gear")
{
	CCar car;
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(30);
	car.SetGear(2);
	car.SetSpeed(50);
	car.SetGear(5);
	REQUIRE(car.SetSpeed(150));
	REQUIRE(car.SetSpeed(50));
	REQUIRE(!car.SetSpeed(151));
	REQUIRE(!car.SetSpeed(49));
}
	// N gear
TEST_CASE("Can set 0 gear, but set speed not more than last speed")
{
	CCar car;
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(30);
	car.SetGear(0);
	REQUIRE(car.SetSpeed(29));
	REQUIRE(!car.SetSpeed(30));
}