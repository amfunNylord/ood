#include "CEllipse.h"

CEllipse::CEllipse(Color color, Point center, double horizontalRadius, double verticalRadius)
	: CShape(color)
	, m_center(center)
	, m_horizontalRadius(horizontalRadius)
	, m_verticalRadius(verticalRadius)
{
}

void CEllipse::Draw(ICanvas* canvas)
{
	canvas->SetColor(this->GetColor());
	canvas->DrawEllipse(m_center, m_horizontalRadius, m_verticalRadius);
}
