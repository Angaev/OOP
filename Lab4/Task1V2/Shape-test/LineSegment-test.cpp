#include "stdafx.h"
#include "../../../Catch/catch.hpp"
#include "../Shape/CLineSegment.h"

using namespace std;

bool IsPointEqual(CPoint const& p1, CPoint const& p2)
{
	return (p1.GetCoordinateX() == p2.GetCoordinateX()) && (p1.GetCoordinateY() == p2.GetCoordinateY()) ? true : false;
}

TEST_CASE("Line can save own coordiants")
{
	CLineSegment line{ CPoint {10.5, 15.3}, CPoint {15.6, 2}, "ff0000" };

	CHECK(IsPointEqual(line.GetStartPoint(), CPoint{ 10.5, 15.3 }));
	CHECK(IsPointEqual(line.GetEndPoint(), CPoint{ 15.6, 2 }));
}

TEST_CASE("Line can save own color")
{
	CLineSegment line{ CPoint{ 10.5, 15.3 }, CPoint{ 15.6, 2 }, "ff0000" };
	string color{ "ff0000" };
	CHECK(line.GetOutlineColor() == color);
}

TEST_CASE("Line have 0 area")
{
	CLineSegment line{ CPoint{ 10.5, 15.3 }, CPoint{ 15.6, 2 }, "ff0000" };
	CHECK(line.GetArea() == 0);
}

TEST_CASE("Line have perimeter")
{
	CLineSegment line{ CPoint{ 10.5, 15.3 }, CPoint{ 15.6, 2 }, "ff0000" };

	CHECK(round(line.GetPerimeter()*100)/100 == 14.24); //14.24429
}
