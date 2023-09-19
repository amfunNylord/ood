#include "Line.h"
#include <iostream>

shape::Line::Line(std::string type, double x1, double y1, double x2, double y2)
	: ShapeType(type)
	, m_x1(x1)
	, m_y1(y1)
	, m_x2(x2)
	, m_y2(y2)
{
}

shape::Line::~Line()
{
}

void shape::Line::AppendProperties(std::ostream& strm) const
{
	strm << m_x1 << ' ' << m_y1 << ' ' << m_x2 << ' ' << m_y2 << std::endl;
}

