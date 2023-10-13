#pragma once
#include "IDrawingStrategy.h"

class LineDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(CCanvas& canvas, VisualObjectInfo objInfo) override;
};
