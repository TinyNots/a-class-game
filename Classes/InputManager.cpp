#include "InputManager.h"

USING_NS_CC;

InputManager* InputManager::_instance = nullptr;

bool InputManager::Init(void)
{
	for (auto & keyState : _keyStates)
	{
		keyState = false;
	}

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event * event)
	{
		_keyStates[static_cast<int>(keyCode)] = true;
		log("Key %d is pressed.", keyCode);
	};

	listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event * evnet)
	{
		_keyStates[static_cast<int>(keyCode)] = false;
		log("Key %d is released.", keyCode);
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}
