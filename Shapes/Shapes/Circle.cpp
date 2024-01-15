#include "Circle.h"
#include <sstream>

shape::Circle::Circle(std::string type, std::string color, double x, double y, double r)
	: ShapeType(type, color)
	, m_x(x)
	, m_y(y)
	, m_r(r)
{
}

void shape::Circle::Draw(gfx::ICanvas* canvas)
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
	canvas->DrawEllipse(m_x, m_y, m_r, m_r);
}

void shape::Circle::AppendProperties(std::ostream& strm) const
{
	strm << m_x << ' ' << m_y << ' ' << m_r << std::endl;
}

void shape::Circle::MoveShape(double dx, double dy)
{
	m_x += dx;
	m_y += dy;
}

std::unique_ptr<shape::ShapeType> shape::Circle::Clone() const
{
	return std::make_unique<Circle>(*this);
}
