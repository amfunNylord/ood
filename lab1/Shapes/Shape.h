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
		Shape(std::string id, std::shared_ptr<ShapeType> type);
		~Shape() = default;

		void ChangeShape(std::string shapeId, std::string shapeTypeStr, std::shared_ptr<ShapeType> shapeType);

		std::shared_ptr<ShapeType> GetShapeType() const;
		std::string GetId() const;
		std::string ToString() const;

	private:
		std::string m_id;
		std::shared_ptr<ShapeType> m_shapeType;
	};

} // namespace shape