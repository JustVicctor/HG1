#pragma once
#include "InteractableRigidBody3D.h"
#include "Utils/Utils.h"

class Grabbable : public InteractableRigidBody3D
{
private:
	GDCLASS(Grabbable, InteractableRigidBody3D)

public:
	virtual Interactable* StartInteraction(Node3D* instigator, Marker3D* marker, Vector3 position) override;
	virtual void AlternativeInteraction(Marker3D* marker) override;
	virtual void ProcessInteraction(float delta) override;
	virtual void StopInteraction() override;

protected:

	static void _bind_methods();
	HG_ADD_PROPERTY(bool, NeedExcludeInstigator, false, bool, bool);
};
