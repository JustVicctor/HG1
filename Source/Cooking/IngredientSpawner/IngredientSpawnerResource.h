#pragma once
#include "Utils/Utils.h"

#include "godot_cpp/classes/resource.hpp"
#include "godot_cpp/classes/packed_scene.hpp"

using namespace godot;

class IngredientSpawnerResource : public Resource
{
    GDCLASS(IngredientSpawnerResource, Resource)
    
public:
protected:
    static void _bind_methods();
    
    HG_ADD_PROPERTY_REF(PackedScene, IngredientScene, nullptr);
};
