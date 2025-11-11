#pragma once
#include "Character/CharacterResource.h"

class PlayerResource : public CharacterResource
{
    GDCLASS(PlayerResource, CharacterResource)
    
public:
    
protected:
    virtual Ref<Character> CreateCharacter() override;
    
    static void _bind_methods();
    
	HG_ADD_PROPERTY(float, InteractionDistance, 2.f, float, const float);
};
