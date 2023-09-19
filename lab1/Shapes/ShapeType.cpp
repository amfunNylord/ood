#include "ShapeType.h"
#include <sstream>

shape::ShapeType::ShapeType(std::string shapeType)
	: m_shapeType(shapeType)
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