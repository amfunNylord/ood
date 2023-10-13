#pragma once
#include "IDrawingStrategy.h"

class EllipseDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(CCanvas& canvas, VisualObjectInfo objInfo) override;

};