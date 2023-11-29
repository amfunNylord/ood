#pragma once
#include "CShape.h"

class CTriangle : public CShape
{
public:
	CTriangle(PointD vertex1, PointD vertex2, PointD vertex3);
	void Draw(ICanvas& canvas) const final;
	std::optional<RectD> GetFrame() override;
	void SetFrame(const RectD& rect) override;

private:
	PointD m_vertex1;
	PointD m_vertex2;
	PointD m_vertex3;
};
