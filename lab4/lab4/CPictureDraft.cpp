#include "CPictureDraft.h"

bool CPictureDraft::IsEmpty() const
{
	return m_shapes.empty();
}

void CPictureDraft::AddShape(std::unique_ptr<CShape>&& shape)
{
	m_shapes.push_back(move(shape));
}

size_t CPictureDraft::GetShapeCount() const
{
	return m_shapes.size();
}

const std::unique_ptr<CShape>& CPictureDraft::GetShape(size_t index) const
{
	return m_shapes.at(index);
}

CPictureDraft::CPictureDraft()
{
}
