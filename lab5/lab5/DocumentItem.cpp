#include "stdafx.h"
#include "DocumentItem.h"

CDocumentItem::CDocumentItem(const std::shared_ptr<IImage>& imagePtr)
	: CConstDocumentItem(imagePtr)
	, m_imagePtr(imagePtr)
{
}

CDocumentItem::CDocumentItem(const std::shared_ptr<IParagraph>& paragraphPtr)
	: CConstDocumentItem(paragraphPtr)
	, m_paragraphPtr(paragraphPtr)
{
}

std::shared_ptr<IImage> CDocumentItem::GetImage()
{
	return m_imagePtr;
}

std::shared_ptr<IParagraph> CDocumentItem::GetParagraph()
{
	return m_paragraphPtr;
}
