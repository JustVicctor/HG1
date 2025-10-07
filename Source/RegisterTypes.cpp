#include "RegisterTypes.h"

#include <gdextension_interface.h>
#include <godot_cpp/classes/engine.hpp>

#include "Game.h"
#include "GameInput.h"
#include "Character/Character.h"
#include "Character/CharacterResource.h"
#include "Character/StateMachine/CharacterBaseState.h"
#include "Character/StateMachine/CharacterStateMachine.h"
#include "Levels/Level.h"
#include "Settings/GameSettings.h"
#include "Settings/UserSettings.h"

using namespace godot;

void ViclibInitialize(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		// Game
		ClassDB::register_runtime_class<Game>();
		ClassDB::register_runtime_class<GameInput>();


		// Settings
		ClassDB::register_runtime_class<GameSettings>();
		ClassDB::register_runtime_class<UserSettings>();


		// Levels
		ClassDB::register_runtime_class<Level>();

		
		// Character
		ClassDB::register_runtime_class<Character>();
		ClassDB::register_runtime_class<CharacterResource>();
		ClassDB::register_runtime_class<CharacterBaseState>();
		ClassDB::register_runtime_class<CharacterStateMachine>();
	}
}

void ViclibTerminate(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
	{
	}
}

extern "C"
{
	GDExtensionBool GDE_EXPORT ViclibInit(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
	{
		GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(ViclibInitialize);
		init_obj.register_terminator(ViclibTerminate);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}
