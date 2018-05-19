#include "stdafx.h"
#include "../../../Catch/catch.hpp"
#include "../Car/CCar.h"
#include <functional>

using namespace std;

void ExpectOperationSuccess(CCar& car, const std::function<bool(CCar& car)>& op, bool engineIsOn, int gear, int speed, Direction movingDirection)
{
	REQUIRE(op(car)); // ожидаем, что операция вернет true (успех)
	// Сравниваем состояние свойства объект с ожидаемым
	CHECK(car.IsEngineOn() == engineIsOn);
	CHECK(car.GetTurnGear() == gear);
	CHECK(car.GetSpeed() == speed);
	CHECK(car.GetDirection() == movingDirection);
	return;
}

void ExpectOperationFailure(CCar const& car, const std::function<bool(CCar& car)>& op)
{
	auto clone(car); // сделали клон объекта
	REQUIRE(!op(clone)); // ожидаем, что операция завершится неуспешно (передаем клон)
						 // проверяем, что после выполнения операции состояние клона не отличается от оригинала 
						 // (операция в случае неудачи оставляет объект в состоянии, в котором он пребывал до операции)
	CHECK(clone.IsEngineOn() == car.IsEngineOn());
	CHECK(clone.GetTurnGear() == car.GetTurnGear());
	CHECK(clone.GetSpeed() == car.GetSpeed());
	CHECK(clone.GetDirection() == car.GetDirection());
	return;
}

bool IsEnumEqual(Direction const enum1, Direction const enum2)
{
	return enum1 == enum2;
}

//engine testing
TEST_CASE("The new car is turn off engine")
{
	CCar car;
	ExpectOperationSuccess(car, [](auto&& car) {return !car.IsEngineOn();  }, false /*engOff*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

}

TEST_CASE("If start stopped engine then engine start")
{
	CCar car;
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);
}

TEST_CASE("If start engine when it is started then engine will remain turn on")
{
	CCar car;
	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//again start engine
	ExpectOperationFailure(car, [](auto&& car) {return car.TurnOnEngine(); });
}

TEST_CASE("If turn off engine when it is start then engine is turn off")
{
	CCar car;
	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//stop engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOffEngine(); }, false /*engOff*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

}

TEST_CASE("If turn off engine when he is stopped then engine will remain turn off")
{
	CCar car;

	//stop engine
	ExpectOperationFailure(car, [](auto&& car) {return car.TurnOffEngine(); });
}


TEST_CASE("If gear != 0 and turn off engine then engine is not turn off")
{
	CCar car;

	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(1); }, true /*engON*/, 1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//stop engine
	ExpectOperationFailure(car, [](auto&& car) {return car.TurnOffEngine(); });
		
}

TEST_CASE("If gear == 0, speed > 0 and turn off engine then engine will remain turn on. After speed = 0  can trun off engine")
{
	CCar car;

	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(1); }, true /*engON*/, 1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 10 speed
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(10); }, true /*engON*/, 1 /*gear*/, 10 /*speed*/, Direction::FORWARD);

	//set 0 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(0); }, true /*engON*/, 0 /*gear*/, 10 /*speed*/, Direction::FORWARD);

	//stop engine
	ExpectOperationFailure(car, [](auto&& car) {return car.TurnOffEngine(); });

	//set 0 speed
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(0); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//stop engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOffEngine(); }, false /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);
}

//gears testing
TEST_CASE("You can't set gear (!=0) when engine is turn off")
{
	CCar car;

	//set -1 gear
	ExpectOperationFailure(car, [](auto&& car) {return car.SetGear(-1); });

	//set -1 gear
	ExpectOperationFailure(car, [](auto&& car) {return car.SetGear(1); });

	//set 2 gear
	ExpectOperationFailure(car, [](auto&& car) {return car.SetGear(2); });

	//set 3 gear
	ExpectOperationFailure(car, [](auto&& car) {return car.SetGear(3); });

	//set 4 gear
	ExpectOperationFailure(car, [](auto&& car) {return car.SetGear(4); });

	//set 5 gear
	ExpectOperationFailure(car, [](auto&& car) {return car.SetGear(5); });

	//set 0 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(0); }, false /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

}

TEST_CASE("You can start drive car (start engine, gear 0 -> 1) ")
{
	CCar car;

	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(1); }, true /*engON*/, 1 /*gear*/, 0 /*speed*/, Direction::STOP);
}

TEST_CASE("Can't set an existing gear")
{
	CCar car;

	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set -2 gear
	ExpectOperationFailure(car, [](auto&& car) {return car.SetGear(-2); });

	//set -6 gear
	ExpectOperationFailure(car, [](auto&& car) {return car.SetGear(6); });

}

