#include "GameInput.h"

#include "Game.h"

#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/input_event_mouse_motion.hpp"

#include "Settings/GameSettings.h"
#include "Settings/UserSettings.h"

bool GameInput::Initialize()
{
    const auto input = Input::get_singleton();
    input->set_mouse_mode(Input::MOUSE_MODE_CAPTURED);

    userSettings = Game::GetUserSettings();
    gameSettings = Game::GetGameSettings();

    return true;
}

void GameInput::_process(double delta)
{
    const auto input = Input::get_singleton();

    m_MoveVector = input->get_vector(
        "move_left",
        "move_right",
        "move_backward",
        "move_forward");

    m_MouseOffset.x -= m_MouseRelative.y * userSettings->GetVerticalMouseSensitivity() * delta;
    m_MouseOffset.x = Math::clamp(m_MouseOffset.x, gameSettings->GetMinPitch(), gameSettings->GetMaxPitch());
    m_MouseOffset.y -= m_MouseRelative.x * userSettings->GetHorizontalMouseSensitivity() * delta;;

    m_MouseRelative *= 0;

    m_IsPrimaryPressed = input->is_action_just_pressed("action_primary");
    m_IsPrimaryReleased = input->is_action_just_released("action_primary");
    m_IsSecondaryPressed = input->is_action_just_pressed("action_secondary");
    m_IsInteractPressed = input->is_action_just_pressed("action_interact");
}

void GameInput::_physics_process(double delta)
{
}

void GameInput::_input(const Ref<InputEvent>& inputEvent)
{
}

void GameInput::_unhandled_input(const Ref<InputEvent>& inputEvent)
{
    const auto input = Input::get_singleton();

    const Ref<InputEventMouseMotion> mouseMotion = inputEvent;
    if (mouseMotion.is_valid() && (input->get_mouse_mode() == Input::MOUSE_MODE_CAPTURED))
        m_MouseRelative = mouseMotion->get_relative();
}

Vector2 GameInput::GetMoveVector() const
{
    return m_MoveVector;
}

Vector2 GameInput::GetMouseOffset() const
{
    return m_MouseOffset;
}

Vector2 GameInput::GetMouseRelative() const
{
    return m_MouseRelative;
}

bool GameInput::IsPrimaryPressed() const
{
    return m_IsPrimaryPressed;
}

bool GameInput::IsPrimaryReleased() const
{
    return m_IsPrimaryReleased;
}

bool GameInput::IsSecondaryPressed() const
{
    return m_IsSecondaryPressed;
}

bool GameInput::IsInteractPressed() const
{
    return m_IsInteractPressed;
}

void GameInput::_bind_methods()
{
}
