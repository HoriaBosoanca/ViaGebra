#include "drawfunc.h"
#include "gui.h"
#include "input.h"
#include "rlImGui.h"

float f(float x) {
    return x*x;
}

float X_SCREEN;
float Y_SCREEN;

int main()
{
    InitWindow(X_SCREEN, Y_SCREEN, "ViaGebra");
    rlImGuiSetup(true);

    int monitor = GetCurrentMonitor();
    X_SCREEN = GetMonitorWidth(monitor);
    Y_SCREEN = GetMonitorHeight(monitor);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        handleInput();
        drawFunc(f);
        drawGui();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}