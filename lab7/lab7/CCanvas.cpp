#include "CCanvas.h"
#include <SFML/Graphics.hpp>

class EllipseShape : public sf::Shape
{
public:
	explicit EllipseShape(const PointD& center, const sf::Vector2f& radius = sf::Vector2f(0.f, 0.f))
		: m_radius(radius)
		, m_center(center)
	{
		update();
	}

	void setRadius(const sf::Vector2f& radius)
	{
		m_radius = radius;
		update();
	}

	const sf::Vector2f& getRadius() const
	{
		return m_radius;
	}

	virtual std::size_t getPointCount() const
	{
		return 30; // fixed, but could be an attribute of the class if needed
	}

	virtual sf::Vector2f getPoint(std::size_t index) const
	{
		static const float pi = 3.141592654f;

		float angle = index * 2 * pi / getPointCount() - pi / 2;
		float x = std::cos(angle) * m_radius.x;
		float y = std::sin(angle) * m_radius.y;

		return sf::Vector2f(m_radius.x + x + float(m_center.x), m_radius.y + y + float(m_center.y));
	}

private:
	sf::Vector2f m_radius;
	PointD m_center;
};

CCanvas::CCanvas(sf::RenderTarget& target)
	: m_target(target)
{
}

void CCanvas::DrawLine(PointD start, PointD end, RGBAColor color, std::optional<double> thickness)
{
	sf::Vertex vertices[4];

	sf::Vector2f startVector((float)start.x, (float)start.y);
	sf::Vector2f endVector((float)end.x, (float)end.y);

	sf::Vector2f direction = startVector - endVector;
	sf::Vector2f unitDirection = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);
	sf::Vector2f unitPerpendicular(-unitDirection.y, unitDirection.x);

	sf::Vector2f offset = (float)(thickness.value() / 2.f) * unitPerpendicular;

	vertices[0].position = startVector + offset;
	vertices[1].position = endVector + offset;
	vertices[2].position = endVector - offset;
	vertices[3].position = startVector - offset;

	for (auto& vertex : vertices)
	{
		vertex.color = sf::Color(color);
	}

	m_target.draw(vertices, 4, sf::Quads);
}

void CCanvas::DrawEllipse(const PointD center, double horizontalRadius, double verticalRadius, std::optional<RGBAColor> borderColor, std::optional<RGBAColor> fillColor, std::optional<double> thickness)
{
	auto ellipse = EllipseShape(center, sf::Vector2f(float(horizontalRadius), float(verticalRadius)));
	if (fillColor.has_value())
	{
		ellipse.setFillColor(sf::Color(fillColor.value()));
	}
	else
	{
		ellipse.setFillColor(sf::Color::Transparent);
	}
	if (thickness.has_value() && borderColor.has_value())
	{
		ellipse.setOutlineThickness(float(thickness.value()));
		ellipse.setOutlineColor(sf::Color(borderColor.value()));
	}
	m_target.draw(ellipse);
}

void CCanvas::FillPolygon(const std::vector<PointD> vertexes, RGBAColor fillColor)
{
	sf::ConvexShape shape;
	shape.setPointCount(vertexes.size());

	for (size_t index = 0; index < vertexes.size(); index++)
	{
		shape.setPoint(index, sf::Vector2f((float)vertexes[index].x, (float)vertexes[index].y));
	}

	shape.setFillColor(sf::Color(fillColor));
	shape.setOutlineColor(sf::Color(fillColor));

	m_target.draw(shape);
}