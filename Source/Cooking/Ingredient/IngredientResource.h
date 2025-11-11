#pragma once
#include "Utils/Utils.h"

#include "godot_cpp/classes/resource.hpp"
#include "godot_cpp/classes/packed_scene.hpp"

using namespace godot;

class IngredientResource : public Resource
{
    GDCLASS(IngredientResource, Resource)
    
public:
    
protected:
    static void _bind_methods();

    HG_ADD_PROPERTY(StringName, Name, "None", StringName, const StringName&);
};
