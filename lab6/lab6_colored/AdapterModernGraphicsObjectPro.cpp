#include "AdapterModernGraphicsObjectPro.h"

const modern_graphics_lib_pro::CPoint DEFAULT_START_POINT = { 0, 0 };
const modern_graphics_lib_pro::CRGBAColor DEFAULT_COLOR = { 0.0, 0.0, 0.0, 1.0 };

CAdapterModernGraphicsObjectPro::CAdapterModernGraphicsObjectPro(modern_graphics_lib_pro::CModernGraphicsRenderer& renderer)
	: m_renderer(renderer)
	, m_currPoint(DEFAULT_START_POINT)
	, m_color(DEFAULT_COLOR)
{
}

void CAdapterModernGraphicsObjectPro::MoveTo(int x, int y)
{
	m_currPoint = { x, y };
}

void CAdapterModernGraphicsObjectPro::LineTo(int x, int y)
{
	m_renderer.DrawLine(m_currPoint, {x, y}, m_color);
	this->MoveTo(x, y);
}

void CAdapterModernGraphicsObjectPro::SetColor(uint32_t rgbColor)
{
	m_color.r = ((rgbColor >> 16) & 0xFF) / 255.0f;
	m_color.g = ((rgbColor >> 8) & 0xFF) / 255.0f; 
	m_color.b = (rgbColor & 0xFF) / 255.0f;
}
