#include "Text.h"
#include <iostream>

shape::Text::Text(std::string type, double left, double top, double size, std::string text)
	: ShapeType(type)
	, m_left(left)
	, m_top(top)
	, m_size(size)
	, m_text(text)
{
}

shape::Text::~Text()
{
}

void shape::Text::AppendProperties(std::ostream& strm) const
{
	strm << m_left << ' ' << m_top << ' ' << m_size << ' ' << m_text << std::endl;
}
