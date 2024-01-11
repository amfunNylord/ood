#include "Line.h"
#include <sstream>

shape::Line::Line(std::string type, std::string color, double x1, double y1, double x2, double y2)
	: ShapeType(type, color)
	, m_point1(x1, y1)
	, m_point2(x2, y2)
{
}

void shape::Line::Draw(gfx::ICanvas* canvas)
{
	std::string color = GetColor();
	std::string newFormatColor;
	for (size_t i = 1; i < color.size(); i++)
	{
		newFormatColor += color[i];
		if (i % 2 == 0)
		{
			if (i == 1)
			{
				continue;
			}
			newFormatColor += ' ';
		}
	}
	std::istringstream stream(newFormatColor);

	int firstValue, secondValue, thirdValue;
	stream >> std::hex >> firstValue >> secondValue >> thirdValue;
	sf::Color sfColor(firstValue, secondValue, thirdValue);
	canvas->SetColor(sfColor);
	canvas->MoveTo(m_point1.x, m_point1.y);
	canvas->LineTo(m_point2.x, m_point2.y);
}

void shape::Line::AppendProperties(std::ostream& strm) const
{
	strm << m_point1.x << ' ' << m_point1.y << ' ' << m_point2.x << ' ' << m_point2.y << std::endl;
}

void shape::Line::MoveShape(double dx, double dy)
{
	m_point1.x += dx;
	m_point2.x += dx;
	m_point1.y += dy;
	m_point2.y += dy;
}

