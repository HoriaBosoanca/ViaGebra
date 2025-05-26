#include "imgui.h"
#include "rlImGui.h"

void drawGui() {
	rlImGuiBegin();
	ImGui::Begin("Hello, ImGui!");
	ImGui::Text("Hello, World!");
	ImGui::End();
	rlImGuiEnd();
}
