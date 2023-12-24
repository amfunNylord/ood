#pragma once
#include "ICanvas.h"
#include <SFML/Graphics/RenderWindow.hpp>

class CCanvas : public ICanvas
{
public:
	CCanvas(sf::RenderTarget& window);

	void DrawLine(PointD start, PointD end, RGBAColor color, std::optional<double> thickness) override;

	void DrawEllipse(const PointD center, double horizontalRadius, double verticalRadius,
		std::optional<RGBAColor> borderColor, std::optional<RGBAColor> fillColor,
		std::optional<double> thickness) override;

	void FillPolygon(const std::vector<PointD> vertexes, RGBAColor fillColor) override;

private:
	sf::RenderTarget& m_target;
};
