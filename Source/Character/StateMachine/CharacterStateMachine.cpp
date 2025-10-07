#include "CharacterStateMachine.h"

#include "CharacterBaseState.h"
#include "Game.h"
#include "Utils/Utils.h"

bool CharacterStateMachine::Initialize(const CharacterBody3D* character)
{
    HG_ERR_FAIL_COND_V_MSG(character == nullptr, false, "Character is null");
    HG_ERR_FAIL_COND_V_MSG(m_InitialState == nullptr, false, "Initial state is null");

    m_CurrentState = m_InitialState;
    const int count = get_child_count();
    for (int index = 0; index < count; index++)
    {
        const auto child = get_child(index);
        if (const auto state = cast_to<CharacterBaseState>(child))
        {
            state->Initialize([this](const StringName& stateName) { ProcessTransition(stateName); });
            const StringName& stateName = state->GetStateName();
            HG_ERR_FAIL_COND_V_MSG(stateName.is_empty(), false, "Character State Enum is invalid");
            m_States[stateName] = state;
        }
    }
    return true;
}

void CharacterStateMachine::_process(const double delta)
{
    HG_ERR_FAIL_COND_MSG(m_CurrentState == nullptr, "Current state is null");
    m_CurrentState->Process(delta);
}

void CharacterStateMachine::_physics_process(const double delta)
{
    HG_ERR_FAIL_COND_MSG(m_CurrentState == nullptr, "Current state is null");
    m_CurrentState->PhysicsProcess(delta);
}

void CharacterStateMachine::_input(const Ref<InputEvent>& inputEvent)
{
    HG_ERR_FAIL_COND_MSG(m_CurrentState == nullptr, "Current state is null");
    m_CurrentState->Input(inputEvent);
}

void CharacterStateMachine::_shortcut_input(const Ref<InputEvent>& inputEvent)
{
    HG_ERR_FAIL_COND_MSG(m_CurrentState == nullptr, "Current state is null");
    m_CurrentState->ShortcutInput(inputEvent);
}

void CharacterStateMachine::_unhandled_input(const Ref<InputEvent>& inputEvent)
{
    HG_ERR_FAIL_COND_MSG(m_CurrentState == nullptr, "Current state is null");
    m_CurrentState->UnhandledInput(inputEvent);
}

void CharacterStateMachine::_unhandled_key_input(const Ref<InputEvent>& inputEvent)
{
    HG_ERR_FAIL_COND_MSG(m_CurrentState == nullptr, "Current state is null");
    m_CurrentState->UnhandledKeyInput(inputEvent);
}

void CharacterStateMachine::ProcessTransition(const StringName& stateName)
{
    HG_ERR_FAIL_COND_MSG(m_CurrentState == nullptr, "Current state is null");
    HG_ERR_FAIL_COND_MSG(stateName.is_empty(), "Transition state name is empty");
    m_CurrentState->Exit();
    m_CurrentState = m_States[stateName];
    m_CurrentState->Enter();
}

void CharacterStateMachine::_bind_methods()
{
    HG_BIND_PROPERTY_NODE(CharacterStateMachine, "InitialState", CharacterBaseState, SetInitialState, GetInitialState);
}
