#pragma once
#include "CShape.h"
#include "CCanvas.h"

class CEllipse : public CShape
{
public:
	CEllipse(Color color, Point center, double horizontalRadius, double verticalRadius);
	void Draw(ICanvas* canvas) override;

private:
	Point m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};
