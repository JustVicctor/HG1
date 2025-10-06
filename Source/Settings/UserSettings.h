#pragma once
#include "godot_cpp/classes/resource.hpp"

class UserSettings : public godot::Resource
{
    GDCLASS(UserSettings, Resource)
public:
	void Save();
	static godot::Ref<UserSettings> LoadOrCreate();
	
protected:
	static void _bind_methods();
};
