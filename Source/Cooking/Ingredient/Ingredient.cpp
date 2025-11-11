#include "Ingredient.h"

#include "IngredientScene.h"
#include "IngredientResource.h"

bool Ingredient::Initialize(const Ref<IngredientResource>& resource, IngredientScene* scene)
{
    m_Resource = resource;
    m_Scene = scene;
    return true;
}

Ref<IngredientResource>& Ingredient::GetResource()
{
    return m_Resource;
}

IngredientScene* Ingredient::GetScene() const
{
    return m_Scene;
}

void Ingredient::_bind_methods()
{
}
