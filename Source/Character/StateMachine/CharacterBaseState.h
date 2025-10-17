#pragma once

#include <functional>
#include "godot_cpp/classes/node.hpp"

#include "Settings/GameSettings.h"
#include "Settings/UserSettings.h"
#include "Character/StateMachine/CharacterStateMachineCommon.h"

class Character;
using namespace godot;

class CharacterBaseState : public Node
{
    GDCLASS(CharacterBaseState, Node)
	
public:
	using ProcessStateTransition = std::function<void(const ECharacterState)>;
	
    virtual bool Initialize(Character* character, const ProcessStateTransition func);
    virtual void Enter(){}
    virtual void Exit(){}
	
	virtual void Process(const float delta){}
	virtual void PhysicsProcess(const float delta){}
	virtual void Input(const Ref<InputEvent>& inputEvent){}
	virtual void ShortcutInput(const Ref<InputEvent>& inputEvent){}
	virtual void UnhandledInput(const Ref<InputEvent>& inputEvent){}
	virtual void UnhandledKeyInput(const Ref<InputEvent>& inputEvent){}

    ECharacterState GetCharacterState() const;

protected:
	ECharacterState m_State = ECharacterState::None;
	ProcessStateTransition m_ProcessStateTransition;
	
	Ref<UserSettings> userSettings;
	Ref<GameSettings> gameSettings;
	
	static void _bind_methods();
};
