#pragma once

#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/input_event.hpp"

#include "Utils/Utils.h"
#include "CharacterStateMachineCommon.h"

class Character;
class CharacterBaseState;
using namespace godot;

class CharacterStateMachine : public Node
{
    GDCLASS(CharacterStateMachine, Node)
	
public:
    bool Initialize(Character* character);

    void Input(const Ref<InputEvent>& inputEvent) const;
    void Process(const double delta) const;
    void PhysicsProcess(const double delta) const;

protected:
    void ProcessTransition(const ECharacterState state);
    
    std::unordered_map<ECharacterState, CharacterBaseState*> m_States;
    CharacterBaseState* m_CurrentState = nullptr;

    static void _bind_methods();

    HG_ADD_PROPERTY(CharacterBaseState*, InitialState, nullptr, CharacterBaseState*, CharacterBaseState*);
};
