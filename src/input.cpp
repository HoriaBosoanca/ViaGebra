#include "raylib.h"

void handleInput() {
	if (IsKeyPressed(KEY_F11)) {
		ToggleFullscreen();
	}
}
