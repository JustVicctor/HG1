#pragma once
#include "godot_cpp/classes/resource.hpp"
#include "Utils/Utils.h"

class UserSettings : public godot::Resource
{
    GDCLASS(UserSettings, Resource)
public:
	void Save();
	static godot::Ref<UserSettings> LoadOrCreate();

protected:
	static void _bind_methods();

	HG_ADD_PROPERTY(float, HorizontalMouseSensitivity, 0.5f, float, const float);
	HG_ADD_PROPERTY(float, VerticalMouseSensitivity, 0.5f, float, const float);
};
