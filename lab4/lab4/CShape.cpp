#include "CShape.h"

CShape::CShape(Color color, size_t index)
	: m_color(color)
	, m_index(index)
{
}

CShape::~CShape()
{
}

size_t CShape::GetIndex()
{
	return m_index;
}

Color CShape::GetColor()
{
	return m_color;
}
