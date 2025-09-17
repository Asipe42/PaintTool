#pragma once
#include "Painter.h"

class PenPainter : public Painter
{
public:
	PenPainter();
	~PenPainter() override;

	void Draw(float x, float y) override;
};