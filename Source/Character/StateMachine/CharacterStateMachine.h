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

    void _process(const double delta) override;
    void _physics_process(const double delta) override;
    void _input(const Ref<InputEvent>& inputEvent) override;
    void _shortcut_input(const Ref<InputEvent>& inputEvent) override;
    void _unhandled_input(const Ref<InputEvent>& inputEvent) override;
    void _unhandled_key_input(const Ref<InputEvent>& inputEvent) override;

protected:
    void ProcessTransition(const ECharacterState state);
    
    std::unordered_map<ECharacterState, CharacterBaseState*> m_States;
    CharacterBaseState* m_CurrentState = nullptr;

    static void _bind_methods();

    HG_ADD_PROPERTY(CharacterBaseState*, InitialState, nullptr, CharacterBaseState*, CharacterBaseState*);
};
