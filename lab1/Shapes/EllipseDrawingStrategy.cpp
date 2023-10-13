#include "EllipseDrawingStrategy.h"

void EllipseDrawingStrategy::Draw(CCanvas& canvas, VisualObjectInfo objInfo)
{
	canvas.SetColor(objInfo.GetColor());
	canvas.DrawEllipse(objInfo.GetBounds()[0].x, objInfo.GetBounds()[0].y, objInfo.GetBounds()[1].x, objInfo.GetBounds()[1].y);
}