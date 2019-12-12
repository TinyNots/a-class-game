#include "InputManager.h"
#include "Key.h"
#include "Touch.h"

#define key static_cast<int>(keyCode)

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
		return _instance;
	}
	return nullptr;
}

void InputManager::update(float dt)
{
	for (int i = 0; i < 256; i++)
	{
		_oldStates[i] = _keyStates[i];
	}
}

bool InputManager::Getkey(cocos2d::EventKeyboard::KeyCode keyCode) const
{
	return _keyStates[key];
}

bool InputManager::GetkeyUp(cocos2d::EventKeyboard::KeyCode keyCode) const
{
	return !!_keyStates[key] && _oldStates[key];
}

bool InputManager::GetKeyDown(cocos2d::EventKeyboard::KeyCode keyCode) const
{
	return _keyStates[key] && !_oldStates[key];
}

InputManager::InputManager()
{
	for (auto & keyState : _keyStates)
	{
		keyState = false;
	}

	this->scheduleUpdate();
}

InputManager::~InputManager()
{
}
