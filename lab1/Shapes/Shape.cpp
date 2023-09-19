#include "Shape.h"
#include <sstream>

shape::Shape::Shape(std::string id, std::string color, std::shared_ptr<ShapeType> shapeType)
	: m_id(id)
	, m_color(color)
	, m_shapeType(shapeType)
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

std::string shape::Shape::GetId() const
{
	return m_id;
}

std::string shape::Shape::ToString() const
{
	std::ostringstream strm;
	strm << m_shapeType.get()->GetType() << ' ' << GetId() << ' ' << GetColor() << ' ';
	m_shapeType.get()->AppendProperties(strm);
	return strm.str();
}

void shape::Shape::ChangeShape(std::string shapeId, std::string shapeType, std::shared_ptr<ShapeType> shape)
{
	this->m_shapeType = shape;
}

void shape::Shape::DrawShape()
{
}