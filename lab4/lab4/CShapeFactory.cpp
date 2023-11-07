#include "CShapeFactory.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CEllipse.h"
#include "CRegularPolygon.h"

#include <stdexcept>
#include <sstream>
// разбить на отдельные функции
std::unique_ptr<CShape> CShapeFactory::CreateShape(const std::string& description)
{
	m_countOfCreatedShapes++;
	std::unique_ptr<CShape> shape;

	std::string shapeStr, colorStr;

	std::istringstream input(description);
	input >> shapeStr >> colorStr;

	Color color = ConvertStrColor(colorStr);

	if (shapeStr == "rectangle")
	{
		double xLeftTop, yLeftTop, xRightBottom, yRightBottom;
		input >> xLeftTop >> yLeftTop >> xRightBottom >> yRightBottom;
		shape = std::make_unique<CRectangle>(color, Point(xLeftTop, yLeftTop), Point(xRightBottom, yRightBottom), m_countOfCreatedShapes);
	}
	else if (shapeStr == "triangle")
	{
		double xVertex1, yVertex1, xVertex2, yVertex2, xVertex3, yVertex3;
		input >> xVertex1 >> yVertex1 >> xVertex2 >> yVertex2 >> xVertex3 >> yVertex3;
		shape = std::make_unique<CTriangle>(color, Point(xVertex1, yVertex1), Point(xVertex2, yVertex2), Point(xVertex3, yVertex3), m_countOfCreatedShapes);
	}
	else if (shapeStr == "ellipse")
	{
		double xCenter, yCenter, horizontalRadius, verticalRadius;
		input >> xCenter >> yCenter >> horizontalRadius >> verticalRadius;
		shape = std::make_unique<CEllipse>(color, Point(xCenter, yCenter), horizontalRadius, verticalRadius, m_countOfCreatedShapes);
	}
	else if (shapeStr == "polygon")
	{
		unsigned vertexCount;
		double xCenter, yCenter, radius;
		input >> vertexCount >> xCenter >> yCenter >> radius;
		shape = std::make_unique<CRegularPolygon>(color, vertexCount, Point(xCenter, yCenter), radius, m_countOfCreatedShapes);
	}
	else
	{
		throw std::invalid_argument("Unknown shape type");
	}
	return shape;
}
