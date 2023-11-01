#pragma once
#include "ICanvas.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class CCanvas : public ICanvas
{
public:
	CCanvas(sf::Color color, sf::RenderWindow& window);
	void SetColor(Color c) override;
	void DrawLine(Point from, Point to) override;
	void DrawEllipse(Point center, double horizontalRadius, double verticalRadius) override;

private:
	sf::Color m_color;
	sf::RenderWindow& m_window;
};
