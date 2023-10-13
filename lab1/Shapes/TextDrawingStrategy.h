#pragma once
#include "IDrawingStrategy.h"

class TextDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(CCanvas& canvas, VisualObjectInfo objInfo) override;
};