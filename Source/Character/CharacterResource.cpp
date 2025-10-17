#include "CharacterResource.h"

#include "Character.h"
#include "CharacterScene.h"

Ref<Character> CharacterResource::CreateCharacter(const Ref<CharacterResource>& resource)
{
    Ref<Character> character = resource->CreateCharacter();
    HG_ERR_FAIL_COND_V_MSG(character.is_null(), nullptr, "Failed to create Character!");

    HG_ERR_FAIL_COND_V_MSG(resource->m_CharacterScene.is_null(), nullptr, "CharacterScene is null!");
    CharacterScene* scene = resource->CreateCharacterScene();
    HG_ERR_FAIL_COND_V_MSG(scene == nullptr, nullptr, "Failed to create CharacterScene!");

    const bool isReady = character->Initialize(resource, scene);
    HG_ERR_FAIL_COND_V_MSG(isReady == false, nullptr, "Failed to initialize Character!");
    
    return character;
}

Ref<Character> CharacterResource::CreateCharacter()
{
    return nullptr;
}

CharacterScene* CharacterResource::CreateCharacterScene()
{
    return nullptr;
}

void CharacterResource::_bind_methods()
{
	ADD_GROUP("Scene", "scene_");
    HG_BIND_PROPERTY_PACKED(CharacterResource, "CharacterScene", SetCharacterScene, GetCharacterScene);
    
	ADD_GROUP("Movement", "movement_");
	HG_BIND_PROPERTY_FLOAT(CharacterResource, "MovementSpeed", SetMovementSpeed, GetMovementSpeed);
	HG_BIND_PROPERTY_FLOAT(CharacterResource, "Acceleration", SetAcceleration, GetAcceleration);
	HG_BIND_PROPERTY_FLOAT(CharacterResource, "Deceleration", SetDeceleration, GetDeceleration);
}
