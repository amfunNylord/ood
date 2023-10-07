#include "LineDrawingStrategy.h"

void LineDrawingStrategy::Draw(Canvas& canvas, IVisualObjectInfo objInfo)
{
	canvas.SetColor(objInfo.GetColor());
	
	canvas.MoveTo(objInfo.GetBounds()[0].x, objInfo.GetBounds()[0].y);
	canvas.LineTo(objInfo.GetBounds()[1].x, objInfo.GetBounds()[1].y);
}
