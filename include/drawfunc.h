#ifndef DRAW_H
#define DRAW_H

#include <functional>

#include "../lib/raylib/include/raylib.h"

void drawFunc(std::function<float(float)>);
void drawLine(Vector2 p1, Vector2 p2, float thickness, Color color);

#endif