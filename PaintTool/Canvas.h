#pragma once
#include "Brush.h"
#include <vector>

class Canvas
{
public:
	Canvas();
	~Canvas();

/** Mouse Event */
public:
	void OnMouseDown(double x, double y);
	void OnMouseMove(double x, double y);
	void OnMouseUp();

/** Drawing */
public:
	void Draw() const;
	void Clear();

private:
	std::vector<std::pair<float, float>> Points;
	bool bIsDrawing = false;

	float bgColor[3] = { 1.0f, 1.0f, 1.0f };

/** Brush */
public:
	void SetBrush(const Brush& brush);
	const Brush& GetBrush() const;

private:
	Brush* CurrentBrush = nullptr;
};