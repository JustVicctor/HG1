#pragma once

#include "Utils/Utils.h"
#include "Character/CharacterScene.h"

namespace godot
{
	class Generic6DOFJoint3D;
}

class CharacterStateMachine;

class PlayerScene : public CharacterScene
{
	GDCLASS(PlayerScene, CharacterScene)

public:
	virtual bool Initialize() override;

protected:
	
	static void _bind_methods();
	
	HG_ADD_PROPERTY(Node3D*, Head, nullptr, Node3D*, Node3D*);
	HG_ADD_PROPERTY(Generic6DOFJoint3D*, HandJoint, nullptr, Generic6DOFJoint3D*, Generic6DOFJoint3D*);
    HG_ADD_PROPERTY(CharacterStateMachine*, CharacterStateMachine, nullptr, CharacterStateMachine*, CharacterStateMachine*);
};
