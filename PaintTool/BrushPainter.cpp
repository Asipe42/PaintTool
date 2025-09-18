#include "BrushPainter.h"

#include <GLFW/glfw3.h>
#include <math.h>

BrushPainter::BrushPainter()
{
}

BrushPainter::~BrushPainter()
{
}

void BrushPainter::Draw(float x, float y)
{
    float radius = size * 0.5f;
    int segments = 64;

    glColor4f(color.r, color.g, color.b, opacity);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; i++) 
    {
        float angle = i * 2.0f * 3.1415926f / segments;
        float dx = cosf(angle) * radius;
        float dy = sinf(angle) * radius;
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}