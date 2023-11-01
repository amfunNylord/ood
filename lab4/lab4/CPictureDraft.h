#pragma once
#include <string>
#include "CShape.h"
#include <memory>
#include <vector>

class CPictureDraft
{

public:
	typedef std::vector<std::unique_ptr<CShape>> Storage;

	CPictureDraft();

	bool IsEmpty() const;

	void AddShape(std::unique_ptr<CShape>&& shape);

	size_t GetShapeCount() const;
	const std::unique_ptr<CShape>& GetShape(size_t index) const;

private:
	Storage m_shapes;
};
