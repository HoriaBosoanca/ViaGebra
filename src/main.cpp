#include <complex>
#include "drawfunc.h"
#include "gui.h"
#include "input.h"
#include "luaApi.h"
#include "rlImGui.h"
#include "axe.h"

float X_SCREEN;
float Y_SCREEN;

int main()
{
    InitWindow(X_SCREEN, Y_SCREEN, "ViaGebra");
    rlImGuiSetup(true);

    int monitor = GetCurrentMonitor();
    X_SCREEN = GetMonitorWidth(monitor);
    Y_SCREEN = GetMonitorHeight(monitor);

    initLua();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        handleInput();

        drawFunc(getLuaFunc());
        drawGui();
        axe();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}