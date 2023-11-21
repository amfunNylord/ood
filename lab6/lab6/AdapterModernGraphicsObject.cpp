#include "AdapterModernGraphicsObject.h"

const modern_graphics_lib::CPoint DEFAULT_START_POINT = { 0, 0 };

CAdapterModernGraphicsObject::CAdapterModernGraphicsObject(modern_graphics_lib::CModernGraphicsRenderer& renderer)
	: m_renderer(renderer)
	, m_currPoint(DEFAULT_START_POINT)
{
}

void CAdapterModernGraphicsObject::MoveTo(int x, int y)
{
	m_currPoint = { x, y };
}

void CAdapterModernGraphicsObject::LineTo(int x, int y)
{
	m_renderer.DrawLine(m_currPoint, { x, y });
	MoveTo(x, y);
}
