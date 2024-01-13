#include "CRectangle.h"
#include <SFML/Graphics.hpp>

CRectangle::CRectangle(Color color, Point leftTop, Point rightBottom)
	: CShape(color)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
}

void CRectangle::Draw(ICanvas* canvas)
{
	canvas->SetColor(this->GetColor());
	Point rightTop(m_rightBottom.x, m_leftTop.y);
	Point leftBottom(m_leftTop.x, m_rightBottom.y);

	canvas->DrawLine(m_leftTop, rightTop);
	canvas->DrawLine(rightTop, m_rightBottom);
	canvas->DrawLine(m_rightBottom, leftBottom);
	canvas->DrawLine(leftBottom, m_leftTop);
}
