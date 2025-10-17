#include "Character.h"
#include "Character/CharacterScene.h"

bool Character::Initialize(const Ref<CharacterResource>& resource, CharacterScene* scene)
{
    return true;
}

void Character::Input(const Ref<InputEvent>& inputEvent)
{
}

void Input(const Ref<InputEvent>& inputEvent)
{
}

void Character::Process(const double delta)
{
}

CharacterResource* Character::GetResource()
{
    return nullptr;
}

CharacterScene* Character::GetScene() const
{
    return nullptr;
}

void Character::_bind_methods()
{
}
