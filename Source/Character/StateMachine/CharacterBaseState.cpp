#include "CharacterBaseState.h"

void CharacterBaseState::Initialize(const ProcessStateTransition func)
{
    set_process_mode(PROCESS_MODE_DISABLED);
    m_ProcessStateTransition = func;
}

const StringName& CharacterBaseState::GetStateName() const
{
    return m_StateName;
}

void CharacterBaseState::_bind_methods()
{
}
