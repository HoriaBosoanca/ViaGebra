#include "gui.h"
#include <iostream>
#include <string>
#include "imgui.h"
#include "luaApi.h"
#include "rlImGui.h"

char code[1024] = R"(function f(x)
	if x<0 then
		return x*x
	else
 		return math.sin(x)
	end
end)";
char luaError[1024];

void drawGui() {
	rlImGuiBegin();
	ImGui::Begin("Lua code");

	// lua code
	ImGui::InputTextMultiline(
		"##",
		code,
		IM_ARRAYSIZE(code),
		ImVec2(400, 300)
	);

	// draw button
	if (ImGui::Button("Draw", ImVec2(400, 40))) {
		setLuaFunc(code);
	}

	// code errors
	ImGui::TextWrapped("%s", luaError);

	ImGui::End();
	rlImGuiEnd();
}
