#include "IngredientScene.h"

void IngredientScene::_ready()
{
    HG_ERR_FAIL_COND_MSG(m_Resource.is_null(), "Resource is null");
    
    // set_collision_layer(1 << 1);
    // set_collision_mask(1 << 0);
}

void IngredientScene::_bind_methods()
{
    HG_BIND_PROPERTY_RESOURCE(IngredientScene, "Resource", IngredientResource, SetResource, GetResource);
}
