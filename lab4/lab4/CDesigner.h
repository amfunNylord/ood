#pragma once
#include <iosfwd>
#include <memory>

class CPictureDraft;

class IShapeFactory;

class CDesigner
{
public:
	CDesigner(std::unique_ptr<IShapeFactory>&& factory); // передавать ссылку
	~CDesigner(); // исли не используем то не писать
	CPictureDraft CreateDraft(std::istream& inputData);

private:
	std::unique_ptr<IShapeFactory> m_factory;
};
