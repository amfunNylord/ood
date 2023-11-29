#pragma once
#include "CommonTypes.h"
#include <optional>

class IStyle
{
public:
	virtual bool IsEnabled() const = 0;
	virtual void Enable() = 0;
	virtual void Disable() = 0;
	virtual std::optional<RGBAColor> GetColor() const = 0;
	virtual void SetColor(RGBAColor color) = 0;
	virtual ~IStyle() = default;
};
