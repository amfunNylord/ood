#pragma once
#include "CShape.h"

class CEllipse : public CShape
{
public:
	CEllipse(PointD center, double verticalRadius, double horizontalRadius);
	void Draw(ICanvas& canvas) const override final;
	std::optional<RectD> GetFrame() override;
	void SetFrame(const RectD& rect) override;

private:
	PointD m_center;
	double m_verticalRadius;
	double m_horizontalRadius;
};
