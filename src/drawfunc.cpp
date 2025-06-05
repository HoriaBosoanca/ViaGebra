#include "drawfunc.h"
#include <functional>
#include "luaApi.h"
#include "raylib.h"
#include "main.h"

void draw() {
	draw_Axis_X();
	draw_Axis_Y();
	drawFunc(getLuaFunc());
}

void drawFunc(std::function<float(float)> func) {
	float prevX = -100.0, prevY = func(-100.0f);
	for (float i = -100.0f; i <= 100.0f; i += 0.1f) {
		drawLine({i, func(i)}, {prevX, prevY}, 2.0, RED);
		prevX = i;
		prevY = func(i);
	}
}

void draw_Axis_X() {
	float prevX = -100.0, prevY = 0, j = -100.0f;
	for (int y = 0; y < 5; y++) {
		drawLine({j, 0}, {prevX, prevY}, 2.0, GREEN);
		prevX = j;
		j += 0.1f;
	}
	for (j = -100.0f; j <= 100.0f; j += 0.1f){
		for (int g = 0; g < 90; g++) {
			drawLine({j, 0}, {prevX, prevY}, 2.0, BLACK);
			prevX = j;
			j += 0.1f;
		}
		for (int y = 0; y < 10; y++) {
			drawLine({j, 0}, {prevX, prevY}, 2.0, GREEN);
			prevX = j;
			j += 0.1f;
		}
	}
}
void draw_Axis_Y() {
	float prevX = 0, prevY = -100, j = -100.0f;
	for (int y = 0; y < 5; y++) {
		drawLine({0, j}, {prevX, prevY}, 2.0, GREEN);
		prevY = j;
		j += 0.1f;
	}
	for (j = -100.0f; j <= 100.0f; j += 0.1f) {
		for (int g = 0; g < 90; g++) {
			drawLine({0, j}, {prevX, prevY}, 2.0, BLACK);
			prevY = j;
			j += 0.1f;
		}
		for (int y = 0; y < 10; y++) {
			drawLine({0, j}, {prevX, prevY}, 2.0, GREEN);
			prevY = j;
			j += 0.1f;
		}
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