TEST_CASE("Can set gear if current speed allow")
{
	CCar car;

	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(1); }, true /*engON*/, 1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 30 speed
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(30); }, true /*engON*/, 1 /*gear*/, 30 /*speed*/, Direction::FORWARD);

	//set 2 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(2); }, true /*engON*/, 2 /*gear*/, 30 /*speed*/, Direction::FORWARD);

	//set 3 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(3); }, true /*engON*/, 3 /*gear*/, 30 /*speed*/, Direction::FORWARD);

	//set 50 speed
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(50); }, true /*engON*/, 3 /*gear*/, 50 /*speed*/, Direction::FORWARD);

	//set 4 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(4); }, true /*engON*/, 4 /*gear*/, 50 /*speed*/, Direction::FORWARD);

	//set 5 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(5); }, true /*engON*/, 5 /*gear*/, 50 /*speed*/, Direction::FORWARD);

	//can't set 1 gear
	ExpectOperationFailure(car, [](auto&& car) {return car.SetGear(1); });

	//can't set -1 gear
	ExpectOperationFailure(car, [](auto&& car) {return car.SetGear(-1); });

	//set 0 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(0); }, true /*engON*/, 0 /*gear*/, 50 /*speed*/, Direction::FORWARD);
}

TEST_CASE("revers gear can turn on olny always full stop (speed = 0, gear = 0)")
{
	CCar car;

	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(1); }, true /*engON*/, 1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 15 speed
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(15); }, true /*engON*/, 1 /*gear*/, 15 /*speed*/, Direction::FORWARD);

	//set 0 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(0); }, true /*engON*/, 0 /*gear*/, 15 /*speed*/, Direction::FORWARD);

	//can't set -1 gear (need 0 speed)
	ExpectOperationFailure(car, [](auto&& car) {return car.SetGear(-1); });
	
	//set 0 speed
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(0); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set -1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(-1); }, true /*engON*/, -1 /*gear*/, 0 /*speed*/, Direction::STOP);

}

//speed testing
TEST_CASE("Can't set speed if engine - Off")
{
	CCar car;
	//can't set speed 
	ExpectOperationFailure(car, [](auto&& car) {return car.SetSpeed(10); });	

}

TEST_CASE("If move reverse, set speed 5, turn 0 gear and set speed 4 then direction will still be reverse")
{
	CCar car;
	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set -1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(-1); }, true /*engON*/, -1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 5 speed
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(5); }, true /*engON*/, -1 /*gear*/, 5 /*speed*/, Direction::REVERSE);

	//set 0 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(0); }, true /*engON*/, 0 /*gear*/, 5 /*speed*/, Direction::REVERSE);

	//set 4 speed
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(4); }, true /*engON*/, 0 /*gear*/, 4 /*speed*/, Direction::REVERSE);

	//is direction reverse?
	ExpectOperationSuccess(car, [](auto&& car) {return IsEnumEqual(Direction::REVERSE, car.GetDirection()); }, true /*engON*/, 0 /*gear*/, 4 /*speed*/, Direction::REVERSE);
}

	//reverse gear
TEST_CASE("Can set speed = 10 if engine - ON, speed = 0")
{
	CCar car;
	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set -1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(-1); }, true /*engON*/, -1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set speed 10
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(10); }, true /*engON*/, -1 /*gear*/, 10 /*speed*/, Direction::REVERSE);
}

TEST_CASE("Can't set speed = 21 if engine - ON, speed = -10 (Incorrect speed)")
{
	CCar car;
	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set -1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(-1); }, true /*engON*/, -1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set speed 10
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(10); }, true /*engON*/, -1 /*gear*/, 10 /*speed*/, Direction::REVERSE);

	//can't set 21 speed 
	ExpectOperationFailure(car, [](auto&& car) {return car.SetSpeed(21); });
}
	//1 gear
TEST_CASE("test speed range  for 1 gear")
{
	CCar car;
	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(1); }, true /*engON*/, 1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set speed 30
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(30); }, true /*engON*/, 1 /*gear*/, 30 /*speed*/, Direction::FORWARD);

	//set speed 0
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(0); }, true /*engON*/, 1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//can't set 31 speed 
	ExpectOperationFailure(car, [](auto&& car) {return car.SetSpeed(31); });
	
	//can't set -1 speed 
	ExpectOperationFailure(car, [](auto&& car) {return car.SetSpeed(-1); });

}
	//2 gear
TEST_CASE("test speed range for 2 gear")
{
	CCar car;

	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(1); }, true /*engON*/, 1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set speed 30
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(30); }, true /*engON*/, 1 /*gear*/, 30 /*speed*/, Direction::FORWARD);

	//set 2 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(2); }, true /*engON*/, 2 /*gear*/, 30 /*speed*/, Direction::FORWARD);

	//set speed 50
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(50); }, true /*engON*/, 2 /*gear*/, 50 /*speed*/, Direction::FORWARD);

	//set speed 20
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(20); }, true /*engON*/, 2 /*gear*/, 20 /*speed*/, Direction::FORWARD);

	//can't set 51 speed 
	ExpectOperationFailure(car, [](auto&& car) {return car.SetSpeed(51); });

	//can't set 19 speed 
	ExpectOperationFailure(car, [](auto&& car) {return car.SetSpeed(19); });

}
	//3 gear
