#pragma once
#include <array>

class Brush
{
public:
    Brush(float size, float hardness, std::array<float, 3> color, float opacity);
    ~Brush();

    void SetSize(float size) { Size = size; }
    float GetSize() const { return Size; }

    void SetColor(const std::array<float, 3>& color) { Color = color; }
    std::array<float, 3> GetColor() const { return Color; }

    void SetOpacity(float opacity) { Opacity = opacity; }
    float GetOpacity() const { return Opacity; }

protected:
    float Size;
    std::array<float, 3> Color;
    float Opacity;
}; 