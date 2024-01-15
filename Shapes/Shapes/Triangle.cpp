#include "Triangle.h"
#include <sstream>

shape::Triangle::Triangle(std::string type, std::string color, double x1, double y1, double x2, double y2, double x3, double y3)
	: ShapeType(type, color)
	, m_point1(x1, y1)
	, m_point2(x2, y2)
	, m_point3(x3, y3)
{
}

void shape::Triangle::Draw(gfx::ICanvas* canvas)
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
	canvas->LineTo(m_point3.x, m_point3.y);
	canvas->LineTo(m_point1.x, m_point1.y);
}

void shape::Triangle::AppendProperties(std::ostream& strm) const
{
	strm << m_point1.x << ' ' << m_point1.y << ' ' << m_point2.x << ' ' << m_point2.y << ' ' << m_point3.x << ' ' << m_point3.y 
		 << ' ' << std::endl;
}

void shape::Triangle::MoveShape(double dx, double dy)
{
	m_point1.x += dx;
	m_point2.x += dx;
	m_point3.x += dx;
	m_point1.y += dy;
	m_point2.y += dy;
	m_point3.y += dy;
}

std::unique_ptr<shape::ShapeType> shape::Triangle::Clone() const
{
	return std::make_unique<Triangle>(*this);
}
