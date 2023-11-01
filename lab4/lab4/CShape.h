#pragma once
#include <string>
#include "ICanvas.h"

class CShape
{
public:
	CShape(Color color, size_t index);
	virtual ~CShape();

	size_t GetIndex();
	Color GetColor();

	virtual void Draw(ICanvas* canvas) = 0;


private:
	size_t m_index;
	Color m_color;
};
