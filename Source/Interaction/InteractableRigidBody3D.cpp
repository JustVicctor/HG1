#include "InteractableRigidBody3D.h"

void InteractableRigidBody3D::StartInteraction(Node3D* instigator, Marker3D* marker)
{
	Interactable::StartInteraction(instigator, marker);
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
