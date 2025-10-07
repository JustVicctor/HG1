#pragma once
#include "Utils/Utils.h"
#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/packed_scene.hpp"

class Character;
class GameInput;
class Level;
class UserSettings;
class GameSettings;

class Game : public godot::Node3D
{
    GDCLASS(Game, Node3D)
    static Game* s_Singleton;

public:
    static Game* Get();
    static GameInput* GetGameInput();
    static godot::Ref<GameSettings>& GetGameSettings();
    static godot::Ref<UserSettings>& GetUserSettings();

    void _ready() override;

protected:
    bool InitCharacter();
    bool InitStartLevel();
    bool InitGameInput();
    
    GameInput* m_GameInput;
	godot::Ref<GameSettings> m_GameSettings;
	godot::Ref<UserSettings> m_UserSettings;

    Character* m_Character = nullptr;
	Level* m_StartLevel = nullptr;
    
    static void _bind_methods();

    HG_ADD_PROPERTY(godot::Ref<godot::PackedScene>, StartLevelScene, nullptr, godot::Ref<godot::PackedScene>, const godot::Ref<godot::PackedScene>&);
    HG_ADD_PROPERTY(godot::Ref<godot::PackedScene>, CharacterScene, nullptr, godot::Ref<godot::PackedScene>, const godot::Ref<godot::PackedScene>&);
};
