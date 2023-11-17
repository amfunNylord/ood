#pragma once
#include "modern_graphics_lib.h"
#include "graphics_lib.h"

class CAdapterModernGraphicsClass : modern_graphics_lib::CModernGraphicsRenderer, public graphics_lib::ICanvas
{
public:
	CAdapterModernGraphicsClass(std::ostream& output);
	~CAdapterModernGraphicsClass();

	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;

private:
	modern_graphics_lib::CPoint m_currPoint;
};
