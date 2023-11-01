#pragma once
#include <string>
#include "Point.h"
#include "Color.h"

class ICanvas
{
public:
	virtual void SetColor(Color c) = 0;
	virtual void DrawLine(Point from, Point to) = 0;
	virtual void DrawEllipse(Point center, double horizontalRadius, double verticalRadius) = 0;
};