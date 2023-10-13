#pragma once
#include "CCanvas.h"
#include "VisualObjectInfo.h"

class IDrawingStrategy
{
public:
	virtual void Draw(CCanvas& canvas, VisualObjectInfo objInfo) = 0;
	virtual ~IDrawingStrategy(){};
};