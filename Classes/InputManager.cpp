#include "InputManager.h"
#include "Key.h"
#include "Touch.h"

#define Key static_cast<int>(keyCode)

USING_NS_CC;
using KeyCode = EventKeyboard::KeyCode;
using MouseButton = EventMouse::MouseButton;

InputManager* InputManager::_instance = nullptr;

InputManager & InputManager::getInstance(void)
{
	if (_instance == nullptr)
	{
		if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		{
			_instance = new KeyInput();
		}
		else if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		{
			_instance = new KeyInput();
			// instance touch
		}

	}
	return (*_instance);
}

InputManager * InputManager::GetPointer(void)
{
	if (_instance != nullptr)
	{
		_instance->removeFromParent();
		return _instance;
	}
	return nullptr;
}

void InputManager::Update(void)
{
	for (int i = 0; i < 256; i++)
	{
		_oldStates[i] = _keyStates[i];
	}
}

bool InputManager::GetKey(KeyCode keyCode) const
{
	return _keyStates[Key];
}

bool InputManager::GetKey(MouseButton button) const
{
	auto index = ENUM_TO_INT(KeyCode::KEY_PLAY) + ENUM_TO_INT(button) + 1;
	return _keyStates[index];
}

bool InputManager::GetKeyUp(KeyCode keyCode) const
{
	return !_keyStates[Key] && _oldStates[Key];
}

bool InputManager::GetKeyUp(MouseButton button) const
{
	auto index = ENUM_TO_INT(KeyCode::KEY_PLAY) + ENUM_TO_INT(button) + 1;
	return !_keyStates[index] && _oldStates[index];
}

bool InputManager::GetKeyDown(KeyCode keyCode) const
{
	return _keyStates[Key] && !_oldStates[Key];
}

bool InputManager::GetKeyDown(MouseButton button) const
{
	auto index = ENUM_TO_INT(KeyCode::KEY_PLAY) + ENUM_TO_INT(button) + 1;
	return _keyStates[index] && !_oldStates[index];
}

cocos2d::Vec2 InputManager::GetCursorPos(void) const
{
	return _cursorPos;
}

InputManager::InputManager()
{
	// key init
	for(auto & keyState : _keyStates)
	{
		keyState = false;
	}

	for (auto & oldState : _oldStates)
	{
		oldState = false;
	}

	// mouse init
	_cursorPos = cocos2d::Vec2::ZERO;
}

InputManager::~InputManager()
{
}
