#include "Triangle.h"
#include <iostream>
#include "TriangleDrawingStrategy.h"

shape::Triangle::Triangle(std::string type, std::string color, double x1, double y1, double x2, double y2, double x3, double y3)
	: ShapeType(type, color, std::make_shared<TriangleDrawingStrategy>())
	, m_x1(x1)
	, m_y1(y1)
	, m_x2(x2)
	, m_y2(y2)
	, m_x3(x3)
	, m_y3(y3)
{
}

void shape::Triangle::Draw(Canvas& canvas)
{
	std::vector<Point> bounds;
	bounds.emplace_back(Point(m_x1, m_y1));
	bounds.emplace_back(Point(m_x2, m_y2));
	bounds.emplace_back(Point(m_x3, m_y3));
	IVisualObjectInfo objInfo(this->GetColor(), bounds);
	m_drawingStrategy->Draw(canvas, objInfo);
}

shape::Triangle::~Triangle()
{
}

void shape::Triangle::AppendProperties(std::ostream& strm) const
{
	strm << m_x1 << ' ' << m_y1 << ' ' << m_x2 << ' ' << m_y2 << ' ' << m_x3 << ' ' <<  m_y3 << ' ' << std::endl;
}

void shape::Triangle::MoveShape(double dx, double dy)
{
	m_x1 += dx;
	m_x2 += dx;
	m_x3 += dx;
	m_y1 += dy;
	m_y2 += dy;
	m_y3 += dy;
}
