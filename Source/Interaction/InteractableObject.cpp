#include "InteractableObject.h"
#include "godot_cpp/classes/rendering_server.hpp"

using namespace godot;

void InteractableObject::Interact(CharacterScene* instigator)
{
    print_line("InteractSample");
}

void InteractableObject::_bind_methods()
{
}
