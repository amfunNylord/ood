#include "RectangleDrawingStrategy.h"

void RectangleDrawingStrategy::Draw(Canvas& canvas, IVisualObjectInfo objInfo)
{
	canvas.SetColor(objInfo.GetColor());

	canvas.MoveTo(objInfo.GetBounds()[0].x, objInfo.GetBounds()[0].y);
	canvas.LineTo(objInfo.GetBounds()[0].x + objInfo.GetBounds()[1].x, objInfo.GetBounds()[0].y);
	canvas.LineTo(objInfo.GetBounds()[0].x + objInfo.GetBounds()[1].x, objInfo.GetBounds()[0].y + objInfo.GetBounds()[1].y);
	canvas.LineTo(objInfo.GetBounds()[0].x, objInfo.GetBounds()[0].y + objInfo.GetBounds()[1].y);
	canvas.LineTo(objInfo.GetBounds()[0].x, objInfo.GetBounds()[0].y);

	sf::RectangleShape rectangle(sf::Vector2f(float(objInfo.GetBounds()[1].x), float(objInfo.GetBounds()[1].y)));
	rectangle.setFillColor(objInfo.GetColor());
	rectangle.setPosition(float(objInfo.GetBounds()[0].x), float(objInfo.GetBounds()[0].y));
	canvas.GetWindow().draw(rectangle);
}