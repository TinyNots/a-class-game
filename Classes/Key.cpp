#include "Key.h"

USING_NS_CC;

KeyInput::KeyInput()
{
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event * event)
	{
		_keyStates[static_cast<int>(keyCode)] = true;
	};

	listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event * evnet)
	{
		_keyStates[static_cast<int>(keyCode)] = false;
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

KeyInput::~KeyInput()
{
}
