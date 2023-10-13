#include "LineDrawingStrategy.h"

void LineDrawingStrategy::Draw(CCanvas& canvas, VisualObjectInfo objInfo)
{
	canvas.SetColor(objInfo.GetColor());
	
	canvas.MoveTo(objInfo.GetBounds()[0].x, objInfo.GetBounds()[0].y);
	canvas.LineTo(objInfo.GetBounds()[1].x, objInfo.GetBounds()[1].y);
}
