#include "IVIsualObjectInfo.h"
#include <sstream>

IVisualObjectInfo::IVisualObjectInfo(std::string color, std::vector<Point> bounds)
	: m_bounds(bounds)
{
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
	m_color = sfColor;
}

IVisualObjectInfo::IVisualObjectInfo(std::string color, std::vector<Point> bounds, std::string text)
	: m_bounds(bounds)
	, m_possibleText(text)
{
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
	m_color = sfColor;
}

sf::Color IVisualObjectInfo::GetColor() const
{
	return m_color;
}

std::vector<Point> IVisualObjectInfo::GetBounds() const
{
	return m_bounds;
}

std::string IVisualObjectInfo::GetText() const
{
	return m_possibleText;
}
