#pragma once
#include "Cooking/Ingredient/IngredientScene.h"
#include "godot_cpp/classes/area3d.hpp"
#include "Utils/Utils.h"

class IngredientContainerResource;

class IngredientContainerScene : public IngredientScene
{
    GDCLASS(IngredientContainerScene, IngredientScene)
    
public:
    virtual void _ready() override;
    virtual void _physics_process(double p_delta) override;

    void SetIsEnabled(const bool isEnabled);
    
protected:
    bool m_IsEnabled = false;
    
    static void _bind_methods();

    HG_ADD_PROPERTY(Area3D*, Area, nullptr, Area3D*, Area3D*);
};
