#pragma once
#include "Interactable.h"
#include "godot_cpp/classes/rigid_body3d.hpp"

class InteractableRigidBody3D : public RigidBody3D, public Interactable
{
	GDCLASS(InteractableRigidBody3D, RigidBody3D)

public:
	virtual Interactable* StartInteraction(Node3D* instigator, Marker3D* marker, Vector3 position) override;
	virtual void AlternativeInteraction(Marker3D* marker) override;
	virtual void ProcessInteraction(float delta) override;
	virtual void StopInteraction() override;

protected:
	static void _bind_methods();
};
