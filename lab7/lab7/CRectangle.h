#pragma once
#include "CShape.h"

class CRectangle : public CShape
{
public:
	CRectangle(double left, double top, double width, double height);
	void Draw(ICanvas& canvas) const override final;
	std::optional<RectD> GetFrame() override;
	void SetFrame(const RectD& rect) override;

private:
	RectD m_frame;
};
