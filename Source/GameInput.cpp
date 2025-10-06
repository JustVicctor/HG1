#include "GameInput.h"

#include "godot_cpp/classes/input.hpp"

void GameInput::_ready()
{
	// Move to game input
	const auto input = godot::Input::get_singleton();
	input->set_mouse_mode(godot::Input::MOUSE_MODE_CAPTURED);
}

void GameInput::_bind_methods()
{
}
