#pragma once
#include "Cooking/Ingredient/Ingredient.h"
using namespace godot;

class IngredientContainer : public Ingredient
{
    GDCLASS(IngredientContainer, RefCounted)
public:
protected:
    bool m_IsEnable = false;
    
    static void _bind_methods();
};
