#pragma once
#include <memory>
#include "CCanvas.h"
#include "CShape.h"

class CTriangle : public CShape
{
public:
	CTriangle(Color color, Point vertex1, Point vertex2, Point vertex3, size_t index);
	void Draw(ICanvas* canvas) override;

private:
	Point m_vertex1;
	Point m_vertex2;
	Point m_vertex3;
};
