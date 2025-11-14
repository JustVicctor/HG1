#include "InteractionComponent.h"

#include "Game.h"
#include "GameInput.h"
#include "Interactable.h"

#include "godot_cpp/classes/ray_cast3d.hpp"
#include "godot_cpp/classes/marker3d.hpp"

void InteractionComponent::_ready()
{
	m_GameInput = Game::GetGameInput();
}

void InteractionComponent::_process(double delta)
{
	if (m_CurrentInteractable)
	{
		if (m_GameInput->IsSecondaryReleased())
		{
			m_CurrentInteractable->AlternativeInteraction(m_Marker);
			m_CurrentInteractable->StopInteraction();
			m_CurrentInteractable = nullptr;
		}
		else if (m_GameInput->IsPrimaryReleased())
		{
			m_CurrentInteractable->StopInteraction();
			m_CurrentInteractable = nullptr;
		}
		else
		{
			m_CurrentInteractable->ProcessInteraction(delta);
		}
	}
	else
	{
		if (m_GameInput->IsPrimaryPressed())
		{
			if (m_RayCast->is_colliding())
			{
				Object* collider = m_RayCast->get_collider();
				if (Interactable* interactable = dynamic_cast<Interactable*>(collider))
					m_CurrentInteractable = interactable->StartInteraction(
						m_Instigator,
						m_Marker,
						m_RayCast->get_collision_point());
			}
		}
	}
}

void InteractionComponent::_bind_methods()
{
	HG_BIND_PROPERTY_NODE(
		InteractionComponent,
		"Instigator",
		Node3D,
		SetInstigator,
		GetInstigator);

	HG_BIND_PROPERTY_NODE(
		InteractionComponent,
		"RayCast",
		RayCast3D,
		SetRayCast,
		GetRayCast);

	HG_BIND_PROPERTY_NODE(
		InteractionComponent,
		"Marker",
		Marker3D,
		SetMarker,
		GetMarker);
}
