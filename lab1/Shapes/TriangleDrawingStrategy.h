#pragma once
#include "IDrawingStrategy.h"

class TriangleDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(Canvas& canvas, IVisualObjectInfo objInfo) override;
};
