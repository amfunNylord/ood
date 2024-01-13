#include "CShape.h"

CShape::CShape(Color color)
	: m_color(color)
{
}

Color CShape::GetColor()
{
	return m_color;
}
