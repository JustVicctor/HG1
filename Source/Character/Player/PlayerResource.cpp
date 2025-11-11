#include "PlayerResource.h"

#include "Character/Player/Player.h"
#include "Character/Player/PlayerScene.h"

Ref<Character> PlayerResource::CreateCharacter()
{
    Ref<Player> character;
    character.instantiate();
    return character;
}

void PlayerResource::_bind_methods()
{
	ADD_GROUP("Interaction", "interaction_");
	HG_BIND_PROPERTY_FLOAT(PlayerResource, "InteractionDistance", SetInteractionDistance, GetInteractionDistance);
}
