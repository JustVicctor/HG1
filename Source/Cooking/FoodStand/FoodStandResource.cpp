#include "Cooking/FoodStand/FoodStandResource.h"
#include "Cooking/IngredientContainer/IngredientContainerResource.h"

void FoodStandResource::_bind_methods()
{
    HG_BIND_PROPERTY_ARRAY(
        FoodStandResource,
        "AllowedIngredientContainers",
        IngredientContainerResource,
        SetAllowedIngredientContainers,
        GetAllowedIngredientContainers);
}
