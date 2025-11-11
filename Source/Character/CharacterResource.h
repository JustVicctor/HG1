#pragma once

#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/resource.hpp"

#include "Utils/Utils.h"

class CharacterScene;
class Character;

using namespace godot;

class CharacterResource : public Resource
{
    GDCLASS(CharacterResource, Resource)
    
public:
    static Ref<Character> CreateCharacter(const Ref<CharacterResource>& resource);
    
protected:
    virtual Ref<Character> CreateCharacter();
    CharacterScene* CreateCharacterScene() const;
    
    static void _bind_methods();
    
    HG_ADD_PROPERTY(Ref<PackedScene>, CharacterScene, nullptr, Ref<PackedScene>, const Ref<PackedScene>&);
	HG_ADD_PROPERTY(float, MovementSpeed, 3.f, float, const float);
	HG_ADD_PROPERTY(float, Acceleration, 10.f, float, const float);
	HG_ADD_PROPERTY(float, Deceleration, 30.f, float, const float);
};
