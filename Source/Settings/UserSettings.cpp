#include "UserSettings.h"

#include "godot_cpp/classes/resource_loader.hpp"
#include "godot_cpp/classes/resource_saver.hpp"

constexpr char* USER_SETTINGS_PATH = "user://user_settings.res";
constexpr char* USER_SETTINGS_HINT = "UserSettings";

void UserSettings::Save()
{
	const auto saver = godot::ResourceSaver::get_singleton();
	auto error = saver->save(this, USER_SETTINGS_PATH);
}

godot::Ref<UserSettings> UserSettings::LoadOrCreate()
{
	godot::Ref<UserSettings> userSettings;

	const auto loader = godot::ResourceLoader::get_singleton();
	if (loader->exists(USER_SETTINGS_PATH, USER_SETTINGS_HINT))
		userSettings = loader->load(USER_SETTINGS_PATH, USER_SETTINGS_HINT, godot::ResourceLoader::CACHE_MODE_REPLACE);

	if (userSettings.is_null())
		userSettings.instantiate();

	return userSettings;
}

void UserSettings::_bind_methods()
{
	HG_BIND_PROPERTY_FLOAT(UserSettings, "HorizontalMouseSensitivity", SetHorizontalMouseSensitivity, GetHorizontalMouseSensitivity);
	HG_BIND_PROPERTY_FLOAT(UserSettings, "VerticalMouseSensitivity", SetVerticalMouseSensitivity, GetVerticalMouseSensitivity);
}
