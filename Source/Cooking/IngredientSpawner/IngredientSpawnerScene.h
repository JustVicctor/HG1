#pragma once
#include "Utils/Utils.h"

#include "godot_cpp/classes/marker3d.hpp"
#include "Interaction/InteractableStaticBody3D.h"


class IngredientSpawnerResource;

class IngredientSpawnerScene : public InteractableStaticBody3D
{
	GDCLASS(IngredientSpawnerScene, StaticBody3D)

public:
	virtual void _ready() override;

	virtual void StartInteraction(Node3D* instigator, Marker3D* marker) override;
	virtual void ProcessInteraction(float delta) override;
	virtual void StopInteraction() override;

protected:
	static void _bind_methods();

	HG_ADD_PROPERTY_REF(IngredientSpawnerResource, Resource, nullptr);
	HG_ADD_PROPERTY(Marker3D*, Marker, nullptr, Marker3D*, Marker3D*);
};
