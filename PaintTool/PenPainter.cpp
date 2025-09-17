#include "PenPainter.h"

#include <GLFW/glfw3.h>

PenPainter::PenPainter()
{
}

PenPainter::~PenPainter()
{
}

void PenPainter::Draw(float x, float y)
{
    float half = size * 0.5f;

    glColor4f(color.r, color.g, color.b, opacity);
   
    glBegin(GL_QUADS);
    glVertex2f(x - half, y - half);
    glVertex2f(x + half, y - half);
    glVertex2f(x + half, y + half);
    glVertex2f(x - half, y + half);
    glEnd();
}