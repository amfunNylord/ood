#include "CShapeFactory.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CEllipse.h"
#include "CRegularPolygon.h"

#include <stdexcept>
#include <sstream>

// разбить на отдельные функции

std::unique_ptr<CRectangle> CreateRectangle(const Color& color, std::istringstream& input)
{
	double xLeftTop, yLeftTop, xRightBottom, yRightBottom;
	input >> xLeftTop >> yLeftTop >> xRightBottom >> yRightBottom;
	return std::make_unique<CRectangle>(color, Point(xLeftTop, yLeftTop), Point(xRightBottom, yRightBottom));
}

std::unique_ptr<CTriangle> CreateTriangle(const Color& color, std::istringstream& input)
{
	double xVertex1, yVertex1, xVertex2, yVertex2, xVertex3, yVertex3;
	input >> xVertex1 >> yVertex1 >> xVertex2 >> yVertex2 >> xVertex3 >> yVertex3;
	return std::make_unique<CTriangle>(color, Point(xVertex1, yVertex1), Point(xVertex2, yVertex2), Point(xVertex3, yVertex3));
}

std::unique_ptr<CEllipse> CreateEllipse(const Color& color, std::istringstream& input)
{
	double xCenter, yCenter, horizontalRadius, verticalRadius;
	input >> xCenter >> yCenter >> horizontalRadius >> verticalRadius;
	return std::make_unique<CEllipse>(color, Point(xCenter, yCenter), horizontalRadius, verticalRadius);
}

std::unique_ptr<CRegularPolygon> CreateRegularPolygon(const Color& color, std::istringstream& input)
{
	unsigned vertexCount;
	double xCenter, yCenter, radius;
	input >> vertexCount >> xCenter >> yCenter >> radius;
	return std::make_unique<CRegularPolygon>(color, vertexCount, Point(xCenter, yCenter), radius);
}

std::unique_ptr<CShape> CreateSpecificShape(const std::string& shapeType, const Color& color, std::istringstream& input)
{
	if (shapeType == "rectangle")
	{
		return CreateRectangle(color, input);
	}
	else if (shapeType == "triangle")
	{
		return CreateTriangle(color, input);
	}
	else if (shapeType == "ellipse")
	{
		return CreateEllipse(color, input);
	}
	else if (shapeType == "polygon")
	{
		return CreateRegularPolygon(color, input);
	}
	else
	{
		throw std::invalid_argument("Unknown shape type");
	}
}

std::unique_ptr<CShape> CShapeFactory::CreateShape(const std::string& description)
{
	std::string shapeStr, colorStr;
	std::istringstream input(description);

	input >> shapeStr >> colorStr;

	Color color = ConvertStrColor(colorStr);

	std::unique_ptr<CShape> shape = CreateSpecificShape(shapeStr, color, input);

	return shape;
}