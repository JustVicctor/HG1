#pragma once
#include "Utils/Utils.h"

#include "godot_cpp/classes/static_body3d.hpp"
#include "godot_cpp/classes/tween.hpp"

class IngredientContainerScene;

namespace godot
{
    class Area3D;
    class Marker3D;
}

class FoodStandResource;
using namespace godot;

class FoodStandScene : public StaticBody3D
{
    GDCLASS(FoodStandScene, StaticBody3D)
    
public:
    virtual void _ready() override;
    virtual void _process(double delta) override;
    
protected:
    IngredientContainerScene* m_IngredientContainer = nullptr;
    Ref<Tween> m_Tween = nullptr;
    
    static void _bind_methods();
    HG_ADD_PROPERTY_REF(FoodStandResource, Resource, nullptr);
    HG_ADD_PROPERTY(Area3D*, Area, nullptr, Area3D*, Area3D*);
    HG_ADD_PROPERTY(Marker3D*, Marker, nullptr, Marker3D*, Marker3D*);
};
