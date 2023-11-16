#include "AdapterModernGraphics.h"

const modern_graphics_lib::CPoint DEFAULT_START_POINT = { 0, 0 };

CAdapterModernGraphics::CAdapterModernGraphics(modern_graphics_lib::CModernGraphicsRenderer& renderer)
	: m_renderer(renderer)
	, m_currPoint(DEFAULT_START_POINT)
{
}

void CAdapterModernGraphics::MoveTo(int x, int y)
{
	m_currPoint = modern_graphics_lib::CPoint(x, y);
}

void CAdapterModernGraphics::LineTo(int x, int y)
{
	m_renderer.DrawLine(m_currPoint, { x, y });
	this->MoveTo(x, y);
}
