#pragma once
#include <iosfwd>
#include <string>
#include <vector>

#include "geom.h"
#include "cow.h"
#include "tile.h"

class Image
{
public:
	/**
     * Конструирует изображение заданного размера. Если размеры не являются положительными,
     * выбрасывает исключение std::out_of_range.
     */
	explicit Image(Size size, uint32_t color = 0xFFFFFFFF);

	// Возвращает размер изображения в пикселях.
	Size GetSize() const noexcept;

	/**
     * Возвращает «цвет» пикселя в указанных координатах.Если координаты выходят за пределы
     * изображения, возвращает «пробел».
     */
	uint32_t GetPixel(Point p) const noexcept;

	/**
     * Задаёт «цвет» пикселя в указанных координатах. Если координаты выходят за пределы изображения
     * действие игнорируется.
     */
	void SetPixel(Point p, uint32_t color);

private:
	int m_width;
	int m_height;
	std::vector<std::vector<CoW<Tile>>> m_tiles;
};

/**
 * Выводит в поток out изображение в виде символов.
 */
void Print(const Image& img, std::ostream& out);
