#pragma once
#include <godot_cpp/classes/static_body3d.hpp>

#include "IInteractable.h"

using namespace godot;
class CharacterScene;

class InteractableObject : public StaticBody3D, public IInteractable
{
    GDCLASS(InteractableObject, StaticBody3D)

public:
    virtual void Interact(CharacterScene* instigator) override;

protected:
    static void _bind_methods();
};
