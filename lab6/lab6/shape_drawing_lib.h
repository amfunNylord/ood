#pragma once
#include "graphics_lib.h"

// ѕространство имен библиотеки дл€ рисовани€ фигур (использует graphics_lib)
//  од библиотеки недоступен дл€ изменени€
namespace shape_drawing_lib
{
struct Point
{
	int x;
	int y;
};

// »нтерфейс объектов, которые могут быть нарисованы на холсте из graphics_lib
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
		// TODO: написать код конструктора
	}

	void Draw(graphics_lib::ICanvas& canvas) const override
	{
		// TODO: написать код рисовани€ треугольника на холсте
		canvas.MoveTo(m_p1.x, m_p1.y);
		canvas.LineTo(m_p2.x, m_p2.y);
		canvas.LineTo(m_p3.x, m_p3.y);
		canvas.LineTo(m_p1.x, m_p1.y);
	}

private:
	// TODO: дописать приватную часть
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
		// TODO: написать код конструктора
	}

	void Draw(graphics_lib::ICanvas& canvas) const override
	{
		// TODO: написать код рисовани€ пр€моугольника на холсте
		canvas.MoveTo(m_leftTop.x, m_leftTop.y);
		canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y);
		canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y + m_height);
		canvas.LineTo(m_leftTop.x, m_leftTop.y + m_height);
		canvas.LineTo(m_leftTop.x, m_leftTop.y);
	}

private:
	// TODO: дописать приватную часть
	Point m_leftTop;
	int m_width, m_height;
};

// ’удожник, способный рисовать ICanvasDrawable-объекты на ICanvas
class CCanvasPainter
{
public:
	CCanvasPainter(graphics_lib::ICanvas& canvas)
		: m_canvas(canvas)
	{
		// TODO: дописать конструктор класса
	}
	void Draw(const ICanvasDrawable& drawable)
	{
		// TODO: дописать код рисовани€ ICanvasDrawable на canvas, переданном в конструктор
		drawable.Draw(m_canvas);
	}

private:
	// TODO: дописать приватную часть
	graphics_lib::ICanvas& m_canvas;
};
} // namespace shape_drawing_lib