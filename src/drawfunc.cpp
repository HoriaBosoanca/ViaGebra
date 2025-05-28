#include "drawfunc.h"
#include <functional>
#include "raylib.h"
#include "main.h"

void drawFunc(std::function<float(float)> func) {
	float prevX = -100.0, prevY = func(-100.0f);
	for (float i = -100.0f; i <= 100.0f; i += 0.01f) {
		drawLine({i, func(i)}, {prevX, prevY}, 5.0, RED);
		prevX = i;
		prevY = func(i);
	}
}

// range (0, 0) -> (100, 100)
void drawLine(Vector2 p1, Vector2 p2, const float thickness, const Color color) {
	p1.x = (p1.x / 200.0f +0.5f) * X_SCREEN;
	p1.y = (-p1.y / 200.0f +0.5f) * Y_SCREEN;
	p2.x = (p2.x / 200.0f +0.5f) * X_SCREEN;
	p2.y = (-p2.y / 200.0f +0.5f) * Y_SCREEN;
	DrawLineEx(p1, p2, thickness, color);
}