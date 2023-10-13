#pragma once
#include "IDrawingStrategy.h"

class TriangleDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(CCanvas& canvas, VisualObjectInfo objInfo) override;
};
