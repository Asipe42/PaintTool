#pragma once

struct Color 
{
    float r;
    float g;
    float b;
    float a;

    Color(float r = 0, float g = 0, float b = 0, float a = 1.0f)
        : r(r), g(g), b(b), a(a) {
    }

    /** Helper */
    static Color White(float a = 1.0f) { return Color(1.0f, 1.0f, 1.0f, a); }
    static Color Black(float a = 1.0f) { return Color(0.0f, 0.0f, 0.0f, a); }
    static Color Red(float a = 1.0f)   { return Color(1.0f, 0.0f, 0.0f, a); }
    static Color Green(float a = 1.0f) { return Color(0.0f, 1.0f, 0.0f, a); }
    static Color Blue(float a = 1.0f)  { return Color(0.0f, 0.0f, 1.0f, a); }
};