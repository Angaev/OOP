#include "stdafx.h"
#include "CRectangle.h"
#include <cmath>
#include <string>

using namespace std;

CRectangle::CRectangle(CPoint const& leftTop, CPoint const& rightBottom, double width, double height,
	std::string const& outlineColor, std::string const& fillColor) :
	m_leftTopPoint(leftTop),
	m_rightBottomPoint(rightBottom),
	m_width(width),
	m_height(height),
	m_outlineColor(outlineColor),
	m_fillColor(fillColor)
{
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return m_width * 2 + m_height * 2;
}

std::string CRectangle::ToString() const
{
	return static_cast<string>("Area: ") + to_string(GetArea()) +
		static_cast<string>(" Perimetr: ") + to_string(GetPerimeter()) +
		static_cast<string>(" Outline color: ") + GetOutlineColor() +
		static_cast<string>(" Fill color: ") + GetFillColor() + "\n";
}

std::string CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CRectangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTopPoint;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottomPoint;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}
