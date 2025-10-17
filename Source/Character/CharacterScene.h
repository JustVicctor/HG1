#pragma once

#include "godot_cpp/classes/character_body3d.hpp"

#include "StateMachine/CharacterStateMachine.h"

class CharacterStateMachine;
using namespace godot;

class CharacterScene : public CharacterBody3D
{
    GDCLASS(CharacterScene, CharacterBody3D)
    
public:
    virtual bool Initialize();
    
protected:
    static void _bind_methods();
};
