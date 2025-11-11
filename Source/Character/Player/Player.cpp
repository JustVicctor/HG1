#include "Player.h"

#include "Game.h"
#include "GameInput.h"
#include "godot_cpp/classes/generic6_dof_joint3d.hpp"

#include "Character/Player/PlayerResource.h"
#include "Character/Player/PlayerScene.h"

bool Player::Initialize(const Ref<CharacterResource>& resource, CharacterScene* scene)
{
	m_Resource = resource;
	m_Scene = cast_to<PlayerScene>(scene);

	bool isReady = true;
	CharacterStateMachine* stateMachine = m_Scene->GetCharacterStateMachine();
	isReady &= stateMachine->Initialize(this);

	return isReady;
}

void Player::Input(const Ref<InputEvent>& inputEvent)
{
	const CharacterStateMachine* machine = m_Scene->GetCharacterStateMachine();
	machine->Input(inputEvent);
}

void Player::Process(const double delta)
{
	const CharacterStateMachine* machine = m_Scene->GetCharacterStateMachine();
	machine->Process(delta);
}

void Player::PhysicsProcess(const float delta)
{
	const CharacterStateMachine* machine = m_Scene->GetCharacterStateMachine();
	machine->PhysicsProcess(delta);

	ProcessMouse();
}

void Player::ProcessMouse() const
{
	const auto gameInput = Game::GetGameInput();
	const auto mouseOffset = gameInput->GetMouseOffset();

	//Apply the new camera transform
	const auto head = m_Scene->GetHead();
	auto headTransform = head->get_transform();
	headTransform.basis = Basis::from_euler(
		Vector3(
			mouseOffset.x,
			0.f,
			0.f
			));
	head->set_transform(headTransform);

	auto globalTransform = m_Scene->get_global_transform();
	globalTransform.basis = Basis::from_euler(
		Vector3(
			0.f,
			mouseOffset.y,
			0.f
			));
	m_Scene->set_global_transform(globalTransform);
}

CharacterResource* Player::GetResource()
{
	return m_Resource.ptr();
}

CharacterScene* Player::GetScene() const
{
	return m_Scene;
}

void Player::_bind_methods()
{
}
