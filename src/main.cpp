#include "drawfunc.h"
#include <cmath>
#include "input.h"
#include "rlImGui.h"
#include "imgui.h"

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

        rlImGuiBegin();
        ImGui::Begin("Hello, ImGui!");
        ImGui::Text("This is some text.");
        ImGui::End();
        rlImGuiEnd();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}