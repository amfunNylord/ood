#include "image.h"
#include <cassert>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <iostream> // -


/**
 * ������������ ����������� ��������� �������. ���� ������� �� �������� ��������������,
 * ����������� ���������� std::out_of_range.
 */
Image::Image(Size size, char color)
{
	/* ���������� ����������� �������������� */
	if (size.height <= 0 || size.width <= 0)
	{
		throw std::out_of_range("Size must be positive");
	}
	m_width = size.width;
	m_height = size.height;

	int tileCountX = (m_width + Tile::SIZE - 1) / Tile::SIZE;
	int tileCountY = (m_height + Tile::SIZE - 1) / Tile::SIZE;

	CoW<Tile> defaultTile = CoW<Tile>(color);

	m_tiles.resize(tileCountY);

	for (int i = 0; i < tileCountY; i++)
	{
		m_tiles[i].resize(tileCountX);
		for (int j = 0; j < tileCountX; j++)
		{
			m_tiles[i][j] = defaultTile;
		}
	}
}

// ���������� ������ ����������� � ��������.
Size Image::GetSize() const noexcept
{
	/* ���������� ����� ��������������. */
	return { m_width, m_height };
}

/**
 * ���������� ����� ������� � ��������� �����������.���� ���������� ������� �� �������
 * �����������, ���������� �������.
 */
char Image::GetPixel(Point p) const noexcept
{
	/* ���������� ����� ��������������. */
	if (p.x < 0 || p.y < 0 || p.x >= m_width || p.y >= m_height)
	{
		return ' ';
	}
	int tilePosY = p.y / Tile::SIZE;
	int tilePosX = p.x / Tile::SIZE;

	int posInTileY = p.y % Tile::SIZE;
	int posInTileX = p.x % Tile::SIZE;

	return m_tiles[tilePosY][tilePosX]->GetPixel({posInTileX, posInTileY});
}

/**
 * ����� ����� ������� � ��������� �����������. ���� ���������� ������� �� ������� �����������
 * �������� ������������.
 */
void Image::SetPixel(Point p, char color)
{
	/* ���������� ����� ��������������. */
	if (IsPointInSize(p, {m_width, m_height}))
	{
		int tilePosY = p.y / Tile::SIZE;
		int tilePosX = p.x / Tile::SIZE;

		int posInTileY = p.y % Tile::SIZE;
		int posInTileX = p.x % Tile::SIZE;
		m_tiles[tilePosY][tilePosX].Write([posInTileX, posInTileY, color](auto& tile) { tile.SetPixel({ posInTileX, posInTileY }, color); });
	}
}

/**
 * ������� � ����� out ����������� � ���� ��������.
 */
void Print(const Image& img, std::ostream& out)
{
	const auto size = img.GetSize();
	for (int y = 0; y < size.height; ++y)
	{
		for (int x = 0; x < size.width; ++x)
		{
			out.put(img.GetPixel({ x, y }));
		}
		out.put('\n');
	}
}

/**
 * ��������� ����������� �� pixels. ����� ����������� ����������� ��������� \n.
 * ������� �������� ������������ �� ���������� ��������� ������ � ����� ������� �����.
 */
Image LoadImage(const std::string& pixels)
{
	std::istringstream s(pixels);
	Size size;
	std::string line;
	while (std::getline(s, line))
	{
		size.width = std::max(size.width, static_cast<int>(line.length()));
		++size.height;
	}

	Image img(size);

	s = std::istringstream(pixels);
	for (int y = 0; y < size.height; ++y)
	{
		if (!std::getline(s, line))
			break;

		int x = 0;
		for (char ch : line)
		{
			img.SetPixel({ x++, y }, ch);
		}
	}

	return img;
}
