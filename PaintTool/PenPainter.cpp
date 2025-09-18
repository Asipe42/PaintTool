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
    glColor4f(color.r, color.g, color.b, opacity);
    glPointSize(size);
   
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}