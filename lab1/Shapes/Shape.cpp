#include "Shape.h"
#include <sstream>

const std::string CIRCLE_TYPE = "circle",
				  RECTANGLE_TYPE = "rectangle",
				  TRIANGLE_TYPE = "triangle",
				  LINE_TYPE = "line",
				  TEXT_TYPE = "text";

shape::Shape::Shape(std::string id, std::string color, std::string type)
	: m_id(id)
	, m_color(color)
	, m_type(type)
{
}

void shape::Shape::MoveShape()
{
}

std::string shape::Shape::GetColor() const
{
	return m_color;
}

void shape::Shape::SetColor(std::string newColor)
{
	m_color = newColor;
}

std::string shape::Shape::GetType() const
{
	return m_type;
}

std::string shape::Shape::GetId() const
{
	return m_id;
}

void shape::Shape::ChangeShape(std::string shapeId, std::string shapeType, std::istream& args)
{
	if (shapeType == CIRCLE_TYPE)
	{
		double x, y, r;
		args >> x >> y >> r;
		

		return;
	}
	else if (shapeType == RECTANGLE_TYPE)
	{
		double left, top, width, height;
		args >> left >> top >> width >> height;
	
		return;
	}
	else if (shapeType == TRIANGLE_TYPE)
	{
		double x1, y1, x2, y2, x3, y3;
		args >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

		return;
	}
	else if (shapeType == LINE_TYPE)
	{
		double x1, y1, x2, y2;
		args >> x1 >> y1 >> x2 >> y2;

		return;
	}
	else if (shapeType == TEXT_TYPE)
	{
		double left, top, size;
		args >> left >> top >> size;
		std::string textContents;
		getline(args, textContents);
		textContents.erase(textContents.begin());

		return;
	}
}

void shape::Shape::DrawShape()
{
}

shape::Shape::~Shape()
{
}

std::string shape::Shape::ToString() const
{
	std::ostringstream strm;
	strm << GetType() << ' ' << GetId() << ' ' << GetColor() << ' ';
	AppendProperties(strm);
	return strm.str();
}