TEST_CASE("test speed range  for 3 gear")
{
	CCar car;
	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(1); }, true /*engON*/, 1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set speed 30
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(30); }, true /*engON*/, 1 /*gear*/, 30 /*speed*/, Direction::FORWARD);

	//set 2 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(2); }, true /*engON*/, 2 /*gear*/, 30 /*speed*/, Direction::FORWARD);

	//set speed 50
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(50); }, true /*engON*/, 2 /*gear*/, 50 /*speed*/, Direction::FORWARD);
	
	//set 3 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(3); }, true /*engON*/, 3 /*gear*/, 50 /*speed*/, Direction::FORWARD);

	//set speed 60
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(60); }, true /*engON*/, 3 /*gear*/, 60 /*speed*/, Direction::FORWARD);

	//set speed 30
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(30); }, true /*engON*/, 3 /*gear*/, 30 /*speed*/, Direction::FORWARD);

	//can't set 61 speed 
	ExpectOperationFailure(car, [](auto&& car) {return car.SetSpeed(61); });

	//can't set 29 speed 
	ExpectOperationFailure(car, [](auto&& car) {return car.SetSpeed(29); });
}


	//4 gear
TEST_CASE("test speed range  for 4 gear")
{
	CCar car;
	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(1); }, true /*engON*/, 1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set speed 30
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(30); }, true /*engON*/, 1 /*gear*/, 30 /*speed*/, Direction::FORWARD);

	//set 2 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(2); }, true /*engON*/, 2 /*gear*/, 30 /*speed*/, Direction::FORWARD);

	//set speed 50
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(50); }, true /*engON*/, 2 /*gear*/, 50 /*speed*/, Direction::FORWARD);

	//set 4 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(4); }, true /*engON*/, 4 /*gear*/, 50 /*speed*/, Direction::FORWARD);

	//set speed 90
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(90); }, true /*engON*/, 4 /*gear*/, 90 /*speed*/, Direction::FORWARD);

	//set speed 40
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(40); }, true /*engON*/, 4 /*gear*/, 40 /*speed*/, Direction::FORWARD);

	//can't set 91 speed 
	ExpectOperationFailure(car, [](auto&& car) {return car.SetSpeed(91); });

	//can't set 39 speed 
	ExpectOperationFailure(car, [](auto&& car) {return car.SetSpeed(39); });

}

	//5 gear
TEST_CASE("test speed range for 5 gear")
{
	CCar car;
	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set 1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(1); }, true /*engON*/, 1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set speed 30
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(30); }, true /*engON*/, 1 /*gear*/, 30 /*speed*/, Direction::FORWARD);

	//set 2 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(2); }, true /*engON*/, 2 /*gear*/, 30 /*speed*/, Direction::FORWARD);

	//set speed 50
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(50); }, true /*engON*/, 2 /*gear*/, 50 /*speed*/, Direction::FORWARD);

	//set 5 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(5); }, true /*engON*/, 5 /*gear*/, 50 /*speed*/, Direction::FORWARD);

	//set speed 150
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(150); }, true /*engON*/, 5 /*gear*/, 150 /*speed*/, Direction::FORWARD);

	//set speed 50
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(50); }, true /*engON*/, 5 /*gear*/, 50 /*speed*/, Direction::FORWARD);

	//can't set 151 speed 
	ExpectOperationFailure(car, [](auto&& car) {return car.SetSpeed(151); });

	//can't set 49 speed 
	ExpectOperationFailure(car, [](auto&& car) {return car.SetSpeed(49); });
}
	// N gear
TEST_CASE("Can set 0 gear, but set speed not more than last speed")
{
	CCar car;
	//start engine
	ExpectOperationSuccess(car, [](auto&& car) {return car.TurnOnEngine(); }, true /*engON*/, 0 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set -1 gear
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetGear(-1); }, true /*engON*/, -1 /*gear*/, 0 /*speed*/, Direction::STOP);

	//set speed 20
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(20); }, true /*engON*/, -1 /*gear*/, 20 /*speed*/, Direction::REVERSE);

	//set speed 0
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(0); }, true /*engON*/, -1 /*gear*/, 00 /*speed*/, Direction::STOP);

	//set speed 20
	ExpectOperationSuccess(car, [](auto&& car) {return car.SetSpeed(20); }, true /*engON*/, -1 /*gear*/, 20 /*speed*/, Direction::REVERSE);

	//can't set 21 speed 
	ExpectOperationFailure(car, [](auto&& car) {return car.SetSpeed(21); });

}