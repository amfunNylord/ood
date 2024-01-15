#include "Text.h"
#include <sstream>

shape::Text::Text(std::string type, std::string color, double left, double top, double size, std::string text)
	: ShapeType(type, color)
	, m_left(left)
	, m_top(top)
	, m_size(size)
	, m_text(text)
{
}

void shape::Text::Draw(gfx::ICanvas* canvas)
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
	canvas->DrawText(m_left, m_top, m_size, m_text);
}

void shape::Text::AppendProperties(std::ostream& strm) const
{
	strm << m_left << ' ' << m_top << ' ' << m_size << ' ' << m_text << std::endl;
}

void shape::Text::MoveShape(double dx, double dy)
{
	m_left += dx;
	m_top += dy;
}

std::unique_ptr<shape::ShapeType> shape::Text::Clone() const
{
	return std::make_unique<Text>(*this);
}
