#pragma once
#include "CharacterResource.h"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/input_event.hpp"

namespace godot
{
    class InputEvent;
}

class CharacterScene;
using namespace godot;

class Character : public RefCounted
{
    GDCLASS(Character, RefCounted)
    
public:
    virtual bool Initialize(const Ref<CharacterResource>& resource, CharacterScene* scene);

	virtual void Input(const Ref<InputEvent>& inputEvent);
    virtual void Process(const double delta);
    virtual void PhysicsProcess(const float delta);
    
    virtual CharacterResource* GetResource();
    virtual CharacterScene* GetScene() const;
    
protected:
    static void _bind_methods();
};
