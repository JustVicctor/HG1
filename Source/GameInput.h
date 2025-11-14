#pragma once
#include "godot_cpp/classes/node.hpp"

class GameSettings;
class UserSettings;
using namespace godot;

class GameInput : public Node
{
    GDCLASS(GameInput, Node)
    
public:
    bool Initialize();
	
	void _process(double delta) override;
	void _physics_process(double delta) override;
	void _input(const Ref<InputEvent>& inputEvent) override;
	void _unhandled_input(const Ref<InputEvent>& inputEvent) override;
	
	Vector2 GetMoveVector() const;
	Vector2 GetMouseOffset() const;
	Vector2 GetMouseRelative() const;

	bool IsPrimaryPressed() const;
	bool IsPrimaryReleased() const;
	bool IsSecondaryPressed() const;
	bool IsSecondaryReleased() const;
	bool IsInteractPressed() const;

protected:
	Ref<UserSettings> userSettings;
	Ref<GameSettings> gameSettings;
	
	Vector2 m_MoveVector;
	Vector2 m_MouseRelative;
	Vector2 m_MouseOffset;

	bool m_IsPrimaryPressed = false;
	bool m_IsPrimaryReleased = false;
	bool m_IsSecondaryPressed = false;
	bool m_IsSecondaryReleased = false;
	bool m_IsInteractPressed = false;

	static void _bind_methods();
};
