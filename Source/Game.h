#pragma once
#include "Utils/Utils.h"

#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/packed_scene.hpp"

#include "Character/Character.h"

class Character;
class CharacterResource;
class CharacterScene;
class GameInput;
class Level;
class UserSettings;
class GameSettings;

using namespace godot;

class Game : public Node3D
{
    GDCLASS(Game, Node3D)
    static Game* s_Singleton;

public:
    static Game* Get();
    static GameInput* GetGameInput();
    static Ref<GameSettings>& GetGameSettings();
    static Ref<UserSettings>& GetUserSettings();

    void _ready() override;
    void _input(const Ref<InputEvent>& p_event) override;
    void _process(double p_delta) override;
    void _physics_process(double p_delta) override;

protected:
    bool InitCharacter();
    bool InitStartLevel();
    bool InitGameInput();
    
    GameInput* m_GameInput;
	Ref<GameSettings> m_GameSettings;
	Ref<UserSettings> m_UserSettings;

    Ref<Character> m_Character;
	Level* m_StartLevel = nullptr;
    
    static void _bind_methods();

    HG_ADD_PROPERTY(Ref<CharacterResource>, CharacterResource, nullptr, Ref<CharacterResource>, const Ref<CharacterResource>&);
    HG_ADD_PROPERTY(Ref<PackedScene>, StartLevelScene, nullptr, Ref<PackedScene>, const Ref<PackedScene>&);
};
