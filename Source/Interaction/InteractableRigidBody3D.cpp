#include "InteractableRigidBody3D.h"

Interactable* InteractableRigidBody3D::StartInteraction(Node3D* instigator, Marker3D* marker, Vector3 position)
{
	return Interactable::StartInteraction(instigator, marker, position);
}

void InteractableRigidBody3D::AlternativeInteraction(Marker3D* marker)
{
	Interactable::AlternativeInteraction(marker);
}

void InteractableRigidBody3D::ProcessInteraction(float delta)
{
	Interactable::ProcessInteraction(delta);
}

void InteractableRigidBody3D::StopInteraction()
{
	Interactable::StopInteraction();
}

void InteractableRigidBody3D::_bind_methods()
{
}
