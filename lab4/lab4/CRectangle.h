#pragma once
#include <memory>
#include "CShape.h"
#include "CCanvas.h"

class CRectangle : public CShape
{
public:
	CRectangle(Color color, Point leftTop, Point rightBottom, size_t index);
	void Draw(ICanvas* canvas) override;
private:
	Point m_leftTop;
	Point m_rightBottom;
};
