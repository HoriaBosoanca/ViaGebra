#include "drawfunc.h"
#include "raylib.h"

float f(float x) {
    return x*x*x/100;
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