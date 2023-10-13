#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "SPoint.h"

class VisualObjectInfo
{
public:
	VisualObjectInfo(std::string color, std::vector<SPoint> bounds);
	VisualObjectInfo(std::string color, std::vector<SPoint> bounds, std::string text);
	sf::Color GetColor() const;
	std::vector<SPoint> GetBounds() const;
	std::string GetText() const;

private:
	sf::Color m_color;
	std::vector<SPoint> m_bounds;
	std::string m_possibleText;
};
