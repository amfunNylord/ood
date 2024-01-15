#pragma once
#include <vector>
#include <memory>
#include "Shape.h"

namespace shape
{
	class Picture
	{
	public:
		Picture() = default;

		Picture(const Picture& other);

		void AddShape(std::unique_ptr<Shape> shape);
		void DeleteShape(const std::string& shapeId, std::ostream& output);
		void List(std::ostream& output);

		std::unique_ptr<Shape> GetShape(const std::string& shapeId, std::ostream& output);

		const std::vector<std::unique_ptr<Shape>>& GetAllShapes() const;

	private:
		std::vector<std::unique_ptr<Shape>> m_shapesVector;
	};
}