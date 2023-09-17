#include "Rectangle.h"
#include <iostream>

shape::Rectangle::Rectangle(std::string id, std::string color, std::string type, double left, double top, double width, double height)
	: Shape(id, color, type)
	, m_left(left)
	, m_top(top)
	, m_width(width)
	, m_height(height)
{
}

shape::Rectangle::~Rectangle()
{
}

void shape::Rectangle::AppendProperties(std::ostream& strm) const
{
	strm << m_left << ' ' << m_top << ' ' << m_width << m_height << std::endl;
}
