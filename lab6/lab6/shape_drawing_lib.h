#pragma once
#include "graphics_lib.h"

// ������������ ���� ���������� ��� ��������� ����� (���������� graphics_lib)
// ��� ���������� ���������� ��� ���������
namespace shape_drawing_lib
{
struct Point
{
	int x;
	int y;
};

// ��������� ��������, ������� ����� ���� ���������� �� ������ �� graphics_lib
class ICanvasDrawable
{
public:
	virtual void Draw(graphics_lib::ICanvas& canvas) const = 0;
	virtual ~ICanvasDrawable() = default;
};

class CTriangle : public ICanvasDrawable
{
public:
	CTriangle(const Point& p1, const Point& p2, const Point& p3)
		: m_p1(p1)
		, m_p2(p2)
		, m_p3(p3)
	{
		// TODO: �������� ��� ������������
	}

	void Draw(graphics_lib::ICanvas& canvas) const override
	{
		// TODO: �������� ��� ��������� ������������ �� ������
		canvas.MoveTo(m_p1.x, m_p1.y);
		canvas.LineTo(m_p2.x, m_p2.y);
		canvas.LineTo(m_p3.x, m_p3.y);
		canvas.LineTo(m_p1.x, m_p1.y);
	}

private:
	// TODO: �������� ��������� �����
	Point m_p1, m_p2, m_p3;
};

class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(const Point& leftTop, int width, int height)
		: m_leftTop(leftTop)
		, m_width(width)
		, m_height(height)
	{
		// TODO: �������� ��� ������������
	}

	void Draw(graphics_lib::ICanvas& canvas) const override
	{
		// TODO: �������� ��� ��������� �������������� �� ������
		canvas.MoveTo(m_leftTop.x, m_leftTop.y);
		canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y);
		canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y + m_height);
		canvas.LineTo(m_leftTop.x, m_leftTop.y + m_height);
		canvas.LineTo(m_leftTop.x, m_leftTop.y);
	}

private:
	// TODO: �������� ��������� �����
	Point m_leftTop;
	int m_width, m_height;
};

// ��������, ��������� �������� ICanvasDrawable-������� �� ICanvas
class CCanvasPainter
{
public:
	CCanvasPainter(graphics_lib::ICanvas& canvas)
		: m_canvas(canvas)
	{
		// TODO: �������� ����������� ������
	}
	void Draw(const ICanvasDrawable& drawable)
	{
		// TODO: �������� ��� ��������� ICanvasDrawable �� canvas, ���������� � �����������
		drawable.Draw(m_canvas);
	}

private:
	// TODO: �������� ��������� �����
	graphics_lib::ICanvas& m_canvas;
};
} // namespace shape_drawing_lib