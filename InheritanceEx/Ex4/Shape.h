#pragma once

#include "Vector2D.h"

class Shape
{
private:
	Vector2D m_center;

protected:
	double area;

public:
	Shape() 
		: m_center(0,0)
		, area(0)
	{
	}
	Shape(const Vector2D& center)
		: m_center(center)
		, area(0)
	{
	}

	const Vector2D& getCenter() const
	{
		return m_center;
	}

	const double getArea() const
	{
		return area;
	}
};