#include "Shape.h"
#include <sstream>

shape::Shape::Shape(std::string id, std::unique_ptr<ShapeType> shapeType)
	: m_id(id)
	, m_shapeType(std::move(shapeType))
{
}

shape::Shape::Shape(const Shape& other)
	: m_id(other.m_id)
	, m_shapeType(other.m_shapeType->Clone())
{
}

std::unique_ptr<shape::ShapeType> shape::Shape::GetShapeType() const
{
	return m_shapeType->Clone();
}

std::string shape::Shape::GetId() const
{
	return m_id;
}

std::string shape::Shape::ToString() const
{
	std::ostringstream strm;
	strm << m_shapeType->GetType() << ' ' << GetId() << ' ' << GetShapeType()->GetColor() << ' ';
	m_shapeType.get()->AppendProperties(strm);
	return strm.str();
}

void shape::Shape::ChangeShape(std::string shapeId, std::string shapeTypeStr, std::unique_ptr<ShapeType> shapeType)
{
	m_shapeType = std::move(shapeType);
}