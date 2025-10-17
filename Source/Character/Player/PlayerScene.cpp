#include "PlayerScene.h"


#include "godot_cpp/classes/marker3d.hpp"
#include "godot_cpp/classes/generic6_dof_joint3d.hpp"

#include "Game.h"
#include "Interaction/GrabbableNode.h"
#include "Character/StateMachine/CharacterStateMachine.h"

bool PlayerScene::Initialize()
{
	HG_ERR_FAIL_COND_V_MSG(!m_Head, false, "Head is invalid.");
    HG_ERR_FAIL_COND_V_MSG(!m_CharacterStateMachine, false, "Character State Machine is invalid!");
	HG_ERR_FAIL_COND_V_MSG(!m_HandJoint, false, "HandJoints is invalid.");
    return true;
}

void PlayerScene::_bind_methods()
{
	HG_BIND_PROPERTY_NODE(PlayerScene, "Head", Node3D, SetHead, GetHead);
	HG_BIND_PROPERTY_NODE(PlayerScene, "HandJoint", Generic6DOFJoint3D, SetHandJoint, GetHandJoint);
    HG_BIND_PROPERTY_NODE(PlayerScene, "CharacterStateMachine", CharacterStateMachine, SetCharacterStateMachine, GetCharacterStateMachine);
}
