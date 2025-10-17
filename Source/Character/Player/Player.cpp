#include "Player.h"

#include "Game.h"
#include "GameInput.h"
#include "godot_cpp/classes/generic6_dof_joint3d.hpp"

#include "Character/Player/PlayerResource.h"
#include "Character/Player/PlayerScene.h"
#include "Interaction/GrabbableObject.h"
#include "Interaction/IInteractable.h"
#include "Utils/SweepUtils.h"

bool Player::Initialize(const Ref<CharacterResource>& resource, CharacterScene* scene)
{
    m_Resource = resource;
    m_Scene = cast_to<PlayerScene>(scene);

    bool isReady = true;
    CharacterStateMachine* stateMachine = m_Scene->GetCharacterStateMachine();
    isReady &= stateMachine->Initialize(this);

    m_Query = PhysicsRayQueryParameters3D::create({}, {});
    m_Query->set_collide_with_areas(false);
    m_Query->set_collide_with_bodies(true);
    m_Query->set_exclude({m_Scene->get_rid()});
    m_Query->set_hit_back_faces(true);
    m_Query->set_hit_from_inside(true);

    return isReady;
}

void Player::Input(const Ref<InputEvent>& inputEvent)
{
}

void Player::Process(const double delta)
{
    ProcessMouse(delta);
    ProcessInteraction(delta);
    ProcessGrabbing(delta);
}

void Player::GrabObject(GrabbableObject* obj)
{
    m_GrabbableObject = obj;
    m_GrabbableObject->add_collision_exception_with(m_Scene);
    m_GrabbableObject->SetIsGrabbed(true);
    Generic6DOFJoint3D* joint = m_Scene->GetHandJoint();
    joint->set_node_b(obj->get_path());
}

void Player::ReleaseGrabbed()
{
    if (!m_GrabbableObject)
        return;
    m_GrabbableObject->remove_collision_exception_with(m_Scene);
    m_GrabbableObject->SetIsGrabbed(false);
    m_GrabbableObject = nullptr;
    Generic6DOFJoint3D* joint = m_Scene->GetHandJoint();
    joint->set_node_b("");
}

void Player::ProcessGrabbing(const float delta)
{
    if (m_GrabbableObject == nullptr)
        return;

    const Generic6DOFJoint3D* joint = m_Scene->GetHandJoint();
    const Vector3 objectTransform = m_GrabbableObject->get_global_transform().origin;
    const Vector3 markerTransform = joint->get_global_transform().origin;
    const Vector3 moveVector = markerTransform - objectTransform;
    if (moveVector.length_squared() > 5.f)
    {
        ReleaseGrabbed();
        return;
    }

    m_GrabbableObject->set_linear_velocity(moveVector * 10.f);
}

void Player::ProcessInteraction(const float delta)
{
    const Node3D* camera = m_Scene->GetHead();
    const Transform3D transform = camera->get_global_transform();

    const float distance = m_Resource->GetInteractionDistance();
    const Vector3 origin = transform.get_origin();
    m_Query->set_from(origin);
    m_Query->set_to(origin + transform.basis.get_column(2).normalized() * -distance);

    const GameInput* gameInput = Game::GetGameInput();

    const bool needInteract = gameInput->IsInteractPressed();
    const bool isPrimary = gameInput->IsPrimaryPressed();
    if (needInteract || isPrimary)
    {
        HitResult hit;
        if (SweepUtils::Sweep(m_Query, camera->get_world_3d(), hit))
        {
            if (needInteract)
            {
                if (IInteractable* interactable = dynamic_cast<IInteractable*>(hit.HitObject))
                    interactable->Interact(m_Scene);
            }

            if (isPrimary)
            {
                if (GrabbableObject* grabbable = dynamic_cast<GrabbableObject*>(hit.HitObject))
                    GrabObject(grabbable);
            }
        }
    }

    if (gameInput->IsPrimaryReleased())
    {
        ReleaseGrabbed();
    }

    ProcessGrabbing(delta);
}

void Player::ProcessMouse(const float delta) const
{
	const auto gameInput = Game::GetGameInput();
	const auto mouseOffset = gameInput->GetMouseOffset();

	//Apply the new camera transform
	const auto head = m_Scene->GetHead();
	auto headTransform = head->get_transform();
	headTransform.basis = Basis::from_euler(Vector3(
		mouseOffset.x,
	    0.f,
	    0.f
	));
	head->set_transform(headTransform);

	auto globalTransform = m_Scene->get_global_transform();
	globalTransform.basis = Basis::from_euler(Vector3(
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
