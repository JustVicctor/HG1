#include "InteractableStaticBody3D.h"

void InteractableStaticBody3D::StartInteraction(Node3D* instigator, Marker3D* marker)
{
	Interactable::StartInteraction(instigator, marker);
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
