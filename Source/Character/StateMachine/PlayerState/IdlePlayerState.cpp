#include "IdlePlayerState.h"

#include "Character/Player/Player.h"
#include "Character/Player/PlayerScene.h"

bool IdlePlayerState::Initialize(Character* character, const ProcessStateTransition func)
{
    if (!PlayerState::Initialize(character, func))
        return false;
    m_State = ECharacterState::Idle;
    return true;
}

void IdlePlayerState::Process(const float delta)
{
}

void IdlePlayerState::PhysicsProcess(const float delta)
{
    ProcessGravity(delta);
    ProcessMove(delta);
    ProcessVelocity();

	const CharacterScene* scene = m_Player->GetScene();
    const Vector3 velocity = scene->get_velocity();
    if (velocity.length_squared() > s_VelocityThreshold && scene->is_on_floor())
    {
        m_ProcessStateTransition(ECharacterState::Walking);
        return;
    }
}

void IdlePlayerState::_bind_methods()
{
}
