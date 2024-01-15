#pragma once
#include <memory>
#include <string>
#include "ShapeType.h"
#include <iostream>

namespace shape
{
	class Shape
	{
	public:
		Shape(std::string id, std::unique_ptr<ShapeType> type);

		Shape(const Shape& other);

		void ChangeShape(std::string shapeId, std::string shapeTypeStr, std::unique_ptr<ShapeType> shapeType);
		std::unique_ptr<ShapeType> GetShapeType() const;
		std::string GetId() const;
		std::string ToString() const;

	private:
		std::string m_id;
		std::unique_ptr<ShapeType> m_shapeType;
	};

} // namespace shape