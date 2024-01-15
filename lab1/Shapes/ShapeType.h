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
		virtual ~ShapeType() = default;

		std::string GetType() const;
		std::string ToString() const;
		std::string GetColor() const;
		void SetColor(std::string newColor);

		virtual void MoveShape(double dx, double dy) = 0;
		virtual void Draw(gfx::ICanvas* canvas) = 0;
		virtual void AppendProperties(std::ostream& strm) const = 0;
		virtual std::unique_ptr<ShapeType> Clone() const = 0;

	private:
		std::string m_shapeType;
		std::string m_color;
	};
} // namespace shape