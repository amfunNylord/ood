#pragma once
#include "IDrawingStrategy.h"

class EllipseDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(Canvas& canvas, IVisualObjectInfo objInfo) override;

};