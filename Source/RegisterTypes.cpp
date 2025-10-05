#include "RegisterTypes.h"

#include <gdextension_interface.h>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void ViclibInitialize(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
	{
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
		godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(ViclibInitialize);
		init_obj.register_terminator(ViclibTerminate);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}
