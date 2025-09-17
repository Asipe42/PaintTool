#pragma once
#include "Color.h"

class Painter
{
public:
	Painter();
	virtual ~Painter();

	void SetColor(const Color& color) { this->color = color; }
	void SetSize(float size) { this->size = size; }
	void SetOpacity(float opacity) { this->opacity = opacity; }

	Color GetColor() const { return color; }
	float GetSize() const { return size; }
	float GetOpacity() const { return opacity; }

	virtual void Draw(float x, float y) = 0;

protected:
	Color color;
	float size; 
	float opacity;
};