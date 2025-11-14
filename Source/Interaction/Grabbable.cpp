#include "Grabbable.h"

#include "godot_cpp/classes/marker3d.hpp"

Interactable* Grabbable::StartInteraction(Node3D* instigator, Marker3D* marker, Vector3 position)
{
	InteractableRigidBody3D::StartInteraction(instigator, marker, position);
	if (m_NeedExcludeInstigator && m_Instigator)
		add_collision_exception_with(m_Instigator);
	return this;
}

void Grabbable::AlternativeInteraction(Marker3D* marker)
{
	const Basis globalBasis = marker->get_global_basis();
	const Vector3 throwDirection = -globalBasis.get_column(2).normalized();
	const float throwStrength = 20.f / get_mass();
	set_linear_velocity(throwDirection * throwStrength);
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
	InteractableRigidBody3D::StopInteraction();
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
