#include "CDesigner.h"
#include "IShapeFactory.h"
#include "CPictureDraft.h"
#include <iostream>

using namespace std;

CDesigner::CDesigner(IShapeFactory& factory)
	: m_factory(factory)
{
}

CPictureDraft CDesigner::CreateDraft(std::istream& inputData)
{
	CPictureDraft draft;
	string line;
	while (getline(inputData, line))
	{
		draft.AddShape(m_factory.CreateShape(line));
	}
	return draft;
}
