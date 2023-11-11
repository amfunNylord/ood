#pragma once
#include "IImage.h"
#include "History.h"

class CImage : public IImage
{
public:
	CImage(CHistory& history, int m_width, int m_height, std::string path);

	std::string GetPath() const override;
	int GetWidth() const override;
	int GetHeight() const override;
	void Resize(int width, int height) override;

private:
	int m_width;
	int m_height;
	std::string m_path;
	CHistory& m_history;
};