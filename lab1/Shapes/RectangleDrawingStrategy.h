#pragma once
#include "IDrawingStrategy.h"

class RectangleDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(Canvas& canvas, IVisualObjectInfo objInfo) override;
};