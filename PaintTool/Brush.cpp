#include "Brush.h"

Brush::Brush(float size, float hardness, std::array<float, 3> color, float opacity)
	: Size(size), Color(color), Opacity(opacity)
{
}

Brush::~Brush()
{
}
