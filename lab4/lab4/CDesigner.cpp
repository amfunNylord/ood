#include "CDesigner.h"
#include "IShapeFactory.h"
#include "CPictureDraft.h"
#include <iostream>

using namespace std;

CDesigner::CDesigner(std::unique_ptr<IShapeFactory>&& factory)
	: m_factory(std::forward<std::unique_ptr<IShapeFactory>>(factory))
{
}

CDesigner::~CDesigner()
{
}

CPictureDraft CDesigner::CreateDraft(std::istream& inputData)
{
	CPictureDraft draft;
	string line;
	while (getline(inputData, line))
	{
		draft.AddShape(m_factory.get()->CreateShape(line));
	}
	return draft;
}
