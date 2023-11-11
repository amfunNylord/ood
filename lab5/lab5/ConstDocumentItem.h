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

	// ���������� ��������� �� ����������� �����������, ���� nullptr,
	// ���� ������� �� �������� ������������
	std::shared_ptr<const IImage> GetImage()const;
	// ���������� ��������� �� ����������� ��������, ���� nullptr, ���� ������� �� �������� ����������
	std::shared_ptr<const IParagraph> GetParagraph()const;
	virtual ~CConstDocumentItem() = default;

private:
	std::shared_ptr<const IImage> m_imagePtr = nullptr;
	std::shared_ptr<const IParagraph> m_paragraphPtr = nullptr;
};
