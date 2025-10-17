#pragma once
#include "godot_cpp/classes/rigid_body3d.hpp"

using namespace godot;

class GrabbableNode : public RigidBody3D
{
    GDCLASS(GrabbableNode, RigidBody3D)

public:
    bool IsGrabbed() const;
    void SetIsGrabbed(const bool isGrabbed);
    
protected:
    bool m_IsGrabbed = false;
    
    static void _bind_methods();
};
