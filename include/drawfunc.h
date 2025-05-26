#ifndef DRAW_H
#define DRAW_H

#include "raylib.h"

void drawFunc(float (*func)(float));
void drawLine(Vector2 p1, Vector2 p2, float thickness, Color color);

#endif