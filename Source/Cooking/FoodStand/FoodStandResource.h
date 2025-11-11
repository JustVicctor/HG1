#pragma once
#include "Utils/Utils.h"

#include "godot_cpp/classes/resource.hpp"

class IngredientContainerResource;
using namespace godot;

class FoodStandResource : public Resource
{
    GDCLASS(FoodStandResource, Resource)
    
public:
protected:
    static void _bind_methods();
    
    HG_ADD_PROPERTY_TYPED_ARRAY(IngredientContainerResource, AllowedIngredientContainers, {});
};
