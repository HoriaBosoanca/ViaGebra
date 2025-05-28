#include <functional>
#include <sol/sol.hpp>
#include "gui.h"

sol::state lua;

void initLua() {
	lua.open_libraries(sol::lib::base, sol::lib::math);
}

void setLuaFunc(const char* string) {
	try {
		lua.script(string);
		strncpy(luaError, "", 1);
	} catch (const sol::error& e) {
		strncpy(luaError, e.what(), sizeof(luaError) - 1);
	}
}

std::function<float(float)> getLuaFunc() {
	sol::object obj = lua["f"];

	// Check if it's a valid and callable function
	if (obj.is<sol::function>()) {
		sol::function f = obj;
		return [f](float x) -> float {
			sol::optional<float> result = f(x);
			return result.value_or(0.0f); // fallback value
		};
	}

	// Return a default dummy function
	return [](float) -> float {
		return 0.0f; // or throw, or log error
	};
}
