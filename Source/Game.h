#pragma once
#include "Utils/Utils.h"
#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/packed_scene.hpp"

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

    virtual void _ready() override;

protected:
    bool InitGameInput();
    bool InitStartLevel();
    
    GameInput* m_GameInput;
	godot::Ref<GameSettings> m_GameSettings;
	godot::Ref<UserSettings> m_UserSettings;
    
	Level* m_StartLevel = nullptr;
    
    static void _bind_methods();

    HG_ADD_PROPERTY(godot::Ref<godot::PackedScene>, StartLevelScene, nullptr, godot::Ref<godot::PackedScene>, const godot::Ref<godot::PackedScene>&);
};
