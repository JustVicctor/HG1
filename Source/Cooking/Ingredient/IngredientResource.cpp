#include "IngredientResource.h"

void IngredientResource::_bind_methods()
{
    HG_BIND_PROPERTY_STRING_NAME(IngredientResource, "Name", SetName, GetName);
}
