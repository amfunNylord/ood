#pragma once
#include "IDrawingStrategy.h"

class TextDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(Canvas& canvas, IVisualObjectInfo objInfo) override;
};