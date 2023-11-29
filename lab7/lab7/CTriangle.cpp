#include "CTriangle.h"
#include <vector>

CTriangle::CTriangle(PointD vertex1, PointD vertex2, PointD vertex3)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

void CTriangle::Draw(ICanvas& canvas) const
{
	std::vector<PointD> vertexes = { m_vertex1, m_vertex2, m_vertex3 };

	if (GetLineStyle()->IsEnabled())
	{
		canvas.DrawLine(m_vertex1, m_vertex2, GetLineStyle()->GetColor().value(), GetLineStyle()->GetThickness());
		canvas.DrawLine(m_vertex2, m_vertex3, GetLineStyle()->GetColor().value(), GetLineStyle()->GetThickness());
		canvas.DrawLine(m_vertex3, m_vertex1, GetLineStyle()->GetColor().value(), GetLineStyle()->GetThickness());
	}

	if (GetFillStyle()->IsEnabled())
	{
		canvas.FillPolygon(vertexes, GetFillStyle()->GetColor().value());
	}
}

std::optional<RectD> CTriangle::GetFrame()
{
	double maxX = std::max({ m_vertex1.x, m_vertex2.x, m_vertex3.x });
	double minX = std::min({ m_vertex1.x, m_vertex2.x, m_vertex3.x });
	double maxY = std::max({ m_vertex1.y, m_vertex2.y, m_vertex3.y });
	double minY = std::min({ m_vertex1.y, m_vertex2.y, m_vertex3.y });

	return RectD(minX, minY, maxX - minX, maxY - minY);
}

void CTriangle::SetFrame(const RectD& rect)
{
	std::vector<PointD*> vertexes = { &m_vertex1, &m_vertex2, &m_vertex3 };

	std::optional<RectD> currentFrame = GetFrame();
	double coefX = rect.width / currentFrame.value().width;
	double coefY = rect.height / currentFrame.value().height;

	for (const auto& vertex : vertexes)
	{
		*vertex = {
			(vertex->x - currentFrame.value().left) * coefX + rect.left,
			(vertex->y - currentFrame.value().top) * coefY + rect.top
		};
	}
}
