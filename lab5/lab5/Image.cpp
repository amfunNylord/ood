#include "stdafx.h"
#include "Image.h"
#include "ResizeImageCommand.h"

CImage::CImage(CHistory& history, int width, int height, std::string path)
	: m_history(history)
	, m_width(width)
	, m_height(height)
	, m_path(path)
{
}

std::string CImage::GetPath() const 
{
	return m_path;
}

int CImage::GetWidth() const 
{
	return m_width;
}

int CImage::GetHeight() const 
{
	return m_height;
}

void CImage::Resize(int width, int height)
{
	m_history.AddAndExecuteCommand(std::make_unique<CResizeImageCommand>(m_width, m_height, width, height));
}
