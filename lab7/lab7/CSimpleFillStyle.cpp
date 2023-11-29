#include "CSimpleFillStyle.h"

CSimpleFillStyle::CSimpleFillStyle()
	: m_enable(false)
	, m_color(0)
{
}

bool CSimpleFillStyle::IsEnabled() const
{
	return m_enable;
}

void CSimpleFillStyle::Enable()
{
	if (!m_enable)
	{
		m_enable = true;
	}
}

void CSimpleFillStyle::Disable()
{
	if (m_enable)
	{
		m_enable = false;
	}
}

std::optional<RGBAColor> CSimpleFillStyle::GetColor() const
{
	return m_color;
}

void CSimpleFillStyle::SetColor(RGBAColor color)
{
	m_color = color;
}
