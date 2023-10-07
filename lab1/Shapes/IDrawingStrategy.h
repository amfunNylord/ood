#pragma once
#include "Canvas.h"
#include "IVisualObjectInfo.h"

class IDrawingStrategy
{
public:
	virtual void Draw(Canvas& canvas, IVisualObjectInfo objInfo) = 0;
	virtual ~IDrawingStrategy(){};
};