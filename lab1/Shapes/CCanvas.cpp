#include "CCanvas.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

CCanvas::CCanvas(sf::Color color, double x, double y, sf::RenderWindow& window)
	: m_color(color)
	, m_x(x)
	, m_y(y)
	, m_window(window)
{
}

void CCanvas::SetColor(sf::Color newColor)
{
	m_color = newColor;
}

void CCanvas::MoveTo(double newX, double newY)
{
	m_x = newX;
	m_y = newY;
}

void CCanvas::LineTo(double x, double y)
{
	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f((float)m_x, (float)m_y)),
		sf::Vertex(sf::Vector2f((float)x, (float)y))
	};
	line[0].color = sf::Color(m_color);
	line[1].color = sf::Color(m_color);

	m_window.draw(line, 2, sf::Lines);
	m_x = x;
	m_y = y;
}

void CCanvas::DrawEllipse(double cx, double cy, double rx, double ry)
{
	sf::CircleShape circle((float)rx);
	circle.setPosition((float)(cx - rx), (float)(cy - ry));
	circle.setFillColor(m_color);
	circle.setOutlineThickness(1);
	circle.setOutlineColor(m_color);

	m_window.draw(circle);
}

void CCanvas::DrawText(double left, double top, double fontSize, const std::string& text)
{
	m_x = left;
	m_y = top;
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		return;
	sf::Text textToDraw("Hello world", font, (unsigned int)fontSize);
	textToDraw.setFillColor(m_color);
	textToDraw.setPosition(float(m_x), float(m_y));

	m_window.draw(textToDraw);
}

sf::RenderWindow& CCanvas::GetWindow()
{
	return m_window;
}