#include "ShapeType.h"
#include <sstream>

shape::ShapeType::ShapeType(std::string shapeType, std::string color)
	: m_shapeType(shapeType)
	, m_color(color)
{
}

std::string shape::ShapeType::GetType() const
{
	return m_shapeType;
}

std::string shape::ShapeType::ToString() const
{
	std::ostringstream strm;
	AppendProperties(strm);
	return strm.str();
}

std::string shape::ShapeType::GetColor() const
{
	return m_color;
}

void shape::ShapeType::SetColor(std::string newColor)
{
	m_color = newColor;
}
