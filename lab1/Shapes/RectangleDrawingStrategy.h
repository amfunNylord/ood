#pragma once
#include "IDrawingStrategy.h"

class RectangleDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(CCanvas& canvas, VisualObjectInfo objInfo) override;
};