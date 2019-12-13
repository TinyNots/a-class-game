#pragma once
#include "cocos2d.h"

#define GET_KEY(keyCode)		InputManager::getInstance().GetKey(keyCode)
#define GET_KEY_UP(keyCode)		InputManager::getInstance().GetKeyUp(keyCode)
#define GET_KEY_DOWN(keyCode)	InputManager::getInstance().GetKeyDown(keyCode)
#define GET_CURSOR_POS			InputManager::getInstance().GetCursorPos

#define ENUM_TO_INT(value) static_cast<int>(value)

class InputManager : public cocos2d::Node
{
public:
	static InputManager& getInstance(void);
	InputManager * GetPointer(void);
	void Update(void);
	bool GetKey(cocos2d::EventKeyboard::KeyCode keyCode) const;
	bool GetKeyUp(cocos2d::EventKeyboard::KeyCode keyCode) const;
	bool GetKeyDown(cocos2d::EventKeyboard::KeyCode keyCode) const;
	bool GetKey(cocos2d::EventMouse::MouseButton button) const;
	bool GetKeyUp(cocos2d::EventMouse::MouseButton button) const;
	bool GetKeyDown(cocos2d::EventMouse::MouseButton button) const;
	cocos2d::Vec2 GetCursorPos(void) const;
private:
protected:
	InputManager();
	~InputManager();
	bool _keyStates[256];
	bool _oldStates[256];
	cocos2d::Vec2 _cursorPos;
	static InputManager* _instance;
};