#pragma once
#include <cstdint>
#include <iostream>

namespace graphics_lib_pro
{
// Холст для рисования
class ICanvas
{
public:
	// Установка цвета в формате 0xRRGGBB
	virtual void SetColor(uint32_t rgbColor) = 0;
	virtual void MoveTo(int x, int y) = 0;
	virtual void LineTo(int x, int y) = 0;
	virtual ~ICanvas() = default;
};

// Реализация холста для рисования
class CCanvas : public ICanvas
{
public:
	void SetColor(uint32_t rgbColor) override
	{
		// TODO: вывести в output цвет в виде строки SetColor (#RRGGBB)
		//std::cout << "SetColor " << rgbColor << std::endl;
	}
	void MoveTo(int x, int y) override
	{
		// Реализация остается без изменения
	}
	void LineTo(int x, int y) override
	{
		// Реализация остается без изменения
	}
};
} // namespace graphics_lib_pro