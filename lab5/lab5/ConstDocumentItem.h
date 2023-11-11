#pragma once
#include <memory>
#include <string>
#include "IParagraph.h"
#include "IImage.h"

class CConstDocumentItem
{
public:
	CConstDocumentItem(const std::shared_ptr<const IImage>& imagePtr);
	CConstDocumentItem(const std::shared_ptr<const IParagraph>& paragraphPtr);

	// Возвращает указатель на константное изображение, либо nullptr,
	// если элемент не является изображением
	std::shared_ptr<const IImage> GetImage()const;
	// Возвращает указатель на константный параграф, либо nullptr, если элемент не является параграфом
	std::shared_ptr<const IParagraph> GetParagraph()const;
	virtual ~CConstDocumentItem() = default;

private:
	std::shared_ptr<const IImage> m_imagePtr = nullptr;
	std::shared_ptr<const IParagraph> m_paragraphPtr = nullptr;
};
