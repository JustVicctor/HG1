#include "PlayerState.h"

#include "Game.h"
#include "GameInput.h"

#include "Character/Player/Player.h"
#include "Character/Player/PlayerScene.h"

bool PlayerState::Initialize(Character* character, const ProcessStateTransition func)
{
    CharacterBaseState::Initialize(character, func);
	
	m_Player = cast_to<Player>(character);
	HG_ERR_FAIL_COND_V_MSG(m_Player == nullptr, false, "Hero could not be initialized!");
	
	return true;
}

void PlayerState::ProcessGravity(const float delta) const
{
	CharacterScene* scene = m_Player->GetScene();
	auto velocity = scene->get_velocity();
	const auto gameSettings = Game::GetGameSettings();
	if (!scene->is_on_floor())
		velocity.y += gameSettings->GetGravityForce() * delta;
	scene->set_velocity(velocity);
}

void PlayerState::ProcessMove(const float delta) const
{
	CharacterScene* scene = m_Player->GetScene();
	const CharacterResource* resource = m_Player->GetResource();
	
	auto velocity = scene->get_velocity();

	const GameInput* gameInput = Game::GetGameInput();
	const Vector2 moveVector = gameInput->GetMoveVector();
	const Basis basis = scene->get_global_basis();
	Vector3 direction = Vector3(moveVector.x, 0, -moveVector.y);
	direction.normalize();
	direction = basis.xform(direction);
	
	if (direction.length_squared() < s_VelocityThreshold)
	{
		const float deceleration = resource->GetDeceleration();
		velocity.x = Math::lerp(velocity.x, 0.0f, deceleration * delta);
		velocity.z = Math::lerp(velocity.z, 0.0f, deceleration * delta);
	}
	else
	{
		const float speed = resource->GetMovementSpeed();
		const float acceleration = resource->GetAcceleration();
		velocity.x = Math::lerp(velocity.x, direction.x * speed, acceleration * delta);
		velocity.z = Math::lerp(velocity.z, direction.z * speed, acceleration * delta);
	}

	scene->set_velocity(velocity);
}

void PlayerState::ProcessVelocity() const
{
	CharacterScene* scene = m_Player->GetScene();
	scene->move_and_slide();
}

void PlayerState::_bind_methods()
{
}
