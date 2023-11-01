#include "CRegularPolygon.h"
#include <numbers>

CRegularPolygon::CRegularPolygon(Color color, unsigned vertexCount, Point center, double radius, size_t index)
	: CShape(color, index)
	, m_vertexCount(vertexCount)
	, m_center(center)
	, m_radius(radius)
{
}

void CRegularPolygon::Draw(ICanvas* canvas)
{
	canvas->SetColor(this->GetColor());
	std::vector<Point> vertexContainer;
	for (unsigned int i = 0; i < m_vertexCount; i++)
	{
		double angle = 2 * std::numbers::pi * i / m_vertexCount;
		vertexContainer.emplace_back(Point(m_radius * cos(angle) + m_center.x, m_radius * sin(angle) + m_center.y));
	}
	for (size_t i = 1; i < vertexContainer.size(); i++)
	{
		canvas->DrawLine(vertexContainer[i - 1], vertexContainer[i]);
	}
	canvas->DrawLine(vertexContainer[vertexContainer.size() - 1], vertexContainer[0]);
}

/* Нахождение всех вершин
  int i, N = 12, X = 50, Y = 50, R = 20;
  double angle;
  String s = "";
  for (i = 0; i < N; i++)
  {
    angle = 2*M_PI*i/N;
    s += "x = " + String(R*cos(angle)+X) + "   y = " + String(R*sin(angle)+Y) + "\n";
  }
  ShowMessage(s);
*/