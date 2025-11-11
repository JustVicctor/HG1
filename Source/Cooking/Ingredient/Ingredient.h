#pragma once
#include "godot_cpp/classes/ref_counted.hpp"

class IngredientScene;
class IngredientResource;

using namespace godot;

class Ingredient : public RefCounted
{
    GDCLASS(Ingredient, RefCounted)
    
public:
    virtual bool Initialize(const Ref<IngredientResource>& resource, IngredientScene* scene);
    
    virtual Ref<IngredientResource>& GetResource();
    virtual IngredientScene* GetScene() const;
    
protected:
    Ref<IngredientResource> m_Resource = nullptr;
    IngredientScene* m_Scene = nullptr;
    
    static void _bind_methods();
};
