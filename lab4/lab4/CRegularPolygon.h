#pragma once
#include <memory>
#include "CShape.h"
#include "CCanvas.h"

class CRegularPolygon : public CShape
{
public:
	CRegularPolygon(Color color, unsigned vertexCount, Point center, double radius);
	void Draw(ICanvas* canvas) override;

private:
	unsigned m_vertexCount;
	Point m_center;
	double m_radius;
};
