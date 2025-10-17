#include "SweepUtils.h"

#include "godot_cpp/classes/shape3d.hpp"
#include "godot_cpp/classes/world3d.hpp"

using namespace godot;

bool SweepUtils::Sweep(const Ref<World3D>& world, const Transform3D& transform, const float distance, const RID& excluded, HitResult& hitResult)
{
    const Ref<PhysicsRayQueryParameters3D> query = PhysicsRayQueryParameters3D::create(
        transform.get_origin(),
        transform.basis.get_column(2) * -distance
    );
    print_line(transform.get_origin());
    print_line(transform.basis.get_column(2) * -distance);
    query->set_collide_with_areas(false);
    query->set_collide_with_bodies(true);
    query->set_exclude({excluded});
    query->set_hit_back_faces(true);
    query->set_hit_from_inside(true);

    PhysicsDirectSpaceState3D* space = world->get_direct_space_state();
    const Dictionary result = space->intersect_ray(query);
    if (result.size() > 0)
    {
        hitResult.HitObject = result["collider"];
        return true;
    }
    return false;
}

bool SweepUtils::Sweep(const Ref<PhysicsRayQueryParameters3D>& query, const Ref<World3D>& world, HitResult& hitResult)
{
    PhysicsDirectSpaceState3D* space = world->get_direct_space_state();
    const Dictionary result = space->intersect_ray(query);
    if (result.size() > 0)
    {
        hitResult.HitObject = result["collider"];
        return true;
    }
    return false;
}
