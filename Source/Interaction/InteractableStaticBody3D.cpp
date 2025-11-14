#include "InteractableStaticBody3D.h"

Interactable* InteractableStaticBody3D::StartInteraction(Node3D* instigator, Marker3D* marker, Vector3 position)
{
	Interactable::StartInteraction(instigator, marker, position);
	return this;
}

void InteractableStaticBody3D::ProcessInteraction(float delta)
{
	Interactable::ProcessInteraction(delta);
}

void InteractableStaticBody3D::StopInteraction()
{
	Interactable::StopInteraction();
}

void InteractableStaticBody3D::_bind_methods()
{
}
