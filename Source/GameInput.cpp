#include "GameInput.h"

#include "godot_cpp/classes/input.hpp"

bool GameInput::Initialize()
{
	const auto input = godot::Input::get_singleton();
	input->set_mouse_mode(godot::Input::MOUSE_MODE_CAPTURED);
	return true;
}

void GameInput::_bind_methods()
{
}
