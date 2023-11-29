#include "CEllipse.h"

CEllipse::CEllipse(PointD center, double verticalRadius, double horizontalRadius)
	: m_center(center)
	, m_verticalRadius(verticalRadius)
	, m_horizontalRadius(horizontalRadius)
{
}

void CEllipse::Draw(ICanvas& canvas) const
{
	canvas.DrawEllipse(m_center, m_horizontalRadius, m_verticalRadius, GetLineStyle()->GetColor(), GetFillStyle()->GetColor(), GetLineStyle()->GetThickness());
}

std::optional<RectD> CEllipse::GetFrame()
{
	double left = m_center.x - m_horizontalRadius;
	double top = m_center.y - m_verticalRadius;
	double width = m_horizontalRadius * 2;
	double height = m_verticalRadius * 2;
	return RectD(left, top, width, height);
}

void CEllipse::SetFrame(const RectD& rect)
{
	m_horizontalRadius = rect.width / 2;
	m_verticalRadius = rect.height / 2;
	m_center.x = rect.left + m_horizontalRadius;
	m_center.y = rect.top + m_verticalRadius;
}
