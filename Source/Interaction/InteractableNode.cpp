#include "InteractableNode.h"
#include "godot_cpp/classes/rendering_server.hpp"

using namespace godot;

void InteractableNode::Interact(CharacterScene* instigator)
{
    print_line("InteractSample");
}

void InteractableNode::_bind_methods()
{
}
