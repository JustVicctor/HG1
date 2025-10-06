#pragma once
#include "godot_cpp/classes/node3d.hpp"

class Level : public godot::Node3D
{
    GDCLASS(Level, Node3D)
public:
protected:
    static void _bind_methods();
};
