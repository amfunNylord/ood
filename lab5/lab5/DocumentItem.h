#pragma once
#include "ConstDocumentItem.h"

class CDocumentItem : public CConstDocumentItem
{
public:
	CDocumentItem(const std::shared_ptr<IImage>& imagePtr);
	CDocumentItem(const std::shared_ptr<IParagraph>& paragraphPtr);
	// Возвращает указатель на изображение, либо nullptr, если элемент не является изображением
	std::shared_ptr<IImage> GetImage();
	// Возвращает указатель на параграф, либо nullptr, если элемент не является параграфом
	std::shared_ptr<IParagraph> GetParagraph();

private:
	std::shared_ptr<IImage> m_imagePtr = nullptr;
	std::shared_ptr<IParagraph> m_paragraphPtr = nullptr;
};
