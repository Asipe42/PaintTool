#pragma once
#include "Painter.h"

class BrushPainter : public Painter
{
public:
    BrushPainter();
    ~BrushPainter() override;

    void Draw(float x, float y) override;
}; 