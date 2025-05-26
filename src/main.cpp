#include "drawfunc.h"
#include <cmath>
#include "input.h"

float f(float x) {
    return x*x;
}

float X_SCREEN;
float Y_SCREEN;

int main()
{
    InitWindow(X_SCREEN, Y_SCREEN, "ViaGebra");

    int monitor = GetCurrentMonitor();
    X_SCREEN = GetMonitorWidth(monitor);
    Y_SCREEN = GetMonitorHeight(monitor);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        handleInput();
        drawFunc(f);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}