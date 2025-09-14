#pragma once

class Canvas
{
public:
	Canvas();

	void Clear();
	void Draw() const;

private:
	float bgColor[3] = { 1.0f, 1.0f, 1.0f };
};