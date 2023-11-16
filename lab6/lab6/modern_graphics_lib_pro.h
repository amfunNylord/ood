#pragma once
#include <iostream>
// Пространство имен обновленной современной графической библиотеки (недоступно для изменения)
namespace modern_graphics_lib_pro
{
class CPoint
{
public:
	CPoint(int x, int y)
		: x(x)
		, y(y)
	{
	}

	int x;
	int y;
};

// Цвет в формате RGBA, каждый компонент принимает значения от 0.0f до 1.0f
class CRGBAColor
{
public:
	CRGBAColor(float r, float g, float b, float a)
		: r(r)
		, g(g)
		, b(b)
		, a(a)
	{
	}
	float r, g, b, a;
};

// Класс для современного рисования графики
class CModernGraphicsRenderer
{
public:
	CModernGraphicsRenderer(std::ostream& strm)
		: m_out(strm)
	{
	}

	~CModernGraphicsRenderer()
	{
		// Реализация остается без изменения
	}

	// Этот метод должен быть вызван в начале рисования
	void BeginDraw()
	{
		// Реализация остается без изменения
	}

	// Выполняет рисование линии
	void DrawLine(const CPoint& start, const CPoint& end, const CRGBAColor& color)
	{
		// TODO: выводит в output инструкцию для рисования линии в виде
		// <line fromX="3" fromY="5" toX="5" toY="17">
		//   <color r="0.35" g="0.47" b="1.0" a="1.0" />
		// </line>
		// Можно вызывать только между BeginDraw() и EndDraw()
	}

	// Этот метод должен быть вызван в конце рисования
	void EndDraw()
	{
		// Реализация остается без изменения
	}

private:
	std::ostream& m_out;
	bool m_drawing = false;
};
} // namespace modern_graphics_lib_pro