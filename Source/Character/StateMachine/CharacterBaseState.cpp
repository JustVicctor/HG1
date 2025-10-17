#include "CharacterBaseState.h"

#include "Game.h"

bool CharacterBaseState::Initialize(Character* character, const ProcessStateTransition func)
{
    set_process_mode(PROCESS_MODE_DISABLED);
    m_ProcessStateTransition = func;
    
	userSettings = Game::GetUserSettings();
	gameSettings = Game::GetGameSettings();
    return true;
}

ECharacterState CharacterBaseState::GetCharacterState() const
{
    return m_State;
}

void CharacterBaseState::_bind_methods()
{
}
