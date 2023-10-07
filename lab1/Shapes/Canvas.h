#pragma once
#include "ICanvas.h"
#include <SFML/Graphics/RenderWindow.hpp>

class Canvas : public gfx::ICanvas
{
public:
	Canvas(sf::Color color, double x, double y, sf::RenderWindow& window);
	void SetColor(sf::Color newColor);
	void MoveTo(double newX, double newY);
	void LineTo(double x, double y);
	void DrawEllipse(double cx, double cy, double rx, double ry);
	void DrawText(double left, double top, double fontSize, const std::string& text);

	sf::RenderWindow& GetWindow();

private:
	sf::Color m_color;
	double m_x;
	double m_y;
	sf::RenderWindow& m_window;
};
