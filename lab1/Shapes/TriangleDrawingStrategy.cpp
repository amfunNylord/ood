#include "TriangleDrawingStrategy.h"

void TriangleDrawingStrategy::Draw(Canvas& canvas, IVisualObjectInfo objInfo)
{
	canvas.SetColor(objInfo.GetColor());

	sf::ConvexShape convex;

	convex.setPointCount(3);

	convex.setPoint(0, sf::Vector2f(float(objInfo.GetBounds()[0].x), float(objInfo.GetBounds()[0].y)));
	convex.setPoint(1, sf::Vector2f(float(objInfo.GetBounds()[1].x), float(objInfo.GetBounds()[1].y)));
	convex.setPoint(2, sf::Vector2f(float(objInfo.GetBounds()[2].x), float(objInfo.GetBounds()[2].y)));

	convex.setFillColor(objInfo.GetColor());

	canvas.GetWindow().draw(convex);
}
