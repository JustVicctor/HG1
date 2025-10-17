#pragma once
#include "PlayerState.h"

class CharacterStateMachine;
using namespace godot;

class WalkingPlayerState final : public PlayerState
{
	GDCLASS(WalkingPlayerState, PlayerState)
	
public:
    virtual bool Initialize(Character* character, const ProcessStateTransition func) override;
	
	virtual void Process(const float delta) override;
 	virtual void PhysicsProcess(const float delta) override;

protected:
	static void _bind_methods();
};
