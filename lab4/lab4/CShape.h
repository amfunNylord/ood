#pragma once
#include <string>
#include "ICanvas.h"

class CShape
{
public:
	CShape(Color color);
	virtual ~CShape() = default;

	Color GetColor();

	virtual void Draw(ICanvas* canvas) = 0;

private:
	Color m_color;
};
