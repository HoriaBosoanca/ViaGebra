#include "drawfunc.h"

#include <iostream>
#include <bits/ostream.tcc>

#include "raylib.h"
#include "main.h"

void drawFunc(float (*func)(float)) {
	float prev = func(-100.0f);
	for (float i = -100.0f; i <= 100.0f; i += 0.01f) {
		drawLine({i, func(i)}, {prev, func(prev)}, 5.0, RED);
		prev = func(i);
		std::cout << i << " " << func(i) << std::endl;
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