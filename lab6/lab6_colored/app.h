#pragma once
#include "shape_drawing_lib.h"
#include "modern_graphics_lib_pro.h"
#include "AdapterModernGraphicsObjectPro.h"
#include "AdapterModernGraphicsClassPro.h"

// Пространство имен приложения (доступно для модификации)
namespace app
{
void PaintPicture(shape_drawing_lib::CCanvasPainter& painter)
{
	using namespace shape_drawing_lib;

	CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 }, 0x33FF34);
	CRectangle rectangle({ 30, 40 }, 18, 24, 0x3D33FF);

	// TODO: нарисовать прямоугольник и треугольник при помощи painter
	painter.Draw(triangle);
	painter.Draw(rectangle);
}

void PaintPictureOnCanvas()
{
	graphics_lib_pro::CCanvas simpleCanvas;
	shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
	PaintPicture(painter);
}

void PaintPictureOnModernGraphicsRenderer()
{
	modern_graphics_lib_pro::CModernGraphicsRenderer renderer(std::cout);
	(void)&renderer; // устраняем предупреждение о неиспользуемой переменной

	// TODO: при помощи существующей функции PaintPicture() нарисовать
	// картину на renderer
	// Подсказка: используйте паттерн "Адаптер"
	std::cout << "Using object adapter" << std::endl;

	CAdapterModernGraphicsObjectPro objectAdapter(renderer);
	renderer.BeginDraw();
	shape_drawing_lib::CCanvasPainter objectPainter(objectAdapter);
	PaintPicture(objectPainter);
	renderer.EndDraw();

	std::cout << "Using class adapter" << std::endl;

	// Class Adapter solution
	CAdapterModernGraphicsClassPro classAdapter(std::cout);
	shape_drawing_lib::CCanvasPainter classPainter(classAdapter);
	PaintPicture(classPainter);

}
} // namespace app