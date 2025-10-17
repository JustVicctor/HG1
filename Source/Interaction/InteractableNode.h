#pragma once
#include <godot_cpp/classes/static_body3d.hpp>

using namespace godot;
class CharacterScene;

class InteractableNode : public StaticBody3D
{
    GDCLASS(InteractableNode, StaticBody3D)

public:
    virtual void Interact(CharacterScene* instigator);

protected:
    static void _bind_methods();
};
