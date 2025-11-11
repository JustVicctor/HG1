#pragma once
#include "Character/Character.h"

#include "godot_cpp/classes/physics_ray_query_parameters3d.hpp"

namespace godot
{
class PhysicsRayQueryParameters3D;
}

class PlayerScene;
class PlayerResource;

class Player : public Character
{
	GDCLASS(Player, Character)

public:
	virtual bool Initialize(const Ref<CharacterResource>& resource, CharacterScene* scene) override;

	virtual void Input(const Ref<InputEvent>& inputEvent) override;
	virtual void Process(const double delta) override;
	virtual void PhysicsProcess(const float delta) override;

	virtual CharacterResource* GetResource() override;
	virtual CharacterScene* GetScene() const override;

protected:
	void ProcessMouse() const;

	Ref<PlayerResource> m_Resource = nullptr;
	PlayerScene* m_Scene = nullptr;

	static void _bind_methods();
};
