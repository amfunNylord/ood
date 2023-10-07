#pragma once
#include <SFML/Graphics/Color.hpp>
#include <string>

namespace gfx
{
	class ICanvas
	{
	public:
		virtual void SetColor(sf::Color c) = 0;
		virtual void MoveTo(double x, double y) = 0;
		virtual void LineTo(double x, double y) = 0;
		virtual void DrawEllipse(double cx, double cy, double rx, double ry) = 0;
		virtual void DrawText(double left, double top, double fontSize, const std::string& text) = 0;
	};
}