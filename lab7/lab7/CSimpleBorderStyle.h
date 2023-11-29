#pragma once
#include "IBorderStyle.h"
class CSimpleBorderStyle : public IBorderStyle
{
public:
	CSimpleBorderStyle();

	void SetThickness(double thickness) override;
	std::optional<double> GetThickness() const override;
	
	bool IsEnabled() const override;
	void Enable() override;
	void Disable() override;
	std::optional<RGBAColor> GetColor() const override;
	void SetColor(RGBAColor color) override;

private:
	bool m_enable;
	RGBAColor m_color;
	double m_thickness;
};
