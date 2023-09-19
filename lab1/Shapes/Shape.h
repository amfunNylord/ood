#pragma once
#include <memory>
#include <string>
#include "ShapeType.h"


namespace shape
{
	class Shape
	{
	public:
		Shape(std::string id, std::string color, std::shared_ptr<ShapeType> type);
		~Shape() = default;

		void MoveShape();
		void SetColor(std::string newColor);
		void ChangeShape(std::string shapeId, std::string shapeType, std::shared_ptr<ShapeType> m_shapeType);
		void DrawShape();

		std::string GetColor() const;
		std::string GetId() const;
		std::string ToString() const;

	private:
		std::string m_id;
		std::string m_color;
		std::shared_ptr<ShapeType> m_shapeType;
		//IDrawingStrategy m_drawingStrategy;
	};

} // namespace shape