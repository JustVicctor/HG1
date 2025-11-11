#pragma once
#include "Interactable.h"
#include "godot_cpp/classes/static_body3d.hpp"

using namespace godot;

class InteractableStaticBody3D : public StaticBody3D, public Interactable
{
	GDCLASS(InteractableStaticBody3D, StaticBody3D)

public:
	virtual void StartInteraction(Node3D* instigator, Marker3D* marker) override;
	virtual void ProcessInteraction(float delta) override;
	virtual void StopInteraction() override;
	
protected:
	static void _bind_methods();
};
