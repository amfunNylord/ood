#include "Circle.h"
#include <iostream>

shape::Circle::Circle(std::string id, std::string color, std::string type, double x, double y, double r)
	: Shape(id, color, type)
	, m_x(x)
	, m_y(y)
	, m_r(r)
{
}

shape::Circle::~Circle()
{
}

void shape::Circle::AppendProperties(std::ostream& strm) const
{
	strm << m_x << ' ' << m_y << ' ' << m_r << std::endl;
}
