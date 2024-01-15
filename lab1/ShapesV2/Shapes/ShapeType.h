#pragma once
#include <string>
#include <memory>
#include "ICanvas.h"

namespace shape
{
	class ShapeType
	{
	public:
		ShapeType(std::string shapeType, std::string color);
		std::string GetType() const;
		std::string ToString() const;
		virtual void MoveShape(double dx, double dy) = 0;
		virtual void Draw(gfx::ICanvas* canvas) = 0;
		virtual void AppendProperties(std::ostream& strm) const = 0;

		std::string GetColor() const;
		void SetColor(std::string newColor);

	private:
		std::string m_shapeType;
		std::string m_color;
	};
} // namespace shape