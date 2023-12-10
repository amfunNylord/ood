#include "drawer.h"
#include <cassert>
#include <cstdlib>

namespace
{

int Sign(int value)
{
	return (0 < value) - (value < 0);
}

/**
 * Рисует крутой отрезок (для которого |to.y - from.x| >= |to.x - from.x|).
 */
void DrawSteepLine(Image& image, Point from, Point to, uint32_t color)
{
	const int deltaX = std::abs(to.x - from.x);
	const int deltaY = std::abs(to.y - from.y);

	assert(deltaY >= deltaX);

	if (from.y > to.y)
	{ // Крутые отрезки рисуем сверху вниз.
		std::swap(from, to);
	}

	const int stepX = Sign(to.x - from.x); // Шаг по оси X (-1, 0 или 1).
	const int errorThreshold = deltaY + 1; // Порог ошибки вычисления координаты X.
	const int deltaErr = deltaX + 1; // Шаг накопления ошибки.

	// Когда начальнное значение ошибки начинается не с 0, а с deltaErr/2, отрезок получается красивее.
	int error = deltaErr / 2;

	for (Point p = from; p.y <= to.y; ++p.y)
	{
		image.SetPixel({ p.x, p.y }, color);
		assert((p.y != to.y) || (p.x == to.x));

		error += deltaErr; // Накапливаем ошибку вычисления координаты X.

		if (error >= errorThreshold)
		{ // Если вышли за пределы текущей координаты X
			p.x += stepX; // Смещаемся к следующей координате X
			error -= errorThreshold; // Сбрасываем ошибку
		}
	}
}

/**
 * Рисует пологий отрезок (для которого |to.y - from.x| >= |to.y - from.y|).
 */
void DrawSlopeLine(Image& image, Point from, Point to, uint32_t color)
{
	const int deltaX = std::abs(to.x - from.x);
	const int deltaY = std::abs(to.y - from.y);

	assert(deltaX >= deltaY);

	if (from.x > to.x)
	{ // Пологие отрезки рисуем слева направо.
		std::swap(from, to);
	}

	// Пологие отрезки рисуются по аналогии с крутыми.

	const int stepY = Sign(to.y - from.y);
	const int errorThreshold = deltaX + 1;
	const int deltaErr = deltaY + 1;

	int error = deltaErr / 2;

	for (Point p = from; p.x <= to.x; ++p.x)
	{
		image.SetPixel({ p.x, p.y }, color);
		assert((p.x != to.x) || (p.y == to.y));

		error += deltaErr;

		if (error >= errorThreshold)
		{
			p.y += stepY;
			error -= errorThreshold;
		}
	}
}

} // namespace

/**
 * Рисует отрезок прямой линии между точками from и to цветом color на изображении Image.
 *
 * Для рисования используется алгоритм Брезенхэма.
 * (https://ru.wikipedia.org/wiki/Алгоритм_Брезенхэма)
 */
void DrawLine(Image& image, Point from, Point to, uint32_t color)
{
	const int deltaX = std::abs(to.x - from.x);
	const int deltaY = std::abs(to.y - from.y);

	if (deltaY > deltaX)
	{ // Отрезок крутой.
		DrawSteepLine(image, from, to, color);
	}
	else
	{ // Отрезок пологий.
		DrawSlopeLine(image, from, to, color);
	}
}

void DrawCircle(Image& image, Point center, int radius, uint32_t color)
{
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	while (y >= x)
	{
		image.SetPixel({ center.x + x, center.y + y }, color);
		image.SetPixel({ center.x + x, center.y - y }, color);
		image.SetPixel({ center.x - x, center.y + y }, color);
		image.SetPixel({ center.x - x, center.y - y }, color);
		image.SetPixel({ center.x + y, center.y + x }, color);
		image.SetPixel({ center.x + y, center.y - x }, color);
		image.SetPixel({ center.x - y, center.y + x }, color);
		image.SetPixel({ center.x - y, center.y - x }, color);
		error = 2 * (delta + y) - 1;
		if ((delta < 0) && (error <= 0))
		{
			delta += 2 * ++x + 1;
			continue;
		}
		if ((delta > 0) && (error > 0))
		{
			delta -= 2 * --y + 1;
			continue;
		}
		delta += 2 * (++x - --y);
	}
}

void FillCircle(Image& image, Point center, int radius, uint32_t color)
{
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	while (y >= 0)
	{
		DrawLine(image, { center.x + x, center.y + y }, { center.x - x, center.y + y }, color);
		DrawLine(image, { center.x + x, center.y - y }, { center.x - x, center.y - y }, color);
		error = 2 * (delta + y) - 1;
		if ((delta < 0) && (error <= 0))
		{
			delta += 2 * ++x + 1;
			continue;
		}
		error = 2 * (delta - x) - 1;
		if ((delta > 0) && (error > 0))
		{
			delta += 1 - 2 * --y;
			continue;
		}
		x++;
		delta += 2 * (x - y);
		y--;
	}
}
