#pragma once
#include "godot_cpp/classes/resource.hpp"
#include "Utils/Utils.h"

class GameSettings : public godot::Resource
{
    GDCLASS(GameSettings, Resource)
public:
    void Save();
    static godot::Ref<GameSettings> LoadOrCreate();

protected:
	static void _bind_methods();

	HG_ADD_PROPERTY(float, MaxPitch, 1.5533f, float, const float);
	HG_ADD_PROPERTY(float, MinPitch, -1.5533f, float, const float);
	
	HG_ADD_PROPERTY(float, GravityForce, -9.8f, float, const float);
};
