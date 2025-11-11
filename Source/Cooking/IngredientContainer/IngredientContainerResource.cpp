#include "Cooking/IngredientContainer/IngredientContainerResource.h"
#include "Cooking/Ingredient/IngredientResource.h"

void IngredientContainerResource::_bind_methods()
{
    HG_BIND_PROPERTY_ARRAY(IngredientContainerResource, "AllowedIngredients", IngredientResource, SetAllowedIngredients, GetAllowedIngredients);
}
