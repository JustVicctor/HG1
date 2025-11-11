#pragma once
#include "Cooking/Ingredient/IngredientResource.h"
#include "Utils/Utils.h"

#include "godot_cpp/classes/resource.hpp"

class IngredientResource;

using namespace godot;

class IngredientContainerResource : public IngredientResource
{
    GDCLASS(IngredientContainerResource, IngredientResource)
    
public:
protected:
    static void _bind_methods();

    HG_ADD_PROPERTY_TYPED_ARRAY(IngredientResource, AllowedIngredients, {});
};
