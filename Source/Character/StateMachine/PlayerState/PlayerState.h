#pragma once

#include "Character/StateMachine/CharacterBaseState.h"

class Player;
using namespace godot;

constexpr float s_VelocityThreshold = 0.001f;

class PlayerState : public CharacterBaseState
{
    GDCLASS(PlayerState, CharacterBaseState)

public:
    virtual bool Initialize(Character* character, const ProcessStateTransition func) override;
    
protected:
	Player* m_Player;

    void ProcessGravity(const float delta) const;
    void ProcessMove(const float delta) const;
    void ProcessVelocity() const;
    
	static void _bind_methods();
};
