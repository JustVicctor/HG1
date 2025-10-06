#pragma once
#include "godot_cpp/classes/resource.hpp"

class GameSettings : public godot::Resource
{
    GDCLASS(GameSettings, Resource)
public:
    void Save();
    static godot::Ref<GameSettings> LoadOrCreate();

protected:
    static void _bind_methods();
};
