#pragma once
#include "shape_drawing_lib.h"
#include "modern_graphics_lib.h"
#include "AdapterModernGraphics.h"

// Пространство имен приложения (доступно для модификации)
namespace app
{
void PaintPicture(shape_drawing_lib::CCanvasPainter& painter)
{
	using namespace shape_drawing_lib;

	CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
	CRectangle rectangle({ 30, 40 }, 18, 24);

	// TODO: нарисовать прямоугольник и треугольник при помощи painter

	painter.Draw(triangle);
	painter.Draw(rectangle);
}

void PaintPictureOnCanvas()
{
	graphics_lib::CCanvas simpleCanvas;
	shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
	PaintPicture(painter);
}

void PaintPictureOnModernGraphicsRenderer()
{
	modern_graphics_lib::CModernGraphicsRenderer renderer(std::cout);
	(void)&renderer; // устраняем предупреждение о неиспользуемой переменной

	// TODO: при помощи существующей функции PaintPicture() нарисовать
	// картину на renderer
	// Подсказка: используйте паттерн "Адаптер"
	CAdapterModernGraphics adapter(renderer);
	renderer.BeginDraw();
	shape_drawing_lib::CCanvasPainter painter(adapter);
	PaintPicture(painter);
	renderer.EndDraw();
}
} // namespace app