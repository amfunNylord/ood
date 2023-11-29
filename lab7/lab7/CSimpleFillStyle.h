#pragma once
#include "IStyle.h"

class CSimpleFillStyle : public IStyle
{
public:
	CSimpleFillStyle();

	bool IsEnabled() const override;
	void Enable() override;
	void Disable() override;
	std::optional<RGBAColor> GetColor() const override;
	void SetColor(RGBAColor color) override;

private:
	bool m_enable;
	RGBAColor m_color;
};
