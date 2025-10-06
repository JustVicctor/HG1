#include "GameSettings.h"

#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/classes/resource_saver.hpp"

constexpr char* GAME_SETTINGS_PATH = "user://game_settings.res";
constexpr char* GAME_SETTINGS_HINT = "GameSettings";

void GameSettings::Save()
{
	const auto saver = godot::ResourceSaver::get_singleton();
	saver->save(this, GAME_SETTINGS_PATH);
}

godot::Ref<GameSettings> GameSettings::LoadOrCreate()
{
	godot::Ref<GameSettings> gameSettings;

	const auto loader = godot::ResourceLoader::get_singleton();
	if (loader->exists(GAME_SETTINGS_PATH, GAME_SETTINGS_HINT))
		gameSettings = loader->load(GAME_SETTINGS_PATH, GAME_SETTINGS_HINT, godot::ResourceLoader::CACHE_MODE_REPLACE);

	if (gameSettings.is_null())
		gameSettings.instantiate();
		
	return gameSettings;
}

void GameSettings::_bind_methods()
{
}
