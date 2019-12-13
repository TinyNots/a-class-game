#include "Key.h"

USING_NS_CC;

KeyInput::KeyInput()
{
	using KeyCode = EventKeyboard::KeyCode;

	// keyboard input
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = [&](KeyCode keyCode, Event * event)
	{
		_keyStates[ENUM_TO_INT(keyCode)] = true;;
	};

	listener->onKeyReleased = [&](KeyCode keyCode, Event * evnet)
	{
		_keyStates[ENUM_TO_INT(keyCode)] = false;
	};

	// mouse input
	auto mouseListener = EventListenerMouse::create();

	mouseListener->onMouseDown = [&](EventMouse * mouse)
	{
		_keyStates[ENUM_TO_INT(KeyCode::KEY_PLAY) + ENUM_TO_INT(mouse->getMouseButton()) + 1] = true;
	};

	mouseListener->onMouseUp = [&](EventMouse * mouse)
	{
		_keyStates[ENUM_TO_INT(KeyCode::KEY_PLAY) + ENUM_TO_INT(mouse->getMouseButton()) + 1] = false;
	};
	
	mouseListener->onMouseMove = [&](EventMouse * mouse)
	{
		_cursorPos = Vec2(mouse->getCursorX(), mouse->getCursorY());
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
}

KeyInput::~KeyInput()
{
}
