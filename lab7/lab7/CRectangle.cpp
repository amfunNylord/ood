#include "CRectangle.h"

CRectangle::CRectangle(double left, double top, double width, double height)
	: m_frame({ left, top, width, height })
{
}

void CRectangle::Draw(ICanvas& canvas) const
{
	std::vector<PointD> vertexes = {
		{ m_frame.left, m_frame.top },
		{ m_frame.left + m_frame.width, m_frame.top },
		{ m_frame.left + m_frame.width, m_frame.top + m_frame.height },
		{ m_frame.left, m_frame.top + m_frame.height }
	};

	if (GetLineStyle()->IsEnabled())
	{
		canvas.DrawLine(vertexes[0], vertexes[1], GetLineStyle()->GetColor().value(), GetLineStyle()->GetThickness());
		canvas.DrawLine(vertexes[1], vertexes[2], GetLineStyle()->GetColor().value(), GetLineStyle()->GetThickness());
		canvas.DrawLine(vertexes[2], vertexes[3], GetLineStyle()->GetColor().value(), GetLineStyle()->GetThickness());
		canvas.DrawLine(vertexes[3], vertexes[0], GetLineStyle()->GetColor().value(), GetLineStyle()->GetThickness());
	}

	if (GetFillStyle()->IsEnabled() && GetFillStyle()->GetColor() != std::nullopt)
	{
		canvas.FillPolygon(vertexes, GetFillStyle()->GetColor().value());
	}
}

std::optional<RectD> CRectangle::GetFrame()
{
	return m_frame;
}

void CRectangle::SetFrame(const RectD& rect)
{
	m_frame = rect;
}
