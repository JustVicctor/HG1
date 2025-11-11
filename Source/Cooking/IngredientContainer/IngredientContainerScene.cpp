#include "IngredientContainerScene.h"
#include "IngredientContainerResource.h"
#include "godot_cpp/classes/box_container.hpp"

void IngredientContainerScene::_ready()
{
    IngredientScene::_ready();
    HG_ERR_FAIL_COND_MSG(m_Area == nullptr, "Area is null");
    
    // set_collision_layer(1 << 2);
    // set_collision_mask(1 << 0);
    
    m_Area->set_collision_layer(0);
    m_Area->set_collision_mask(1 << 1);
}

void IngredientContainerScene::_physics_process(double p_delta)
{
    if (!m_IsEnabled)
        return;
    
    if (!m_Area->has_overlapping_bodies())
        return;
    
    const Ref<IngredientContainerResource> containerResource = m_Resource;
    HG_ERR_FAIL_COND_MSG(containerResource.is_null(), "Container Resource is null");
    
    const auto& bodies = m_Area->get_overlapping_bodies();
    const auto& alloweds = containerResource->GetAllowedIngredients();
    
    for (const auto& body : bodies)
    {
        const auto ingredient = cast_to<IngredientScene>(body);
        if (!ingredient || ingredient->IsInteracting())
            return;

        const auto& ingredientResource = ingredient->GetResource();
        for (const auto& allowed : alloweds)
        {
            if (allowed == ingredientResource)
            {
                // TODO: Logic
                ingredient->queue_free();
            }
        }
    }
}

void IngredientContainerScene::SetIsEnabled(const bool isEnabled)
{
    m_IsEnabled = isEnabled;
}

void IngredientContainerScene::_bind_methods()
{
    HG_BIND_PROPERTY_NODE(IngredientContainerScene, "Area", Area3D, SetArea, GetArea);
}
