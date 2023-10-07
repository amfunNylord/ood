#pragma once
#include "IDrawingStrategy.h"

class LineDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(Canvas& canvas, IVisualObjectInfo objInfo) override;
};
