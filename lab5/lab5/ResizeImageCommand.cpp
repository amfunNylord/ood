#include "ResizeImageCommand.h"

CResizeImageCommand::CResizeImageCommand(int& width, int& height, int newWidth, int newHeight)
	: m_width(width)
	, m_height(height)
	, m_newWidth(newWidth)
	, m_newHeight(newHeight)
{
}

void CResizeImageCommand::DoExecute()
{
	std::swap(m_newWidth, m_width);
	std::swap(m_newHeight, m_height);
}

void CResizeImageCommand::DoUnexecute()
{
	std::swap(m_newWidth, m_width);
	std::swap(m_newHeight, m_height);
}
