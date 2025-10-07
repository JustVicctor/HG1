#pragma once
#include "godot_cpp/classes/character_body3d.hpp"
#include "Utils/Utils.h"

#include "CharacterResource.h"
#include "StateMachine/CharacterStateMachine.h"

class CharacterStateMachine;
using namespace godot;

class Character : public CharacterBody3D
{
    GDCLASS(Character, CharacterBody3D)
    
public:
    bool Initialize();
    
protected:
    static void _bind_methods();

    HG_ADD_PROPERTY(godot::Ref<CharacterResource>, CharacterResource, nullptr, godot::Ref<CharacterResource>, const godot::Ref<CharacterResource>&);
    HG_ADD_PROPERTY(CharacterStateMachine*, CharacterStateMachine, nullptr, CharacterStateMachine*, CharacterStateMachine*);
};
