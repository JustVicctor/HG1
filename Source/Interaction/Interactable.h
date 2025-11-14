#pragma once
#include <godot_cpp/variant/vector3.hpp>

namespace godot
{
class Node3D;
class Marker3D;
}

using namespace godot;

class Interactable
{
public:
	virtual ~Interactable() = default;

	virtual Interactable* StartInteraction(Node3D* instigator, Marker3D* marker, Vector3 position);
	virtual void AlternativeInteraction(Marker3D* marker);
	virtual void ProcessInteraction(float delta);
	virtual void StopInteraction();

	bool CanInteract() const;
	bool IsInteracting() const;

protected:
	Marker3D* m_Marker = nullptr;
	Node3D* m_Instigator = nullptr;
	bool m_CanInteract = true;
	bool m_IsInteracting = false;
};
