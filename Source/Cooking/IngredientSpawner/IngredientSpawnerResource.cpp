#include "IngredientSpawnerResource.h"

void IngredientSpawnerResource::_bind_methods()
{
    HG_BIND_PROPERTY_PACKED_SCENE(IngredientSpawnerResource, "IngredientScene", SetIngredientScene, GetIngredientScene);
}
