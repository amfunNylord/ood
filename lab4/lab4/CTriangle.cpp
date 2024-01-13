#include "CTriangle.h"

CTriangle::CTriangle(Color color, Point vertex1, Point vertex2, Point vertex3)
	: CShape(color)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

void CTriangle::Draw(ICanvas* canvas)
{
	canvas->SetColor(this->GetColor());
	canvas->DrawLine(m_vertex1, m_vertex2);
	canvas->DrawLine(m_vertex2, m_vertex3);
	canvas->DrawLine(m_vertex3, m_vertex1);
}
