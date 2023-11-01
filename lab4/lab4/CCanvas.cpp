#include "CCanvas.h"
#include "EllipseSFML.h"
#include <SFML/Graphics.hpp>

CCanvas::CCanvas(sf::Color color, sf::RenderWindow& window)
	: m_color(color)
	, m_window(window)
{
}

void CCanvas::SetColor(Color c)
{
	switch (c)
	{
	case Color::Green:
		m_color = sf::Color::Green;
		break;
	case Color::Red:
		m_color = sf::Color::Red;
		break;
	case Color::Black:
		m_color = sf::Color::Black;
		break;
	case Color::Blue:
		m_color = sf::Color::Blue;
		break;
	case Color::Yellow:
		m_color = sf::Color::Yellow;
		break;
	case Color::Pink:
		m_color = sf::Color::Magenta;
		break;
	}
}

void CCanvas::DrawLine(Point from, Point to)
{	
	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f((float)from.x, (float)from.y)),
		sf::Vertex(sf::Vector2f((float)to.x, (float)to.y))
	};

	line[0].color = sf::Color(m_color);
	line[1].color = sf::Color(m_color);

	m_window.draw(line, 2, sf::Lines);
}

void CCanvas::DrawEllipse(Point center, double horizontalRadius, double verticalRadius)
{
	auto ellipse = std::make_unique<EllipseShape>(center, sf::Vector2f(float(horizontalRadius), float(verticalRadius)));
	ellipse->setOutlineColor(m_color);
	ellipse->setFillColor(sf::Color::Transparent);
	ellipse->setOutlineThickness(1);

	m_window.draw(*ellipse.get());
}
