#pragma once
#include "shape_drawing_lib.h"
#include "modern_graphics_lib.h"
#include "AdapterModernGraphicsObject.h"
#include "AdapterModernGraphicsClass.h"

// ������������ ���� ���������� (�������� ��� �����������)
namespace app
{
void PaintPicture(shape_drawing_lib::CCanvasPainter& painter)
{
	using namespace shape_drawing_lib;

	CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
	CRectangle rectangle({ 30, 40 }, 18, 24);

	// TODO: ���������� ������������� � ����������� ��� ������ painter

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
	(void)&renderer; // ��������� �������������� � �������������� ����������

	// TODO: ��� ������ ������������ ������� PaintPicture() ����������
	// ������� �� renderer
	// ���������: ����������� ������� "�������"
	std::cout << "Using object adapter" << std::endl;

	CAdapterModernGraphicsObject objectAdapter(renderer);
	renderer.BeginDraw();
	shape_drawing_lib::CCanvasPainter objectPainter(objectAdapter);
	PaintPicture(objectPainter);
	renderer.EndDraw();

	std::cout << "Using class adapter" << std::endl;

	// Class Adapter solution
	CAdapterModernGraphicsClass classAdapter(std::cout);
	shape_drawing_lib::CCanvasPainter classPainter(classAdapter);
	PaintPicture(classPainter);

}
} // namespace app