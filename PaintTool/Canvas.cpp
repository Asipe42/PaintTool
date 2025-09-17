#include "Canvas.h"
#include <GLFW/glfw3.h>

Canvas::Canvas()
{
	bgColor[0] = 1.0f;
	bgColor[1] = 1.0f;
	bgColor[2] = 1.0f;
}

Canvas::~Canvas()
{
}

void Canvas::Draw() const
{
	glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (!CurrentPainter)
	{
		return;
	}

	for (auto& p : Points)
	{
		CurrentPainter->Draw(p.first, p.second);
	}
}

void Canvas::Clear()
{
	Points.clear();
	glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Canvas::OnMouseDown(double x, double y)
{
	bIsDrawing = true;
	OnMouseMove(x, y);
}

void Canvas::OnMouseMove(double x, double y)
{
	if (!bIsDrawing) 
	{
		return;
	}

	int width, height;
	glfwGetWindowSize(glfwGetCurrentContext(), &width, &height);

	float ndcX = (x / width) * 2.0f - 1.0f;  // -1.0 ~ 1.0
	float ndcY = 1.0f - (y / height) * 2.0f; // -1.0 ~ 1.0

	Points.push_back({ ndcX, ndcY });
}

void Canvas::OnMouseUp()
{
	bIsDrawing = false;
}