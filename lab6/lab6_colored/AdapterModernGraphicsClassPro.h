#pragma once
#include "modern_graphics_lib_pro.h"
#include "graphics_lib_pro.h"

class CAdapterModernGraphicsClassPro : modern_graphics_lib_pro::CModernGraphicsRenderer, public graphics_lib_pro::ICanvas
{
public:
	CAdapterModernGraphicsClassPro(std::ostream& output);
	~CAdapterModernGraphicsClassPro();
	
	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;
	void SetColor(uint32_t rgbColor) override;

private:
	modern_graphics_lib_pro::CPoint m_currPoint;
	modern_graphics_lib_pro::CRGBAColor m_color;
};
