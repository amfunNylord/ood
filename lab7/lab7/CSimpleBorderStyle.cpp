#include "CSimpleBorderStyle.h"

CSimpleBorderStyle::CSimpleBorderStyle()
	: m_enable(false)
	, m_color(0)
	, m_thickness(0.0)
{
}

void CSimpleBorderStyle::SetThickness(double thickness)
{
	m_thickness = thickness;
}

std::optional<double> CSimpleBorderStyle::GetThickness() const
{
	return m_thickness;
}

bool CSimpleBorderStyle::IsEnabled() const
{
	return m_enable;
}

void CSimpleBorderStyle::Enable()
{
	if (!m_enable)
	{
		m_enable = true;
	}
}

void CSimpleBorderStyle::Disable()
{
	if (m_enable)
	{
		m_enable = false;
	}
}

std::optional<RGBAColor> CSimpleBorderStyle::GetColor() const
{
	return m_color;
}

void CSimpleBorderStyle::SetColor(RGBAColor color)
{
	m_color = color;
}

