#include "drawfunc.h"
#include <cmath>

float f(float x) {
    return 10*std::sin(x);
}

float X_SCREEN;
float Y_SCREEN;

int main()
{
    InitWindow(X_SCREEN, Y_SCREEN, "ViaGebra");

    int monitor = GetCurrentMonitor();
    X_SCREEN = GetMonitorWidth(monitor);
    Y_SCREEN = GetMonitorHeight(monitor);
    ToggleFullscreen();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        drawFunc(f);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}