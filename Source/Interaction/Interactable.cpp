#include "Interactable.h"

#include "godot_cpp/classes/marker3d.hpp"

#include <godot_cpp/variant/vector3.hpp>

Interactable* Interactable::StartInteraction(Node3D* instigator, Marker3D* marker, Vector3 position)
{
	m_Instigator = instigator;
	m_Marker = marker;
	m_IsInteracting = true;
	return this;
}

void Interactable::AlternativeInteraction(Marker3D* marker)
{
}

void Interactable::ProcessInteraction(float delta)
{
}

void Interactable::StopInteraction()
{
	m_Instigator = nullptr;
	m_Marker = nullptr;
	m_IsInteracting = false;
}

bool Interactable::CanInteract() const
{
	return m_CanInteract;
}

bool Interactable::IsInteracting() const
{
	return m_IsInteracting;
}
