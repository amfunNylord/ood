#pragma once
#include "CShape.h"
#include "CCanvas.h"

class CEllipse : public CShape
{
public:
	CEllipse(Color color, Point center, double horizontalRadius, double verticalRadius, size_t index);
	void Draw(ICanvas* canvas) override;

private:
	Point m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};
