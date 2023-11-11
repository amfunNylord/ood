#pragma once
#include "ConstDocumentItem.h"

class CDocumentItem : public CConstDocumentItem
{
public:
	CDocumentItem(const std::shared_ptr<IImage>& imagePtr);
	CDocumentItem(const std::shared_ptr<IParagraph>& paragraphPtr);
	// ���������� ��������� �� �����������, ���� nullptr, ���� ������� �� �������� ������������
	std::shared_ptr<IImage> GetImage();
	// ���������� ��������� �� ��������, ���� nullptr, ���� ������� �� �������� ����������
	std::shared_ptr<IParagraph> GetParagraph();

private:
	std::shared_ptr<IImage> m_imagePtr = nullptr;
	std::shared_ptr<IParagraph> m_paragraphPtr = nullptr;
};
