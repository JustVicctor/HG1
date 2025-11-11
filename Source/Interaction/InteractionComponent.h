#pragma once
#include "Grabbable.h"
#include "Utils/Utils.h"

#include "godot_cpp/classes/input_event.hpp"

class GameInput;
class Interactable;

namespace godot
{
class RayCast3D;
class Marker3D;
}

using namespace godot;

class InteractionComponent : public Node
{
	GDCLASS(InteractionComponent, Node)

public:
	virtual void _ready() override;
	virtual void _process(double delta) override;

protected:
	GameInput* m_GameInput = nullptr;
	Interactable* m_CurrentInteractable = nullptr;
	
	static void _bind_methods();
	HG_ADD_PROPERTY(Node3D*, Instigator, nullptr, Node3D*, Node3D*);
	HG_ADD_PROPERTY(RayCast3D*, RayCast, nullptr, RayCast3D*, RayCast3D*);
	HG_ADD_PROPERTY(Marker3D*, Marker, nullptr, Marker3D*, Marker3D*);
};
