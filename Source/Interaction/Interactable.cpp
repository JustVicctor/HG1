#include "Interactable.h"

void Interactable::StartInteraction(Node3D* instigator, Marker3D* marker)
{
	m_Instigator = instigator;
	m_Marker = marker;
}

void Interactable::ProcessInteraction(float delta)
{
}

void Interactable::StopInteraction()
{
}

bool Interactable::CanInteract() const
{
	return m_CanInteract;
}

bool Interactable::IsInteracting() const
{
	return m_IsInteracting;
}
