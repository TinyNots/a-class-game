#pragma once
#include "cocos2d.h"
#include "Key.h"
#include "Touch.h"
#include "Controller.h"

class InputManager : public cocos2d::Node
{
public:
	static InputManager& Instace(void)
	{
		if (_instance == nullptr)
		{
			_instance = new InputManager();
			_instance->Init();
		}
		return (*_instance);
	}
	bool Init(void);
private:
	bool _keyStates[256];
	static InputManager* _instance;
};