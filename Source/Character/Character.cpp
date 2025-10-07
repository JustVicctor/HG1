#include "Character.h"

#include "Character/CharacterResource.h"
#include "Character/StateMachine/CharacterStateMachine.h"

bool Character::Initialize()
{
    HG_ERR_FAIL_COND_V_MSG(m_CharacterResource.is_null(), false, "Character Resource is invalid!");
    HG_ERR_FAIL_COND_V_MSG(m_CharacterStateMachine == nullptr, false, "Character State Machine is invalid!");
    
    bool isReady = true;
    isReady &= m_CharacterStateMachine->Initialize(this);
    return isReady;
}

void Character::_bind_methods()
{
    HG_BIND_PROPERTY_RESOURCE(Character, "CharacterResource", CharacterResource, SetCharacterResource, GetCharacterResource);
    HG_BIND_PROPERTY_NODE(Character, "CharacterStateMachine", CharacterStateMachine, SetCharacterStateMachine, GetCharacterStateMachine);
}
