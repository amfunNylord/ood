#pragma once
#include "IShapeFactory.h"

class CShapeFactory : public IShapeFactory
{
public:
	std::unique_ptr<CShape> CreateShape(const std::string& description) override;

private:
	size_t m_countOfCreatedShapes = 0;
};
