#pragma once
#include "CPictureDraft.h"

class CPainter
{
public:
	void DrawPicture(const CPictureDraft& draft, ICanvas* canvas);
};
