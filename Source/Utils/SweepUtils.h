#pragma once
#include "godot_cpp/classes/physics_direct_space_state3d.hpp"
#include "godot_cpp/classes/physics_ray_query_parameters3d.hpp"
#include "godot_cpp/classes/world3d.hpp"

namespace godot
{
    struct HitResult
    {
        Object* HitObject = nullptr;
    };
    
    class SweepUtils
    {
    public:
        static bool Sweep(
            const Ref<World3D>& world,
            const Transform3D& transform,
            const float distance,
            const RID& excluded,
            HitResult& hitResult);

        static bool Sweep(
            const Ref<PhysicsRayQueryParameters3D>& query,
            const Ref<World3D>& world,
            HitResult& hitResult);
    };
}
