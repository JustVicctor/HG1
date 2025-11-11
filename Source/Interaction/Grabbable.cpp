#include "Grabbable.h"

#include "godot_cpp/classes/marker3d.hpp"

void Grabbable::StartInteraction(Node3D* instigator, Marker3D* marker)
{
	InteractableRigidBody3D::StartInteraction(instigator, marker);
	if (m_NeedExcludeInstigator && m_Instigator)
		add_collision_exception_with(m_Instigator);
	m_IsInteracting = true;
}

void Grabbable::ProcessInteraction(float delta)
{
	if (!m_IsInteracting)
		return;
	
	if (m_Marker == nullptr)
		return;

	const Vector3 currentPosition = get_global_position();
	const Vector3 targetPosition = m_Marker->get_global_position();
	const Vector3 distance = targetPosition - currentPosition;

	set_linear_velocity(distance * (15 / get_mass()));
}

void Grabbable::StopInteraction()
{
	if (m_NeedExcludeInstigator && m_Instigator)
		remove_collision_exception_with(m_Instigator);
	m_Instigator = nullptr;
	m_Marker = nullptr;
	m_IsInteracting = false;
}

void Grabbable::_bind_methods()
{
	HG_BIND_PROPERTY(
		Grabbable,
		Variant::BOOL,
		"NeedExcludeInstigator",
		SetNeedExcludeInstigator,
		GetNeedExcludeInstigator);
}
