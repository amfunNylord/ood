#pragma once
#include <string>
#include <memory>
#include "IDrawingStrategy.h"

namespace shape
{
	class ShapeType
	{
	public:
		ShapeType(std::string shapeType, std::string color, std::shared_ptr<IDrawingStrategy>&& drawingStrategy);
		std::string GetType() const;
		std::string ToString() const;
		std::string GetColor() const;
		virtual void MoveShape(double dx, double dy) = 0;
		void SetColor(std::string newColor);
		void SetDrawingStrategy(std::shared_ptr<IDrawingStrategy>&& drawingStrategy);
		virtual void Draw(Canvas& canvas) = 0;
		virtual void AppendProperties(std::ostream& strm) const = 0;

	protected:
		std::shared_ptr<IDrawingStrategy> m_drawingStrategy;
	private:
		std::string m_color;
		std::string m_shapeType;
	};
} // namespace shape