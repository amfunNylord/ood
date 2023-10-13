#include "Circle.h"
#include <iostream>
#include "EllipseDrawingStrategy.h"

shape::Circle::Circle(std::string type, std::string color, double x, double y, double r)
	: ShapeType(type, color, std::make_shared<EllipseDrawingStrategy>())
	, m_x(x)
	, m_y(y)
	, m_r(r)
{
}

void shape::Circle::Draw(CCanvas& canvas)
{
	std::vector<SPoint> bounds;
	bounds.emplace_back(SPoint(m_x, m_y));
	bounds.emplace_back(SPoint(m_r, m_r));
	VisualObjectInfo objInfo(this->GetColor(), bounds);
	m_drawingStrategy->Draw(canvas, objInfo);
}

shape::Circle::~Circle()
{
}

void shape::Circle::AppendProperties(std::ostream& strm) const
{
	strm << m_x << ' ' << m_y << ' ' << m_r << std::endl;
}

void shape::Circle::MoveShape(double dx, double dy)
{
	m_x += dx;
	m_y += dy;
}
