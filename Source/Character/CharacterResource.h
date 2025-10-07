#pragma once
#include "godot_cpp/classes/resource.hpp"

class CharacterResource : public godot::Resource
{
    GDCLASS(CharacterResource, Resource)
    
public:
protected:
    static void _bind_methods();
};
