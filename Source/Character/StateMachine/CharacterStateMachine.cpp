#include "CharacterStateMachine.h"

#include "Character/StateMachine/CharacterBaseState.h"
#include "Utils/Utils.h"

bool CharacterStateMachine::Initialize(Character* character)
{
    set_process_mode(PROCESS_MODE_DISABLED);
    
    HG_ERR_FAIL_COND_V_MSG(!character, false, "Character is null");
    HG_ERR_FAIL_COND_V_MSG(!m_InitialState, false, "Initial state is null");

    m_CurrentState = m_InitialState;
    const int count = get_child_count();
    for (int index = 0; index < count; index++)
    {
        const auto child = get_child(index);
        if (const auto stateNode = cast_to<CharacterBaseState>(child))
        {
            const bool isReady = stateNode->Initialize(
                character, [this](const ECharacterState state) { ProcessTransition(state); });
            HG_ERR_FAIL_COND_V_MSG(!isReady, false, "Failed to initialize state");
            
            const ECharacterState state = stateNode->GetCharacterState();
            HG_ERR_FAIL_COND_V_MSG(state == ECharacterState::None, false, "Character State Enum is invalid");
            m_States[state] = stateNode;
        }
    }
    return true;
}

void CharacterStateMachine::Input(const Ref<InputEvent>& inputEvent) const
{
    HG_ERR_FAIL_COND_MSG(!m_CurrentState, "Current state is null");
    m_CurrentState->Input(inputEvent);
}

void CharacterStateMachine::Process(const double delta) const
{
    HG_ERR_FAIL_COND_MSG(!m_CurrentState, "Current state is null");
    m_CurrentState->Process(delta);
}

void CharacterStateMachine::PhysicsProcess(const double delta) const
{
    HG_ERR_FAIL_COND_MSG(!m_CurrentState, "Current state is null");
    m_CurrentState->PhysicsProcess(delta);
}

void CharacterStateMachine::ProcessTransition(const ECharacterState state)
{
    HG_ERR_FAIL_COND_MSG(!m_CurrentState, "Current state is null");
    HG_ERR_FAIL_COND_MSG(state == ECharacterState::None, "Transition state name is empty");
    m_CurrentState->Exit();
    m_CurrentState = m_States[state];
    m_CurrentState->Enter();
}

void CharacterStateMachine::_bind_methods()
{
    HG_BIND_PROPERTY_NODE(CharacterStateMachine, "InitialState", CharacterBaseState, SetInitialState, GetInitialState);
}
