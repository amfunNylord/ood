#pragma once
#include <vector>
#include <memory>
#include "Shape.h"

namespace shape
{
	class Picture
	{
	public:
		void AddShape(std::shared_ptr<Shape> shape);
		void DeleteShape(std::string shapeId, std::ostream& output);
		void DrawPicture();
		void List(std::ostream& output);

		std::shared_ptr<shape::Shape> GetShape(std::string shapeId, std::ostream& output);

	private:
		std::vector<std::shared_ptr<Shape>> m_shapesVector;
	};
}