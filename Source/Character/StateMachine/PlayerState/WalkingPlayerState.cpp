#include "WalkingPlayerState.h"

#include "Character/Player/Player.h"
#include "Character/Player/PlayerScene.h"

bool WalkingPlayerState::Initialize(Character* character, const ProcessStateTransition func)
{
	if (!PlayerState::Initialize(character, func))
		return false;
	m_State = ECharacterState::Walking;
	return true;
}

void WalkingPlayerState::Process(const float delta)
{
}

void WalkingPlayerState::PhysicsProcess(const float delta)
{
	ProcessGravity(delta);
	ProcessMove(delta);
	ProcessVelocity();

	const CharacterScene* scene = m_Player->GetScene();
	const Vector3 velocity = scene->get_velocity();
	if (velocity.length_squared() <= s_VelocityThreshold && scene->is_on_floor())
	{
		m_ProcessStateTransition(ECharacterState::Idle);
		return;
	}
}

void WalkingPlayerState::_bind_methods()
{
}
