#include "TextDrawingStrategy.h"

void TextDrawingStrategy::Draw(Canvas& canvas, IVisualObjectInfo objInfo)
{
	canvas.SetColor(objInfo.GetColor());
	canvas.DrawText(objInfo.GetBounds()[0].x, objInfo.GetBounds()[0].y, objInfo.GetBounds()[1].x, objInfo.GetText());

}