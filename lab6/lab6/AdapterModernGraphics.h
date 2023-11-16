#pragma once
#include "modern_graphics_lib.h"
#include "graphics_lib.h"

class CAdapterModernGraphics : public graphics_lib::ICanvas
{
public:
	CAdapterModernGraphics(modern_graphics_lib::CModernGraphicsRenderer& renderer);
	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;

private:
	modern_graphics_lib::CModernGraphicsRenderer& m_renderer;
	modern_graphics_lib::CPoint m_currPoint;
};
