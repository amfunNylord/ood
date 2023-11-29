#pragma once
#include <cstdint>

typedef uint32_t RGBAColor;
template <typename T>
struct Rect
{
	T left;
	T top;
	T width;
	T height;
};
typedef Rect<double> RectD;

template <typename T>
struct Point
{
	T x;
	T y;
};
using PointD = Point<double>;