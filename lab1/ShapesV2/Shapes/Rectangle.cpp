#include "Rectangle.h"
#include <sstream>

shape::Rectangle::Rectangle(std::string type, std::string color, double left, double top, double width, double height)
	: ShapeType(type, color)
	, m_left(left)
	, m_top(top)
	, m_width(width)
	, m_height(height)
{
}

void shape::Rectangle::Draw(gfx::ICanvas* canvas)
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
	canvas->MoveTo(m_left, m_top);
	canvas->LineTo(m_left + m_width, m_top);
	canvas->LineTo(m_left + m_width, m_top + m_height);
	canvas->LineTo(m_left, m_top + m_height);
	canvas->LineTo(m_left, m_top);
}

void shape::Rectangle::MoveShape(double dx, double dy)
{
	m_left += dx;
	m_top += dy;
}

void shape::Rectangle::AppendProperties(std::ostream& strm) const
{
	strm << m_left << ' ' << m_top << ' ' << m_width << ' '<< m_height << std::endl;
}
