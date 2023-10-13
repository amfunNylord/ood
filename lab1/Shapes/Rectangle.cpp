#include "Rectangle.h"
#include <iostream>
#include "RectangleDrawingStrategy.h"

shape::Rectangle::Rectangle(std::string type, std::string color, double left, double top, double width, double height)
	: ShapeType(type, color, std::make_shared<RectangleDrawingStrategy>())
	, m_left(left)
	, m_top(top)
	, m_width(width)
	, m_height(height)
{
}

void shape::Rectangle::Draw(CCanvas& canvas)
{
	std::vector<SPoint> bounds;
	bounds.emplace_back(SPoint(m_left, m_top));
	bounds.emplace_back(SPoint(m_width, m_height));
	VisualObjectInfo objInfo(this->GetColor(), bounds);
	m_drawingStrategy->Draw(canvas, objInfo);
}

shape::Rectangle::~Rectangle()
{
}

void shape::Rectangle::MoveShape(double dx, double dy)
{
	m_left += dx;
	m_top += dy;
}

void shape::Rectangle::AppendProperties(std::ostream& strm) const
{
	strm << m_left << ' ' << m_top << ' ' << m_width << ' '<< m_height << std::endl;
}
