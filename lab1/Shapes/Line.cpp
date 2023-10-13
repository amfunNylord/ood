#include "Line.h"
#include <iostream>
#include "LineDrawingStrategy.h"

shape::Line::Line(std::string type, std::string color, double x1, double y1, double x2, double y2)
	: ShapeType(type, color, std::make_shared<LineDrawingStrategy>())
	, m_x1(x1)
	, m_y1(y1)
	, m_x2(x2)
	, m_y2(y2)
{
}

void shape::Line::Draw(CCanvas& canvas)
{
	std::vector<SPoint> bounds;
	bounds.emplace_back(SPoint(m_x1, m_y1));
	bounds.emplace_back(SPoint(m_x2, m_y2));
	VisualObjectInfo objInfo(this->GetColor(), bounds);
	m_drawingStrategy->Draw(canvas, objInfo);
}

shape::Line::~Line()
{
}

void shape::Line::AppendProperties(std::ostream& strm) const
{
	strm << m_x1 << ' ' << m_y1 << ' ' << m_x2 << ' ' << m_y2 << std::endl;
}

void shape::Line::MoveShape(double dx, double dy)
{
	m_x1 = m_x1 + dx;
	m_x2 = m_x2 + dx;
	m_y1 = m_y1 + dy;
	m_y2 = m_y2 + dy;
}

