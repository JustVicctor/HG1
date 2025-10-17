#include "PlayerResource.h"

#include "Character/Player/Player.h"
#include "Character/Player/PlayerScene.h"

Ref<Character> PlayerResource::CreateCharacter()
{
    Ref<Player> character;
    character.instantiate();
    return character;
}

CharacterScene* PlayerResource::CreateCharacterScene()
{
    PlayerScene* scene = cast_to<PlayerScene>(m_CharacterScene->instantiate());
    return scene && scene->Initialize() ? scene : nullptr;
}

void PlayerResource::_bind_methods()
{
	ADD_GROUP("Interaction", "interaction_");
	HG_BIND_PROPERTY_FLOAT(PlayerResource, "InteractionDistance", SetInteractionDistance, GetInteractionDistance);
}
