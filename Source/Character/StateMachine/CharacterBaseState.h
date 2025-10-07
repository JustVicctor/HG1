#pragma once

#include <functional>
#include "godot_cpp/classes/node.hpp"

using namespace godot;

class CharacterBaseState : public Node
{
    GDCLASS(CharacterBaseState, Node)
	
public:
	using ProcessStateTransition = std::function<void(const StringName&)>;
	
    virtual void Initialize(const ProcessStateTransition func);
    virtual void Enter(){}
    virtual void Exit(){}
	
	virtual void Process(const float delta){}
	virtual void PhysicsProcess(const float delta){}
	virtual void Input(const Ref<InputEvent>& inputEvent){}
	virtual void ShortcutInput(const Ref<InputEvent>& inputEvent){}
	virtual void UnhandledInput(const Ref<InputEvent>& inputEvent){}
	virtual void UnhandledKeyInput(const Ref<InputEvent>& inputEvent){}

    const StringName& GetStateName() const;

protected:

	StringName m_StateName;
	ProcessStateTransition m_ProcessStateTransition;
	
	static void _bind_methods();
};
