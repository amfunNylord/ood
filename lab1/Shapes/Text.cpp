#include "Text.h"
#include <iostream>
#include "TextDrawingStrategy.h"

shape::Text::Text(std::string type, std::string color, double left, double top, double size, std::string text)
	: ShapeType(type, color, std::make_shared<TextDrawingStrategy>())
	, m_left(left)
	, m_top(top)
	, m_size(size)
	, m_text(text)
{
}

void shape::Text::Draw(Canvas& canvas)
{
	std::vector<Point> bounds;
	bounds.emplace_back(Point(m_left, m_top));
	bounds.emplace_back(Point(m_size, m_size));
	IVisualObjectInfo objInfo(this->GetColor(), bounds, m_text);
	m_drawingStrategy->Draw(canvas, objInfo);
}

shape::Text::~Text()
{
}

void shape::Text::AppendProperties(std::ostream& strm) const
{
	strm << m_left << ' ' << m_top << ' ' << m_size << ' ' << m_text << std::endl;
}

void shape::Text::MoveShape(double dx, double dy)
{
	m_left += dx;
	m_top += dy;
}
