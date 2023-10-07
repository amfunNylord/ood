#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Point.h"

class IVisualObjectInfo
{
public:
	IVisualObjectInfo(std::string color, std::vector<Point> bounds);
	IVisualObjectInfo(std::string color, std::vector<Point> bounds, std::string text);
	sf::Color GetColor() const;
	std::vector<Point> GetBounds() const;
	std::string GetText() const;

private:
	sf::Color m_color;
	std::vector<Point> m_bounds;
	std::string m_possibleText;
};
