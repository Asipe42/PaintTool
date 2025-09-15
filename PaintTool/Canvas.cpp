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

	if (!CurrentBrush)
	{
		return;
	}

	auto color = CurrentBrush->GetColor();
	glColor4f(color[0], color[1], color[2], CurrentBrush->GetOpacity());
	glPointSize(CurrentBrush->GetSize());

	glBegin(GL_POINTS);
	for (auto& p : Points)
		glVertex2f(p.first, p.second);
	glEnd();
}

void Canvas::Clear()
{
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

void Canvas::SetBrush(const Brush& brush)
{
	CurrentBrush = const_cast<Brush*>(&brush);
}

const Brush& Canvas::GetBrush() const
{
	return *CurrentBrush;
}