#include "Game.h"

#include "godot_cpp/classes/input.hpp"

#include "GameInput.h"
#include "Levels/Level.h"
#include "Settings/GameSettings.h"
#include "Settings/UserSettings.h"
#include "Character/CharacterResource.h"
#include "Character/CharacterScene.h"

Game* Game::s_Singleton = nullptr;

Game* Game::Get()
{
    return s_Singleton;
}

GameInput* Game::GetGameInput()
{
    return s_Singleton->m_GameInput;
}

Ref<GameSettings>& Game::GetGameSettings()
{
    return s_Singleton->m_GameSettings;
}

Ref<UserSettings>& Game::GetUserSettings()
{
    return s_Singleton->m_UserSettings;
}

void Game::_ready()
{
    HG_ERR_FAIL_COND_MSG(s_Singleton != nullptr, "The game has already been initialized!");

    s_Singleton = this;
    
	m_GameSettings = GameSettings::LoadOrCreate();
	m_UserSettings = UserSettings::LoadOrCreate();

    bool isReady = true;
    isReady &= InitCharacter();
    isReady &= InitStartLevel();
    // Must be last to proper input handle
    isReady &= InitGameInput();
    
    if (!isReady)
    {
        // Disable all process
		set_process_mode(PROCESS_MODE_DISABLED);
		return;
    }

    print_line("Game is Ready");
}

void Game::_input(const Ref<InputEvent>& p_event)
{
    m_Character->Input(p_event);
}

void Game::_process(double delta)
{
    m_Character->Process(delta);
}

void Game::_physics_process(double delta)
{
    m_Character->PhysicsProcess(delta);
}

bool Game::InitCharacter()
{
    HG_ERR_FAIL_COND_V_MSG(m_CharacterResource.is_null(), false, "Character Resource is invalid!");
    m_Character = CharacterResource::CreateCharacter(m_CharacterResource);
    HG_ERR_FAIL_COND_V_MSG(m_Character.is_null(), false, "Character failed to instantiate!");
    add_child(m_Character->GetScene());
    return true;
}

bool Game::InitStartLevel()
{
    HG_ERR_FAIL_COND_V_MSG(m_StartLevelScene.is_null(), false, "Start Level Scene is invalid!");
    m_StartLevel = cast_to<Level>(m_StartLevelScene->instantiate());
    HG_ERR_FAIL_COND_V_MSG(m_StartLevel == nullptr, false, "Start Level failed to instantiate!");
    add_child(m_StartLevel);
    return m_StartLevel->Initialize();
}

bool Game::InitGameInput()
{
    m_GameInput = memnew(GameInput);
    m_GameInput->set_name("GameInput");
    add_child(m_GameInput);
    return m_GameInput->Initialize();
}

void Game::_bind_methods()
{
    HG_BIND_PROPERTY_RESOURCE(Game, "CharacterResource", CharacterResource, SetCharacterResource, GetCharacterResource);
    HG_BIND_PROPERTY_PACKED(Game, "StartLevelScene", SetStartLevelScene, GetStartLevelScene);
}
