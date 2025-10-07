#pragma once
#include "godot_cpp/classes/node.hpp"

class GameInput : public godot::Node
{
    GDCLASS(GameInput, Node)
    
public:
    bool Initialize();
    
protected:
    static void _bind_methods();
};
