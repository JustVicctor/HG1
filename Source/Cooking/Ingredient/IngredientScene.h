#pragma once
#include "Utils/Utils.h"

#include "IngredientResource.h"
#include "Interaction/Grabbable.h"


class IngredientResource;

class IngredientScene : public Grabbable
{
    GDCLASS(IngredientScene, Grabbable)
    
public:
    virtual void _ready() override;
    
protected:
    static void _bind_methods();

    HG_ADD_PROPERTY_REF(IngredientResource, Resource, nullptr);
};
