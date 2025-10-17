#pragma once

class CharacterScene;

class IInteractable
{
public:
    virtual ~IInteractable() = default;
    virtual void Interact(CharacterScene* instigator) = 0;
};
